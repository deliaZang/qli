package edu.zut.cs.qli.note.service.impl;

import edu.zut.cs.qli.base.service.impl.BaseManagerImpl;
import edu.zut.cs.qli.note.dao.NoteDao;
import edu.zut.cs.qli.note.domain.Note;
import edu.zut.cs.qli.note.service.NoteManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
@Service("noteManager")
@Transactional
public class NoteManagerImpl extends BaseManagerImpl<Note, Long>
        implements NoteManager {
    NoteDao noteDao;

    @Autowired
    public void setNoteDao(NoteDao noteDao) {
        this.noteDao = noteDao;
        this.dao = this.noteDao;
    }

    /**
     * 根据Article的ID查询
     * @param id
     * @return
     */
    @Override
    public List<Note> findByArticle(long id) {
        return this.noteDao.findByArticle(id);
    }
}
