package edu.zut.cs.qli.comment.controller;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.comment.domain.Comment;
import edu.zut.cs.qli.comment.service.CommentManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
@Controller
@RequestMapping("/comment")
public class CommentController extends
        BaseEntityController<Comment, Long, CommentManager> {

    CommentManager commentManager;

    @Autowired
    public void setCommentManager(CommentManager commentManager) {
        this.commentManager = commentManager;
        this.manager = commentManager;
    }

    @Autowired
    ArticleManager articleManager ;

    /**
     * 保存Article
     * @param id
     * @param content
     * @return
     */
    @RequestMapping(method = RequestMethod.POST, value = "/save")
    @ResponseBody
    public String save(@RequestParam Long id, @RequestParam String content){
        Comment comment = new Comment();
        Article article = this.articleManager.findById(id);
        comment.setArticle(article);
        comment.setContent(content);
        this.commentManager.save(comment);
        return "SUCCESS";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/list")
    public String list(Model model){
        model.addAttribute("comment", this.commentManager.findAll());
        return "comment/list";
    }

    /**
     * 根据Article的ID查询评论
     * @param id
     * @return
     */
    @RequestMapping(method = RequestMethod.GET, value = "/findByArticle.json")
    @ResponseBody
    public List<Comment> findByArticle(@RequestParam long id){
        List<Comment> comments = this.commentManager.findByArticle(id);
        return comments;
    }
}
