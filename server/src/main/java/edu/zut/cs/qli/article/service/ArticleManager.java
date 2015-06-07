package edu.zut.cs.qli.article.service;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.base.service.BaseManager;

import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
public interface ArticleManager extends BaseManager<Article, Long> {
    /**
     * 根据Id查找
     * @param id
     * @return
     */
    public Article findDetailById(long id);

    /**
     * 保存
     * @param article
     * @param html
     */
    public void doSave(Article article, String html);

    /**
     * 查找最热门
     * @return
     */
    public List<Article> findHot();

    /**
     * 查找最新
     * @return
     */
    public List<Article> findLasted();

  //  public void deleteBatch(List<Long> ids);

    /**
     * 查找文件编程
     * @return
     */
    public List<Article> findFileList();

    /**
     * 查找网络编程
     * @return
     */
    public List<Article> findWebList();

    /**
     * 批量删除
     * @param ids
     */
    public void deleteBatch(String[] ids);

    public List<Article> findByUser(long id);
}
