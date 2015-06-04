<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>个人中心</title>
  <%@include file="../common/header.jsp" %>
  <script type="application/javascript">
    $(function () {
      /** 信息验证**/
      $("#updatePassword").validate({
        rules: {
          password: {required: true},
          newPassword: {required: true, minlength: 6}
        },
        errorPlacement: function (error, element) {
          error.appendTo(element.siblings("span"));
        }
      });
      $("#password").blur(function () {
        if ($("#password").val() != $("#passwordInput").val()) {
          alert("密码不正确，请确认后再次输入");
          $("#password").focus();
        }
      });
      $("#confirmNewPassword").blur(function () {
        if ($("#confirmNewPassword").val() != $("#newPassword").val()) {
          alert("两次密码输入不一致，请确认后再次输入");
          $("#confirmNewPassword").focus();
        }
      });
      $("#updatePwdBtn").click(function () {
        var userId = $("#userIdInput").val();
        var password = $("#newPassword").val();
        var user;
        $.ajax({
          type: "get",
          url: basePath + "user/" + userId + ".json",
          dataType: "json",
          async: false,
          success: function (result) {
            user = result;
          },
          error: function () {
          }
        });
        user.password = password;
        $.ajax({
          type: "put",
          data: JSON.stringify(user),
          url: basePath + "user/" + userId + ".json",
          contentType: 'application/json;charset=utf-8',
          dataType: "json",
          async: false,
          success: function (msg) {
            alert("修改成功");
            alert(msg.name);

            window.location.href = basePath + "user/login.html";
          }
        });
      });
    });
  </script>
  <style>
    .control-label{  line-height: 35px;}
    .controls .input{  line-height: 28px;margin: 5px 0;}
    #updatePwdBtn,#updateBtn{  width: 162px;margin-top: 20px; border: none;}
  </style>

</head>
<body>
<%@include file="../common/top.jsp" %>

<input id="passwordInput" value="${user.password}" hidden="hidden">

<div class="container personal_container" style="width: 1050px">
  <div class="panel panel-primary">
    <div class="tabbable  col-md-6 column" id="tabs-159901" style="margin: 0 auto;float: none;">
      <div class="panel-heading">
        <ul class="nav nav-tabs">
          <li class="active"><a href="#panel-924305" data-toggle="tab">个人信息</a></li>
          <li><a href="#panel-143310" data-toggle="tab">修改密码</a></li>
        </ul>
      </div>
      <div class="panel-body">
        <div class="tab-content">
          <div class="tab-pane  active" id="panel-924305">
            <form class="form-horizontal" role="form" id="updateUserInfo" action="<%=path%>/user/update.html">
              <div class="control-group">
                <label class="control-label" for="name">姓名</label>

                <div class="controls">
                  <input type="text" class="input" id="name" value="${user.name}">
                </div>
              </div>
              <div class="control-group">
                <label class="control-label" for="nick">昵称</label>

                <div class="controls">
                  <input type="text" class="input" id="nick" value="${user.nick}">
                </div>
              </div>
              <div class="form-actions">
                <button type="submit" class="btn btn-primary" id="updateBtn">提交</button>
              </div>
            </form>
          </div>

          <div class="tab-pane" id="panel-143310">
            <form class="form-horizontal" role="form" id="updatePassword" method="post" action="<%=path%>/user/update.html">
              <div class="control-group">
                <label class="control-label" for="password">原密码</label>

                <div class="controls">
                  <input type="password" class="input" placeholder="密码" id="password"
                         name="password">
                  <font color="red">*</font>
                  <span></span>
                </div>
              </div>
              <div class="control-group">
                <label class="control-label" for="newPassword">新密码</label>

                <div class="controls">
                  <input type="password" class="input" placeholder="新密码" id="newPassword"
                         name="newPassword">
                  <font color="red">*</font>
                  <span></span>
                </div>
              </div>
              <div class="control-group">
                <label class="control-label" for="confirmNewPassword">确认新密码</label>

                <div class="controls">
                  <input type="password" class="input" placeholder="确认新密码" id="confirmNewPassword"
                         name="confirmNewPassword">
                  <font color="red">*</font>
                  <span></span>
                </div>
              </div>
              <div class="form-actions">
                <button type="submit" class="btn btn-primary" id="updatePwdBtn">提交</button>
              </div>
            </form>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>

<%@include file="../common/foot.jsp" %>

</body>
