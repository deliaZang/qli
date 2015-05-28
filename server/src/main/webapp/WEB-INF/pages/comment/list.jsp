<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>评论</title>
    <%@include file="../common/header.jsp" %>
    <link href="<%=path%>/resources/style/comment.css" rel="stylesheet"/>

</head>
<body>
<%@include file="../common/top.jsp" %>
<div class="main">
    <div class="main_left">
        <div class="hot_book">
            <span>课程</span>

            <ul>
                <c:forEach items="${commentList}" var="c">
                    <li>
                        <a href="javascrit:void(0);">${c.article.title}</a>

                        <div class="summry">
                                ${c.article.content}
                        </div>
                    </li>
                </c:forEach>
            </ul>
        </div>
    </div>
    <div class="main_right">
        <ul>
            <c:forEach items="${commentList}" var="c">
                <li>
                    <span class="name">${c.user.nick}</span>

                    <p>${c.content}</p>
                </li>
            </c:forEach>
        </ul>
    </div>
</div>
<%@include file="../common/foot.jsp" %>

</body>
</html>
