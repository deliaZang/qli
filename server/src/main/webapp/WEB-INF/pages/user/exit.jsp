<%@ page import="edu.zut.cs.qli.user.domain.User" %>
<%
    String path = request.getContextPath();
%>
<%
    User user = (User)request.getSession().getAttribute("user");
    if(user!=null)
    {
        request.getSession().removeAttribute("user");
    }
    response.sendRedirect(path+"/user/main.html");
%>
