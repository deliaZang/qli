package edu.zut.cs.qli.article.domain;

import com.fasterxml.jackson.annotation.JsonManagedReference;
import edu.zut.cs.qli.base.domain.BaseEntityDomain;
import edu.zut.cs.qli.catalog.domain.Catalog;
import edu.zut.cs.qli.user.domain.User;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Entity
@Table(name = "Article")
public class Article extends BaseEntityDomain {

    @ManyToOne
    @JoinColumn(name = "u_id", nullable = false)
    private User user;

    @Column(name = "title", nullable = false)
    private String title;

    @Column(name = "name", nullable = false)
    private String name;

    @Column(name = "visits", nullable = false)
    private Integer visits = 0;

    /**
     * 文件编程：fileProgram;
     * 网络编程：webProgram
     */
    @Column(name = "type", nullable = false)
    private String type;

    @JsonManagedReference
    @OrderBy(value = "id ASC")
    @OneToMany(mappedBy = "article", cascade = CascadeType.ALL)
    private List<Catalog> catalogs = new ArrayList<>();

    public Integer getVisits() {
        return visits;
    }

    public void setVisits(Integer visits) {
        this.visits = visits;
    }

    @Transient
    private String content;


    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
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

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}
