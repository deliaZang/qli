<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" %>
<%
    String path = request.getContextPath();
%>
<!DOCTYPE html>
<html>
<head>
    <title>用户登录</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <script type="text/javascript">
        var localObj = window.location;
        var contextPath = localObj.pathname.split("/")[1];
        var basePath = localObj.protocol + "//" + localObj.host + "/";
    </script>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery.validate.js"></script>
    <script type="text/javascript" src="<%=path%>/resources/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="<%=path%>/resources/js/messages_zh.js"></script>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css"  rel="stylesheet"/>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css"  rel="stylesheet"/>
    <script type="application/javascript">
        $(function () {
            $("#loginForm").validate({
                rules: {
                    name: {required: true, minlength: 6},
                    password: {required: true, minlength: 6}
                },
                errorPlacement: function (error, element) {
                    error.appendTo(element.siblings("span"));

                }});
        });
    </script>
</head>
<style type="text/css">
    .container {
        width: 40%;
        height: 600px;
        margin-left: 30%;
        margin-right: 30%;
        margin-top: 10%;
    }
    .panel-heading
    {
        background-color: #b2dba1;
        font-size: 20px;
        font-family: "Trebuchet MS", "Arial", "Helvetica", "Verdana", "sans-serif";
    }
</style>
<body>
<div id="info">
    <c:if test="not empty ${msg !=null}">
        <script type="text/javascript">
            alert(${msg});
        </script>
    </c:if>
</div>
<div class="container" align="center">
    <form class="form-horizontal well" id="loginForm" method="post" action="<%=path%>/user/login.html">
        <div class="panel panel-primary">
            <div class="panel-heading">用户登录</div>
            <div class="panel-body">
                <div class="control-group">
                    <label class="control-label" for="role">角色</label>
                    <select style="width: 174px;height: 26px;" name="role">
                        <option id="role"  value="teacher">教师</option>
                        <option value="student" selected="selected">学生</option>
                    </select>
                </div>
                <div class="control-group">
                    <label class="control-label" for="userId">用户名</label>
                    <input type="text" id="userId" class="input" placeholder="用户名" name="name">
                    <font color="red">*</font><br>
                    <span></span>
                </div>
                <div class="control-group">
                    <label class="control-label" for="password">密码&nbsp;&nbsp;</label>
                    <input type="password" class="input" placeholder="密码" id="password" name="password">
                    <font color="red">*</font><br>
                    <span></span>
                </div>
                <div class="control-group">
                    <div class="controls">
                        <span class="help-inline"><a href="<%=path%>/user/register.html">还没账户，点击注册</a></span>
                    </div>
                </div>
            </div>
            <div class="panel-footer">
                <div class="form-actions">
                    <button type="submit" class="btn btn-primary" id="loginBtn">登录</button>
                    <button type="reset" class="btn">重置</button>
                </div>
            </div>
        </div>
    </form>
</div>
</body>
</html>