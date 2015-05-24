package edu.zut.cs.qli.user.service;

import edu.zut.cs.qli.base.service.BaseManager;
import edu.zut.cs.qli.user.domain.User;

/**
 * Created by ZL on 2015/4/26.
 */
public interface UserManager extends BaseManager<User, Long> {
    /**
     * 根据用户名查询
     * @param userName
     * @return
     */
    public User findByName(String userName);
}
