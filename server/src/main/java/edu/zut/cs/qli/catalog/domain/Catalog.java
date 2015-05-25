package edu.zut.cs.qli.catalog.domain;

import com.fasterxml.jackson.annotation.JsonBackReference;
import com.fasterxml.jackson.annotation.JsonManagedReference;
import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.base.domain.BaseEntityDomain;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-19.
 */
@Entity
@Table(name = "Catalog")
public class Catalog extends BaseEntityDomain {

    @JsonBackReference
    @ManyToOne
    @JoinColumn(name = "a_id", nullable = false)
    private Article article;

    @JsonBackReference
    @ManyToOne
    @JoinColumn(name = "p_id")
    private Catalog parent;

    @Column(name = "name", nullable = false)
    private String name;

    @Column(name = "flag", nullable = false)
    private String flag;

    @Column(name = "level", nullable = false)
    private long level;

    @Column(name = "count", nullable = false)
    private long count;

    @JsonManagedReference
    @OrderBy(value = "count ASC")
    @OneToMany(mappedBy = "parent", cascade = CascadeType.ALL)
    private List<Catalog> children = new ArrayList<>();


    public Article getArticle() {
        return article;
    }

    public void setArticle(Article article) {
        this.article = article;
    }

    public Catalog getParent() {
        return parent;
    }

    public void setParent(Catalog parent) {
        this.parent = parent;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getFlag() {
        return flag;
    }

    public void setFlag(String flag) {
        this.flag = flag;
    }

    public long getLevel() {
        return level;
    }

    public void setLevel(long level) {
        this.level = level;
    }

    public long getCount() {
        return count;
    }

    public void setCount(long count) {
        this.count = count;
    }

    public List<Catalog> getChildren() {
        return children;
    }

    public void setChildren(List<Catalog> children) {
        this.children = children;
    }
}
