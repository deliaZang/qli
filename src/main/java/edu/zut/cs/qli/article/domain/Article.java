package edu.zut.cs.qli.article.domain;

import edu.zut.cs.qli.base.domain.BaseEntityDomain;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;

/**
 * Created by shouhutsh on 15-4-12.
 */
@SuppressWarnings("ALL")
@Entity
@Table(name = "Article")
public class Article extends BaseEntityDomain {

    @Column(name = "title", nullable = false)
    private String title;
    @Column(name = "content", nullable = false)
    private String content;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
