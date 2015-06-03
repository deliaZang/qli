<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" %>
<%
    String path = request.getContextPath();
%>
<!DOCTYPE html>
<html>
<head>
    <title>用户注册</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <script type="text/javascript">
    var localObj = window.location;
    var contextPath = localObj.pathname.split("/")[1];
    var basePath = localObj.protocol + "//" + localObj.host + "/";
</script>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
    <script type="text/javascript" src="<%=path%>/resources/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery.validate.js"></script>
    <script type="text/javascript" src="<%=path%>/resources/js/messages_zh.js"></script>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css"  rel="stylesheet"/>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css"  rel="stylesheet"/>

    <script type="text/javascript">
        $(function () {
            $("#saveBtn").click(function(){
                $('#register').submit();
            });
            $("#register").validate({
                rules: {
                    name: {
                        required: true, minlength: 3,
                        remote: {
                            url: "<%=path%>/user/isExit.html",
                            type: "post",
                            dataType: "json"

                        }
                    },
                    nick: {required: true, minlength: 6},
                    birthday: {required: true},
                    password: {required: true, minlength: 6},
                    confirmPassword: {required: true, minlength: 6,equalTo:'#password'}

                },
                messages:{
                    name:{
                        remote: '用户名已存在',
                        required:'用户名必须填写'
                    },
                    confirmPassword:'两次输入不一致'
                },

                errorPlacement: function (error, element) {
                    error.appendTo(element.siblings("span"));

                }});
        });
    </script>
    <style type="text/css">
        .container {
            width: 60%;
            height: 50%;
            margin-left: 20%;
            margin-right: 20%;
            margin-top: 5%;
        }
        tr{
            width: 250px;
            height: 50px;
        }
        .left {
            width: 80px;
            height: 50px;
            padding: 10px;
        }
        .right{
            width: 200px;
            height: 50px;
        }
    </style>
</head>
<body>
<div class="container" align="center">
    <form class="form-horizontal well" id="register" method="post" action="<%=path%>/user/register.html">
        <div class="panel panel-primary">
            <div class="panel-heading">用户注册</div>

            <div class="panel-body">
                <table>
                    <tr>
                        <td class="left"><label class="control-label" for="name">姓名</label>
                        </td>
                        <td class="right"><input type="text" class="input" id="name" name="name" placeholder="用户名">
                            <font color="red">*</font>
                            <span></span></td>
                    </tr>
                    <tr>
                        <td class="left"><label class="control-label" for="nick" id="nickLabel">昵称</label>
                        </td>
                        <td class="right"><input type="text" class="input" id="nick" name="nick" placeholder="昵称">
                        </td>
                    </tr>
                    <tr>
                        <td class="left"><label class="control-label" for="password" id="passwordLabel">密码</label>
                        </td>
                        <td class="right"><input type="password" class="input" placeholder="密码" id="password" name="password">
                            <font color="red">*</font>
                            <span></span></td>
                    </tr>
                    <tr>
                        <td class="left"><label class="control-label" for="confirmPassword" id="confirmPasswordLabel">确认密码</label>
                        </td>
                        <td class="right"><input type="password" class="input" placeholder="确认密码" id="confirmPassword">
                            <font color="red">*</font>
                            <span></span></td>
                    </tr>
                </table>
            </div>
            <div class="panel-footer">
                <div class="form-actions">
                    <div class="form-actions">
                        <button type="button" class="btn btn-primary" id="saveBtn">提交</button>
                        <button class="btn" type="reset">重置</button>
                    </div>
                </div>
            </div>
        </div>
    </form>
</div>
</body>
</html>