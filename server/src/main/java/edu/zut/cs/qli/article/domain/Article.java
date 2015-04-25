package edu.zut.cs.qli.article.domain;

import com.fasterxml.jackson.annotation.JsonManagedReference;
import edu.zut.cs.qli.base.domain.BaseEntityDomain;
import edu.zut.cs.qli.catalog.domain.Catalog;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Entity
@Table(name = "Article")
public class Article extends BaseEntityDomain {

    @Column(name = "title", nullable = false)
    private String title;

    @Column(name = "name", nullable = false)
    private String name;

    @Column(name = "visits", nullable = false)
    private Long visits = 0L;

    @JsonManagedReference
    @OrderBy(value = "id ASC")
    @OneToMany(mappedBy = "article", cascade = CascadeType.ALL)
    private List<Catalog> catalogs = new ArrayList<>();


    @Transient
    private String content;

    public Long getVisits() {
        return visits;
    }

    public void setVisits(Long visits) {
        this.visits = visits;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Catalog> getCatalogs() {
        return catalogs;
    }

    public void setCatalogs(List<Catalog> catalogs) {
        this.catalogs = catalogs;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
