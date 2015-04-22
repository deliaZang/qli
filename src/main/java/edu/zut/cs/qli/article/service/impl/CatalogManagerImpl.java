package edu.zut.cs.qli.article.service.impl;

import edu.zut.cs.qli.article.dao.CatalogDao;
import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.domain.Catalog;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.article.service.CatalogManager;
import edu.zut.cs.qli.base.service.impl.BaseManagerImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * Created by ZL on 2015/4/18.
 */
@Service("catalogManager")
public class CatalogManagerImpl extends BaseManagerImpl<Catalog,Long> implements CatalogManager {

    CatalogDao catalogDao ;

    ArticleManager articleManager;

    @Autowired
    public void setCatalogDao(CatalogDao catalogDao) {
        this.catalogDao = catalogDao;
    }

    @Autowired
    public void setArticleManager(ArticleManager articleManager) {
        this.articleManager = articleManager;
    }

    public void getCatalog(){
        List<Article> articleList = articleManager.findAll();
        for (Article article : articleList){
            String content = article.getContent();

        }
    }
}
