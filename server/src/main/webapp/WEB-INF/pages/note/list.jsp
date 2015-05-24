<%@ page import="edu.zut.cs.qli.user.domain.User" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String path = request.getContextPath();
    User user = (User) request.getSession().getAttribute("user");
%>
<html>
<head>
    <title></title>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css" rel="stylesheet"/>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css" rel="stylesheet"/>
    <script>
        function show(index){
            $(".note_content").hide();
            $("#note_content"+index).show();

        }
    </script>
    <style>
        body {
            font-family: "微软雅黑";
            margin: 0;
            padding: 0;
        }

        .note {
            height: 100%;
            margin: 0px auto;
            padding: 20px 10px 10px;
            position: relative;
        }

        .note_title {
            width: 30%;
            float: left;
            border-right: 1px solid blue;
        }

        .note_content {
            width: 70%;
            height: 100%;
            float: right;
            padding: 20px;
            display: none;
        }

        .note_title ul {
            padding: 0;
            margin: 20px 10px;
        }

        .note_title li {
            display: block;
            line-height: 30px;
            width: 100%;
            height: 30px;
            position: relative;
        }

        .note_title li a {
            width: 70%;
            height: 30px;
            display: inline-block;
            float: left;
            overflow: hidden;
            text-decoration: none;
            text-overflow:ellipsis;
            white-space:nowrap;
        }

        .note_title li span {
            width: 30%;
            height: 30px;
            display: inline-block;
            overflow: hidden;
        }

        .note_content .theme {
            width: 100%;
            height: 40px;
            line-height: 40px;
            border-bottom: 1px solid #333;
            overflow: hidden;
        }

        .note_content .content {
            margin-top: 15px;
        }

        .first {
            display: block;
        }
    </style>
</head>
<body>
<div class="note">
    <div class="note_title">
        <ul>
            <c:forEach items="${noteList}" var="note" varStatus="status">
                <c:if test="${status.index == 0}">

                </c:if>
                <li><a href="javascript:void(0);" onclick="show(${status.index+1})">${note.title}</a> <span>${note.dateCreated}</span></li>
            </c:forEach>
        </ul>
    </div>
    <c:forEach items="${noteList}" varStatus="status" var="note">
        <c:if test="${status.index == 0}">
            <div class="note_content first" id="note_content${status.index+1}">
                <div class="theme">${note.title}</div>
                <div class="content">
                    ${note.content}
                </div>
            </div>
        </c:if>
        <div class="note_content" id="note_content${status.index+1}">
            <div class="theme">${note.title}</div>
            <div class="content">
                    ${note.content}
            </div>
        </div>
    </c:forEach>
</div>
</body>
</html>
