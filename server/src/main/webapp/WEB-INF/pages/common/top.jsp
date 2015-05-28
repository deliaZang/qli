<%@ page import="edu.zut.cs.qli.user.domain.User" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<div class="container-fluid" id="header_title">
  <div class="row-fluid" id="header">
    <div class="span12">
      <div class="navbar">
        <div class="navbar-inner">
          <div class="container-fluid top_nav">
            <ul class="nav nav-tabs"
                style="font-weight: bolder; border-bottom: 2px; border-bottom-style: solid; border-bottom-color: blue;">
              <li class="active" style="width: 30%;">
                <a><span style="font-size: 24px">Linux课程设计</span></a></li>
              <li><a href="<%=path%>/user/index.html" target="_self">首页</a></li>
              <li><a href="<%=path%>/article/list.html" target="_self">目录</a></li>
              <c:if test="${user.role == 'teacher'}">
                <li><a href="<%=path%>/comment/list.html" target="_self">评论</a></li>
              </c:if>
              <c:if test="${user.role == 'student'}">
                <li><a href="<%=path%>/note/list.html" target="_self">笔记</a></li>
              </c:if>
              <c:if test="${User.NULL eq user}">
                <li><a href="<%=path%>/user/login.html" class="colblue">登录</a></li>
                <li><a href="<%=path%>/user/register.html" class="colf1">注册</a></li>
              </c:if>
              <c:if test="${User.NULL ne user}">
                <li><a href="<%=path%>/user/personal.html" target="_self">您好，${user.nick}</a>
                <li><a href="<%=path%>/user/exit.html" class="colf1">退出</a></li>
              </c:if>
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
</div>