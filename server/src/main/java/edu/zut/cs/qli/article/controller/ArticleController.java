package edu.zut.cs.qli.article.controller;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.catalog.service.CatalogManager;
import edu.zut.cs.qli.utils.FileParseUtil;
import edu.zut.cs.qli.utils.FileUtil;
import edu.zut.cs.qli.utils.Uploader;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Controller
@RequestMapping("/article")
public class ArticleController extends
        BaseEntityController<Article, Long, ArticleManager> {

    ArticleManager articleManager;

    @Autowired
    public void setUserManager(ArticleManager articleManager) {
        this.articleManager = articleManager;
        this.manager = this.articleManager;
    }

    @Autowired
    CatalogManager catalogManager;

    @RequestMapping(method = RequestMethod.GET, value = "/edit")
    public String edit(@RequestParam(required = false, defaultValue = "0") Long id, Model model) {
        if (0 != id) {
            Article article = articleManager.findById(id);
            article.setContent(FileUtil.getHtml(article.getName()));
            model.addAttribute("article", article);
        }
        return "article/edit";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/main")
    public String main(Model model) {
        model.addAttribute("articles", articleManager.findAll());
        return "article/main";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/list")
    public String list(Model model) {
        model.addAttribute("articles", articleManager.findAll());
        return "article/list";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/show")
    public String show(@RequestParam long id, Model model) {
        Article article = articleManager.findDetailById(id);
        int visits = article.getVisits().intValue();
        article.setVisits(++visits);
        articleManager.save(article);
        article.setContent(FileUtil.getHtml(article.getName()));
        model.addAttribute("article", article);
        return "article/show";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/do")
    @ResponseBody
    public List<Article> doList() {
        return articleManager.findAll();
    }

    @RequestMapping(method = RequestMethod.POST, value = "/do")
    @ResponseBody
    public String doSave(@RequestParam(required = false, defaultValue = "0") Long id,
                         @RequestParam String title,
                         @RequestParam String content) {
        Article article = (0 == id) ? new Article() : articleManager.findById(id);
        article.setTitle(title);
        article.setName(FileUtil.createUniqueName());

        articleManager.doSave(article, content);
        return "保存成功！";
    }

    @RequestMapping(method = RequestMethod.DELETE, value = "/delete")
    @ResponseBody
    public String doDelete(@RequestParam long id) {
        // FIXME 删除今后需要改为设置删除标志，但这样的话也要将list函数排除删除标志，这个还需要考虑下
        articleManager.delete(id);
        return "删除成功！";
    }

    @RequestMapping(method = RequestMethod.POST, value = "/imageUp")
    public void imageUp(HttpServletRequest request, HttpServletResponse response) throws Exception {
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        Uploader up = new Uploader(request);
        up.setSavePath("upload");
        String[] fileType = {".gif", ".png", ".jpg", ".jpeg", ".bmp"};
        up.setAllowFiles(fileType);
        up.setMaxSize(10000); //单位KB
        up.upload();

        String callback = request.getParameter("callback");
        String result = "{\"name\":\"" + up.getFileName() + "\", \"originalName\": \"" + up.getOriginalName() + "\", \"size\": " + up.getSize() + ", \"state\": \"" + up.getState() + "\", \"type\": \"" + up.getType() + "\", \"url\": \"" + up.getUrl() + "\"}";
        result = result.replaceAll("\\\\", "\\\\");
        if (callback == null) {
            response.getWriter().print(result);
        } else {
            response.getWriter().print("<script>" + callback + "(" + result + ")</script>");
        }
    }

    // FIXME 没有添加异常处理，其实只用返回前端说明上传状态就可以了
    @RequestMapping(method = RequestMethod.POST, value = "/fileUp")
    public String fileUp(@RequestParam MultipartFile file, Model model){
        String fileName = file.getOriginalFilename();
        if(!(fileName.endsWith(".ppt") || fileName.endsWith(".pptx"))){
            model.addAttribute("message", "暂只支持ppt格式！");
            return edit(0L, model);
        }
        try {
            doSave(0L, fileName, FileParseUtil.getPPTContent(file.getInputStream()));
        }catch (Exception e){
            model.addAttribute("message", "上传出错！");
        }
        model.addAttribute("message", "上传成功！");
        return list(model);
    }

    @RequestMapping(method = RequestMethod.GET, value = "/hot", produces = "application/json")
    @ResponseBody
    public List<Article> getHotList() {
        return this.articleManager.findHot();
    }

    @RequestMapping(method = RequestMethod.GET, value = "/lasted", produces = "application/json")
    @ResponseBody
    public List<Article> getLastedList() {
        return this.articleManager.findHot();
    }
}
