package edu.zut.cs.qli.utils;


import edu.zut.cs.qli.user.domain.User;

import javax.servlet.*;
import java.io.IOException;

public class LoginFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        User user = (User) servletRequest.getAttribute("user");
        if (null == user)
        {
            servletRequest.getRequestDispatcher("/user/login.html");
        }
    }

    @Override
    public void destroy() {

    }
}
