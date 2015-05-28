package edu.zut.cs.qli.article.service.impl;

import edu.zut.cs.qli.article.dao.ArticleDao;
import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.base.service.impl.BaseManagerImpl;
import edu.zut.cs.qli.catalog.dao.CatalogDao;
import edu.zut.cs.qli.catalog.domain.Catalog;
import edu.zut.cs.qli.utils.CatalogUtil;
import edu.zut.cs.qli.utils.FileUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Service("articleManager")
@Transactional
public class ArticleManagerImpl extends BaseManagerImpl<Article, Long>
    implements ArticleManager {

    ArticleDao articleDao;

    @Autowired
    public void setUserDao(ArticleDao articleDao){
        this.articleDao = articleDao;
        this.dao = this.articleDao;
    }

    @Autowired
    private CatalogDao catalogDao;

    public Article findDetailById(long id){
        Article article = articleDao.findOne(id);
        // 由于catalogs字段加载方式为LAZY，因此需要触碰改字段使它加载出来
        article.getCatalogs().size();
        article.setContent(FileUtil.getHtml(article.getName()));
        return article;
    }

    @Override
    public void doSave(Article article, String html) {
        articleDao.save(article);

        List<Catalog> catalogs = new ArrayList<>();
        CatalogUtil catalogUtil = new CatalogUtil(article, html);
        catalogUtil.parseCatalog(null, catalogs);
        catalogDao.save(catalogs);

        FileUtil.saveHtml(article.getName(), catalogUtil.getHtml());
    }

    @Override
    public List<Article> findHot() {
        return this.articleDao.findHot();
    }

    @Override
    public List<Article> findLasted() {
        return this.articleDao.findLasted();
    }

    @Override
    public List<Article> findFileList() {
        return this.articleDao.findFileList();
    }

    @Override
    public List<Article> findWebList() {
        return this.articleDao.findWebList();
    }

    @Override
    public void deleteBatch(String[] ids) {
    }
}
