package edu.zut.cs.qli.user.domain;

import edu.zut.cs.qli.base.domain.BaseEntityDomain;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name="t_user")
public class User extends BaseEntityDomain {

    @Column(name="nick")
    private String nick;

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

    public String getNick() {
        return nick;
    }

    public void setNick(String nick) {
        this.nick = nick;
    }
}
