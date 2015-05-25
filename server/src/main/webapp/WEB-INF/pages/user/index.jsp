<%@ page import="edu.zut.cs.qli.user.domain.User" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%
    String path = request.getContextPath();
    User user = (User) request.getSession().getAttribute("user");
%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title></title>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css" rel="stylesheet"/>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css" rel="stylesheet"/>
    <script type="text/javascript" src="<%=path%>/resources/js/SimpleTree1.3/js/SimpleTree.js"></script>
    <link href="<%= path%>/resources/style/tree_themes/SimpleTree.css" rel="stylesheet" type="text/css">
    <script type="text/javascript">
        var localObj = window.location;
        var contextPath = localObj.pathname.split("/")[1];
        var basePath = localObj.protocol + "//" + localObj.host + "/";
    </script>
    <script type="text/javascript">

    </script>
</head>
<body style="width: 80%;margin-left: 10%;margin-right: 10%;">

<div class="container-fluid">
    <div class="row-fluid" id="header">
        <div class="span12">
            <div class="navbar">
                <div class="navbar-inner">
                    <div class="container-fluid">
                        <ul class="nav nav-tabs"
                            style="font-weight: bolder; border-bottom: 2px; border-bottom-style: solid; border-bottom-color: blue;">
                            <li class="active" style="width: 30%;">
                                <a><span style="font-size: 24px">Linux课程设计</span></a></li>
                            <li><a href="<%=path%>/article/main.html" target="mainView">首页</a></li>
                            <li><a href="<%=path%>/article/list.html" target="mainView">目录</a></li>
                            <c:if test="${user.role == 'teacher'}">
                                <li><a href="<%=path%>/comment/list.html" target="mainView">评论</a></li>
                            </c:if>
                            <c:if test="${user.role == 'student'}">
                                <li><a href="<%=path%>/note/list.html" target="mainView">笔记</a></li>
                            </c:if>
                            <% if (null == user) {%>
                            <li><a href="<%=path%>/user/login.html" class="colblue">登录</a></li>
                            <li><a href="<%=path%>/user/register.html" class="colf1">注册</a></li>
                            <%} else {%>
                            <li><a href="<%=path%>/user/personal.html">您好，${user.nick}</a>
                            <li><a href="<%=path%>/user/exit.html" class="colf1">退出</a></li>
                            <%}%>
                            <li class="dropdown pull-right">
                                <a href="" data-toggle="dropdown" class="dropdown-toggle">应用下载<strong
                                        class="caret"></strong></a>
                                <ul class="dropdown-menu">
                                    <li><a href="">宝贝计划 for Android</a></li>
                                    <li><a href="">Another action</a></li>
                                    <li class="divider"></li>
                                    <li><a href="">Separated link</a></li>
                                </ul>
                            </li>
                        </ul>
                    </div>
                </div>

            </div>
        </div>
    </div>
    <div class="row-fluid" id="main">
        <div class="span12">
            <iframe name="mainView"
                    style="border:none; width: 100%; height: 80%; float: inherit;margin-right: 10px;"
                    src="<%=path%>/article/main.html"></iframe>
        </div>
    </div>
    <div class="row-fluid" id="foot">
        <div class="col-md-12 column"
             style="margin-top:2%;border-top: 2px; border-top-style: solid; border-top-color: blue;"
             align="center">
            <span>@Copyright归FreeTeam所有</span><br> <span><a
                href="#">联系我们</a></span>
        </div>
    </div>
</div>
</body>
</html>