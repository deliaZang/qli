package edu.zut.cs.qli.comment.service.impl;

import edu.zut.cs.qli.base.service.impl.BaseManagerImpl;
import edu.zut.cs.qli.comment.dao.CommentDao;
import edu.zut.cs.qli.comment.domain.Comment;
import edu.zut.cs.qli.comment.service.CommentManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * Created by ZL on 2015/4/27.
 */
@Service("commentManager")
@Transactional
public class CommentManagerImpl extends BaseManagerImpl<Comment, Long> implements CommentManager{
    CommentDao commentDao;

    @Autowired
    public void setCommentDao(CommentDao commentDao) {
        this.commentDao = commentDao;
        this.dao = this.commentDao;
    }

    @Override
    public List<Comment> findByArticle(long id) {
        return this.commentDao.findByArticle(id);
    }
}
