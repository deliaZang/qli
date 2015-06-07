package edu.zut.cs.qli.note.controller;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.note.domain.Note;
import edu.zut.cs.qli.note.service.NoteManager;
import edu.zut.cs.qli.user.domain.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
@Controller
@RequestMapping("/note")
@SessionAttributes("user")
public class NoteController extends BaseEntityController<Note, Long, NoteManager> {

    NoteManager noteManager;

    @Autowired
    public void setNoteManager(NoteManager noteManager) {
        this.noteManager = noteManager;
        this.manager = noteManager;
    }

    @Autowired
    ArticleManager articleManager;


    /**
     * 添加笔记
     * @param id
     * @param title
     * @param content
     * @param request
     * @return
     */
    @RequestMapping(method = RequestMethod.POST, value = "/save")
    @ResponseBody
    public String doSave(@RequestParam Long id, @RequestParam String title, @RequestParam String content, HttpServletRequest request) {
        User user = (User) request.getSession().getAttribute("user");
        if(null == user){
            return "user/login";
        }
        Note note = new Note();
        note.setUser(user);
        Article article = this.articleManager.findById(id);
        note.setArticle(article);
        note.setTitle(title);
        note.setContent(content);
        this.noteManager.save(note);
        return "SUCCESS";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/list")
    public String list(Model model, HttpServletRequest request) {
        User user = (User) request.getSession().getAttribute("user");
        if(null == user){
            return "user/login";
        }
        model.addAttribute("articleList",articleManager.findByUser(user.getId()));
        model.addAttribute("noteList", this.noteManager.findByUser(user.getId()));
        return "note/list";
    }

    /**
     * 根据Article的ID查询
     *
     * @param id
     * @return
     */
    @RequestMapping(method = RequestMethod.POST, value = "/findByArticle")
    @ResponseBody
    public List<Note> findByArticle(long id) {

        return this.noteManager.findByArticle(id);
    }

}
