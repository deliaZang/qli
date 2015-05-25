package edu.zut.cs.qli.user.controller;

import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.user.domain.User;
import edu.zut.cs.qli.user.service.UserManager;
import edu.zut.cs.qli.utils.Constants;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.SessionAttributes;

import javax.servlet.http.HttpServletRequest;

/**
 * Created by ZL on 2015/4/26.
 */
@Controller
@RequestMapping("/user")
@SessionAttributes("user")
public class UserController extends BaseEntityController<User, Long, UserManager> {

    UserManager userManager;

    @Autowired
    public void setUserManager(UserManager userManager) {
        this.userManager = userManager;
        this.manager = this.userManager;
    }

    @RequestMapping(method = RequestMethod.GET, value = "/login.html")
    public String login() {
        return "user/login";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/register.html")
    public String register() {
        return "user/register";
    }

    @RequestMapping(method = RequestMethod.GET, value = "/personal.html")
    public String personal() {
        return "user/personal";
    }

    @RequestMapping(method = RequestMethod.POST, value = "/login.html")
    public String loginCheck(@RequestParam String name,
                             @RequestParam String password,Model model) {
        User user = userManager.findByName(name);
        if (user.getPassword().equals(password)) {
            model.addAttribute("user", user);
            return "user/index";
        } else {
            model.addAttribute("msg", "登录失败，用户名或密码错误");
            return "user/login";
        }
    }

    @RequestMapping(method = RequestMethod.POST, value = "/register")
    public String saveUser(User user) {
        user.setRole("student");
        this.userManager.save(user);
        return "user/login";
    }
    @RequestMapping(value = "/exit")
    public String exit(HttpServletRequest request){
        User user = (User)request.getSession().getAttribute("user");
        if(user!=null)
        {
            request.getSession().removeAttribute("user");
        }
        return "user/index";
    }

    @RequestMapping(method = RequestMethod.POST, value = "/update")
    public String update(User user) {
        this.userManager.save(user);
        return Constants.MESSAGE_SUCCESS;
    }
}
