package edu.zut.cs.qli.note.domain;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.base.domain.BaseEntityDomain;

import javax.persistence.*;

/**
 * Created by ZL on 2015/4/27.
 */
@Entity
@Table(name = "note")
public class Note extends BaseEntityDomain {
    @ManyToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "a_id", nullable = false)
    private Article article;

    @Column(name = "content")
    private String content;

    public Article getArticle() {
        return article;
    }

    public void setArticle(Article article) {
        this.article = article;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
