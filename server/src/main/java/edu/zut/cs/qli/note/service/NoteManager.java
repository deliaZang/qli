package edu.zut.cs.qli.note.service;

import edu.zut.cs.qli.base.service.BaseManager;
import edu.zut.cs.qli.note.domain.Note;

import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
public interface NoteManager extends BaseManager<Note, Long> {
    /**
     * 根据Article的ID查询
     * @param id
     * @return
     */
    public List<Note> findByArticle(long id);
}
