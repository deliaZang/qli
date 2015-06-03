package edu.zut.cs.qli.user.controller;

import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.user.domain.User;
import edu.zut.cs.qli.user.service.UserManager;
import edu.zut.cs.qli.utils.Constants;
import org.apache.commons.lang3.StringUtils;
import org.codehaus.jackson.map.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;

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

    @RequestMapping(method = RequestMethod.GET, value = "/index.html")
    public String index(Model model) {
        model.addAttribute("user", User.NULL);
        return "user/index";
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
    public String loginCheck(@RequestParam String role,
                             @RequestParam String name,
                             @RequestParam String password,
                             Model model) {
        //用户名或者密码为空，返回登陆页
        if (StringUtils.isBlank(name) || StringUtils.isBlank(password)) {
            model.addAttribute("msg", "登录失败，用户名或密码不能为空");
            return "user/login";
        }
        User user = userManager.findByName(name);
        if (user.getPassword().equals(password) && user.getRole().equals(role)) {
            //把用户信息存放在session中
            model.addAttribute("user", user);
            return "user/index";
        } else {
            //用户名或者密码错误，返回登陆页
            model.addAttribute("msg", "登录失败，用户名或密码错误");
            return "user/login";
        }
    }

    protected void generateJson(HttpServletResponse response, Object obj)
            throws Exception {
        ObjectMapper mapper = new ObjectMapper();
        response.setHeader("Pragma", "No-cache");
        response.setHeader("Cache-Control", "no-cache");
        response.setDateHeader("Expires", 0);
        response.setContentType("text/html;charset=utf-8");
        response.setCharacterEncoding("utf-8");
        mapper.writeValue(response.getWriter(), obj);
    }

    /**
     * 查找用户名是否存在，验证唯一性
     * @param name
     * @return

     */

    @RequestMapping(method = RequestMethod.POST, value = "/isExit")
    public boolean isExit(String name,HttpServletResponse response) throws Exception {
        User user = userManager.findByName(name);
        boolean flag=false;
        if(user == null){
            flag = true;
        }
        generateJson(response, flag);
        return flag;
    }

    @RequestMapping(method = RequestMethod.POST, value = "/register")
    public String saveUser(User user) {
        user.setRole("student");
        this.userManager.save(user);
        return "user/login";
    }

    /**
     * 用户退出系统
     *
     * @return
     */
    @RequestMapping(value = "/exit")
    public String exit(Model model) {
        model.addAttribute("user", User.NULL);
        return "user/index";
    }

    @RequestMapping(method = RequestMethod.POST, value = "/update")
    public String update(User user) {
        this.userManager.save(user);
        return Constants.MESSAGE_SUCCESS;
    }

    @RequestMapping(method = RequestMethod.GET, value = "/file.html")
    public String file() {
        return "user/filet";
    }

    @RequestMapping(method = RequestMethod.POST, value = "/upload")
    public String fileUp(@RequestParam(value = "file") MultipartFile file, Model model) {
        return "";
    }

}
