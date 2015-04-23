package edu.zut.cs.qli.article.service.impl;

import edu.zut.cs.qli.article.dao.ArticleDao;
import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.service.impl.BaseManagerImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Service("articleManager")
public class ArticleManagerImpl extends BaseManagerImpl<Article, Long>
    implements ArticleManager {

    ArticleDao articleDao;

    @Autowired
    public void setUserDao(ArticleDao articleDao){
        this.articleDao = articleDao;
        this.dao = this.articleDao;
    }
}
