package edu.zut.cs.qli.article.controller;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.utils.Uploader;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
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

    @RequestMapping(method = RequestMethod.GET, value = "/edit")
    public String edit(Model model) {
        return "article/edit";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/update")
    public String update(@RequestParam Long id, Model model) {
        model.addAttribute("article", articleManager.findById(id));
        return "article/edit";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/list")
    public String list(Model model) {
        model.addAttribute("articles", articleManager.findAll());
        return "article/list";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/do")
    public
    @ResponseBody
    List<Article> doList() {
        return articleManager.findAll();
    }

    @RequestMapping(method = RequestMethod.POST, value = "/do")
    public void doSave(@RequestParam(required = false, defaultValue = "0") Long id,
                       @RequestParam String title,
                       @RequestParam String content) {
        Article a = (0 == id) ? new Article() : articleManager.findById(id);
        a.setTitle(title);
        a.setContent(content);

        articleManager.save(a);
    }

    @RequestMapping(method = RequestMethod.DELETE, value = "/do")
    public void doDelete(@RequestParam long id) {
        articleManager.delete(id);
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
}
