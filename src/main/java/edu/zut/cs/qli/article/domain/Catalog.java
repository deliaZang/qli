package edu.zut.cs.qli.article.domain;

import edu.zut.cs.qli.base.domain.BaseEntityDomain;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;

/**
 * Created by ZL on 2015/4/18.
 */
@SuppressWarnings("ALL")
@Entity
@Table(name = "Catelog")
public class Catalog extends BaseEntityDomain {
    @Column(name = "catelog_name" ,nullable = false)
    private String catelogName;
    @Column(name = "article_id" , nullable = false)
    private Long articleId;
    @Column(name = "patent_id" , nullable = false)
    private Long parentId;

    public String getCatelogName() {
        return catelogName;
    }

    public void setCatelogName(String catelogName) {
        this.catelogName = catelogName;
    }

    public Long getArticleId() {
        return articleId;
    }

    public void setArticleId(Long articleId) {
        this.articleId = articleId;
    }

    public Long getParentId() {
        return parentId;
    }

    public void setParentId(Long parentId) {
        this.parentId = parentId;
    }
}
