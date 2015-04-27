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
    <script type="text/javascript" src="<%=path%>/resources/js/jquery-2.0.3.js"></script>
    <link href="<%=path%>/resources/style/bootstrap-3.1.1/dist/css/bootstrap.min.css"
          rel="stylesheet" type="text/css"/>
    <link
            href="<%=path%>/resources/style/bootstrap-3.1.1/dist/css/bootstrap-theme.css"
            rel="stylesheet" type="text/css"/>

    <script type="text/javascript"
            src="<%=path%>/resources/js/jquery-validation-1.12.0/dist/jquery.validate.js"></script>
    <script type="text/javascript"
            src="<%=path%>/resources/js/jquery-validation-1.12.0/src/localization/messages_zh.js"></script>
    <link href="<%=path%>/resources/style/bootstrap-3.1.1/dist/css/bootstrap-datetimepicker.css" rel="stylesheet"
          type="text/css"/>

    <script type="text/javascript"
            src="<%=path%>/resources/style/bootstrap-3.1.1/dist/js/bootstrap-datetimepicker.js"></script>
    <script type="text/javascript"
            src="<%=path%>/resources/style/bootstrap-3.1.1/dist/js/locales/bootstrap-datetimepicker.zh-CN.js"></script>
    <script type="text/javascript">
        $(function () {
            $("#register").validate({
                rules: {
                    name: {required: true, minlength: 6},
                    nick: {required: true, minlength: 6},
                    birthday: {required: true},
                    password: {required: true, minlength: 6},
                    confirmPassword: {required: true, minlength: 6}
                },
                errorPlacement: function (error, element) {
                    error.appendTo(element.siblings("span"));

                }});
            $("#confirmPassword").blur(function () {
                if ($("#confirmPassword").val() != $("#password").val()) {
                    alert("两次密码输入不一致，请确认后再次输入");
                    $("#confirmPassword").focus();
                }
            });
            $("#submitBtn").click(

                    function () {
                        var name = $('#name').val();
                        var nickname = $('#nick').val();
                        var birthday = $('#birthday').val();
                        var password = $('#password').val();
                        var params = {
                            name: name,
                            nickname: nickname,
                            birthday: birthday,
                            password: password
                        };
                        $.ajax({
                            type: "post",
                            contentType: 'application/json;charset=utf-8',
                            data: JSON.stringify(params),
                            dataType: "json",
                            url: basePath + "user/0.json",
                            success: function (msg) {
                                alert("注册成功,请记住你的ID:" + msg.id);
                                window.location.href = basePath + "user/login.html";
                            },
                            error: function (msg) {
                                alert("注册失败");
                                alert(msg);
                            }
                        });
                    });
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
            width: 120px;
            height: 50px;
        }
    </style>
</head>
<body>
<div class="container" align="center">
    <form class="form-horizontal well" id="register" method="post">
        <div class="panel panel-primary">
            <div class="panel-heading">用户注册</div>

            <div class="panel-body">
                <table>
                    <tr>
                        <td class="left"><label class="control-label" for="name">姓名</label>
                        </td>
                        <td class="right"><input type="text" class="input" id="name" name="name" placeholder="用户名">
                            <font color="red">*</font><br>
                            <span></span></td>
                    </tr>
                    <tr>
                        <td class="left"><label class="control-label" for="nick" id="nickLabel">昵称</label>
                        </td>
                        <td class="right"><input type="text" class="input" id="nick" name="nick">
                        </td>
                    </tr>
                    <tr>
                        <td class="left"><label class="control-label" for="birthday" id="birthdayLabel">生日</label>
                        </td>
                        <td class="right">
                            <div class="controls input-append date form_datetime"
                                 data-date-format="yyyy-MM-dd" data-link-field="dtp_input1">
                                <input size="16" type="text" value="" class="input" id="birthday" name="birthday"
                                       readonly> <span
                                    class="add-on"><i class="icon-remove"></i></span> <span
                                    class="add-on"><i class="icon-th"></i></span>
                            </div>
                        </td>
                    </tr>
                    <tr>
                        <td class="left"><label class="control-label" for="password" id="passwordLabel">密码</label>
                        </td>
                        <td class="right"><input type="password" class="input" placeholder="密码" id="password" name="password">
                            <font color="red">*</font><br>
                            <span></span></td>
                    </tr>
                    <tr>
                        <td class="left"><label class="control-label" for="confirmPassword" id="confirmPasswordLabel">确认密码</label>
                        </td>
                        <td class="right"><input type="password" class="input" placeholder="确认密码" id="confirmPassword"
                                                 name="confirmPassword">
                            <font color="red">*</font><br>
                            <span></span></td>
                    </tr>
                </table>
            </div>
            <div class="panel-footer">
                <div class="form-actions">
                    <div class="form-actions">
                        <button type="submit" class="btn btn-primary" id="submitBtn">提交</button>
                        <button class="btn" type="reset">重置</button>
                    </div>
                </div>
            </div>
        </div>

    </form>
</div>

<script type="application/javascript">
    $(function () {
        $('.form_datetime').datetimepicker({
            language: 'zh-CN',
            weekStart: 1,
            todayBtn: 1,
            autoclose: 1,
            todayHighlight: 1,
            startView: 2,
            forceParse: 0,
            showMeridian: 1
        });
    });

</script>
</body>
</html>