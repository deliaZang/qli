package edu.zut.cs.qli.comment.dao;

import edu.zut.cs.qli.base.dao.BaseDao;
import edu.zut.cs.qli.comment.domain.Comment;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
public interface CommentDao extends BaseDao<Comment, Long> {
    /**
     * 根据article的Id查询
     * @param id
     * @return
     */
    @Query(value = "select c from Comment c where c.article.id = :id")
    public List<Comment> findByArticle(@Param("id")long id);

    /**
     * 根据用户查询
     * @param id
     * @return
     */
    @Query(value = "select c from Comment c where c.user.id = :id")
    public List<Comment> findByUser(@Param("id")long id);
}