package edu.zut.cs.qli.comment.service;

import edu.zut.cs.qli.base.service.BaseManager;
import edu.zut.cs.qli.comment.domain.Comment;

import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
public interface CommentManager extends BaseManager<Comment, Long>{
    /**
     * 根据Article的ID查询
     * @param id
     * @return
     */
    public List<Comment> findByArticle(long id);

}
