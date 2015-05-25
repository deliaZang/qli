package edu.zut.cs.qli.user.dao;

import edu.zut.cs.qli.base.dao.BaseDao;
import edu.zut.cs.qli.user.domain.User;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

/**
 * Created by ZL on 2015/4/26.
 */

public interface UserDao extends BaseDao<User, Long>{

    /**
     * 根据用户名查询
     * @param userName
     * @return
     */
    @Query(value = "select u from User u where u.name = :name")
    public User findByName(@Param("name") String userName);

    }
