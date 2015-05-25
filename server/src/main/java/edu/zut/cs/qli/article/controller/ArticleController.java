package edu.zut.cs.qli.article.controller;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.catalog.service.CatalogManager;
import edu.zut.cs.qli.user.domain.User;
import edu.zut.cs.qli.utils.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Controller
@RequestMapping("/article")
@SessionAttributes("user")
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
    public String main() {
        return "article/main";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/list")
    public String list(Model model, Integer pageIndex) {
        if (null == pageIndex) {
            pageIndex = 1;
        }
        Page<Article> page = articleManager.findAll(new MyPageable(pageIndex - 1, 2));
        model.addAttribute("page", page);
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
                         @RequestParam String type,
                         @RequestParam String content,
                         Model model) {
        Article article = (0 == id) ? new Article() : articleManager.findById(id);
        article.setUser((User) model.asMap().get("user"));
        article.setTitle(title);
        article.setType(type);
        article.setName(FileUtil.createUniqueName());

        articleManager.doSave(article, content);
        return Constants.MESSAGE_SUCCESS;
    }

    @RequestMapping(method = RequestMethod.POST, value = "/delete")
    @ResponseBody
    public String doDelete(@RequestParam long id) {
        // FIXME 删除今后需要改为设置删除标志，但这样的话也要将list函数排除删除标志，这个还需要考虑下
        articleManager.delete(id);
        return Constants.MESSAGE_SUCCESS;
    }

    @RequestMapping(method = RequestMethod.POST, value = "/deleteBatch")
    @ResponseBody
    public String deleteBatch(@RequestParam List<Long> ids) {
        // FIXME 删除今后需要改为设置删除标志，但这样的话也要将list函数排除删除标志，这个还需要考虑下
        for (Long id : ids) {
            doDelete(id);
        }
        return Constants.MESSAGE_SUCCESS;
    }


    // FIXME
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

    @RequestMapping(method = RequestMethod.POST, value = "/fileUp")
    public String fileUp(@RequestParam MultipartFile file, Model model) {
        String fileName = file.getOriginalFilename();
        if (!(fileName.endsWith(".ppt") || fileName.endsWith(".pptx"))) {
            model.addAttribute("message", Constants.MESSAGE_WARN);
            return edit(0L, model);
        }
        try {
            // FIXME 我不知道为什么要分类，而且应该是系统编程啊，这要弄的话文件上传也得分类，弄这干啥都
            doSave(0L, fileName, "NONE", FileParseUtil.getPPTContent(file.getInputStream()), model);
        } catch (Exception e) {
            model.addAttribute("message", Constants.MESSAGE_ERROR);
        }
        model.addAttribute("message", Constants.MESSAGE_SUCCESS);
        return list(model, 1);
    }

    @RequestMapping(method = RequestMethod.GET, value = "/hot", produces = "application/json")
    @ResponseBody
    public List<Article> getHotList() {
        return this.articleManager.findHot();
    }

    @RequestMapping(method = RequestMethod.GET, value = "/lasted", produces = "application/json")
    @ResponseBody
    public List<Article> getLastedList() {
        return this.articleManager.findLasted();
    }

    @RequestMapping(method = RequestMethod.GET, value = "/file", produces = "application/json")
    @ResponseBody
    public List<Article> getFileList() {
        return this.articleManager.findFileList();
    }

    @RequestMapping(method = RequestMethod.GET, value = "/web", produces = "application/json")
    @ResponseBody
    public List<Article> getWebList() {
        return this.articleManager.findWebList();
    }
}
