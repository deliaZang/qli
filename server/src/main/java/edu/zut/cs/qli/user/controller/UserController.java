package edu.zut.cs.qli.user.controller;

import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.user.domain.User;
import edu.zut.cs.qli.user.service.UserManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.RedirectView;

import javax.servlet.http.HttpServletRequest;

/**
 * Created by ZL on 2015/4/26.
 */
@Controller
@RequestMapping("/user")
public class UserController extends BaseEntityController<User,Long,UserManager> {

    UserManager userManager;

    @Autowired
    public void setUserManager(UserManager userManager) {
        this.userManager = userManager;
        this.manager = this.userManager;
    }

    @RequestMapping(method = RequestMethod.POST, value = "/login.html")
    public ModelAndView loginCheck(@RequestParam(value = "userId", required = true) String userId,
                                   @RequestParam(value = "password", required = true) String password,
                                   HttpServletRequest request) {
        User user = null;
        user = userManager.findById(Long.parseLong(userId));
        String msg = null;
        if (user.getPassword().equals(password)) {
            request.getSession().setAttribute("user", user);
            return new ModelAndView(new RedirectView("welcome.html"));
        } else {
            ModelAndView mav = new ModelAndView("user/login");
            mav.setViewName("user/login");
            mav.addObject("msg", "登录失败，用户名或密码错误");
            return mav;
        }
    }

}
