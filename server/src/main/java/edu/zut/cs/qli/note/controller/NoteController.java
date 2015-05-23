package edu.zut.cs.qli.note.controller;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.note.domain.Note;
import edu.zut.cs.qli.note.service.NoteManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;
import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
@Controller
@RequestMapping("/note")
public class NoteController extends BaseEntityController<Note, Long, NoteManager>{

    NoteManager noteManager;

    @Autowired
    public void setNoteManager(NoteManager noteManager) {
        this.noteManager = noteManager;
        this.manager = noteManager;
    }

    @Autowired
    ArticleManager articleManager ;



    @RequestMapping(method = RequestMethod.POST, value = "/save")
    @ResponseBody
    public String doSave(@RequestParam Long id,@RequestParam String content){
        Note note = new Note();
        Article article = this.articleManager.findById(id);
        note.setArticle(article);
        note.setContent(content);
        this.noteManager.save(note);
        return "SUCCESS";
    }
    @RequestMapping(method = RequestMethod.GET, value = "/list")
    public String list(Model model, HttpServletRequest request){
        model.addAttribute("note", this.noteManager.findAll());
        return "note/list";
    }

    /**
     * 根据Article的ID查询
     * @param id
     * @return
     */
    @RequestMapping(method = RequestMethod.POST, value = "/findByArticle")
    @ResponseBody
    public List<Note> findByArticle(long id){

        return this.noteManager.findByArticle(id);
    }
    @RequestMapping(method = RequestMethod.GET, value = "/add")
    public String add(Long articleId,Model model){
        model.addAttribute("articleId", articleId);
        return "note/addNote";
    }

}
