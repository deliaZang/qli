package edu.zut.cs.qli.note.dao;

import edu.zut.cs.qli.base.dao.BaseDao;
import edu.zut.cs.qli.note.domain.Note;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
public interface NoteDao extends BaseDao<Note, Long> {
    /**
     * 根据Article的ID查询
     * @param id
     * @return
     */
    @Query(value = "select n from Note n where n.article.id = :id")
    public List<Note> findByArticle(@Param("id") long id);

    @Query(value = "select n from Note n where n.user.id = :id")
    public List<Note> findByUser(@Param("id") long id);
}
