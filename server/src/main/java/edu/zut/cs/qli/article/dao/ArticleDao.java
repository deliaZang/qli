package edu.zut.cs.qli.article.dao;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.base.dao.BaseDao;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
public interface ArticleDao extends BaseDao<Article, Long> {

    @Query(value = "select a from Article a order by visits desc ")
    public List<Article> findHot();

    @Query(value = "select a from Article a order by dateCreated desc")
    public List<Article> findLasted();

    @Query(value = "select a from Article a where a.type = 'fileProgram' ")
    public List<Article> findFileList();

    @Query(value = "select a from Article a where a.type = 'webProgram'")
    public List<Article> findWebList();

}
