package edu.zut.cs.qli.user.domain;

import edu.zut.cs.qli.base.domain.BaseEntityDomain;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name="t_user")
public class User extends BaseEntityDomain {

    @Column(name="nick",nullable = false)
    private String nick;

    @Column(name="name",nullable = false)
    private String name;

    @Column(name="password",nullable = false)
    private String password;

    @Column(name = "role",nullable = false)
    private  String role;

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

    public String getNick() {
        return nick;
    }

    public void setNick(String nick) {
        this.nick = nick;
    }

    public String getRole() {
        return role;
    }

    public void setRole(String role) {
        this.role = role;
    }

    public static final User NULL = new User();
}
