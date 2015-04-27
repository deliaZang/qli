package edu.zut.cs.qli.user.domain;

import edu.zut.cs.qli.base.domain.BaseEntityDomain;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name="t_user")
public class User extends BaseEntityDomain {

    @Column(name="userId")
    private String userId;
    
    @Column(name="name")
    private String name;

    @Column(name="password")
    private String password;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
