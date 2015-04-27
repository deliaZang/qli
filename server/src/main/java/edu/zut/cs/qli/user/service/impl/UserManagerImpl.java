package edu.zut.cs.qli.user.service.impl;

import edu.zut.cs.qli.base.service.impl.BaseManagerImpl;
import edu.zut.cs.qli.user.dao.UserDao;
import edu.zut.cs.qli.user.domain.User;
import edu.zut.cs.qli.user.service.UserManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service("userManager")
@Transactional
public class UserManagerImpl  extends BaseManagerImpl<User, Long> implements UserManager {
    UserDao userDao;

    @Autowired
    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

}
