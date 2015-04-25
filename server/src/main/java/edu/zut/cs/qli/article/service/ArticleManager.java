package edu.zut.cs.qli.article.service;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.base.service.BaseManager;

import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
public interface ArticleManager extends BaseManager<Article, Long> {
    public Article findDetailById(long id);

    public void doSave(Article article, String html);

    public List<Article> findHot();

    public List<Article> findLasted();
}
