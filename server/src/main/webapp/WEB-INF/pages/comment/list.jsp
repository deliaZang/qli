<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title></title>
    <style>
        body {
            margin: 0;
            padding: 0;
        }

        ul {
            list-style: none;
            padding: 0;
        }

        .main {
            width: 80%;
            height: 100%;
            position: relative;
            margin: 0 auto;
        }

        .main_left {
            width: 34%;
            height: 100%;
            float: left;
            position: relative;
        }

        .hot_book, .main_right {
            background: #fff;
            box-shadow: 0 1px 2px #c5c5c5;
        }

        .hot_book span {
            display: block;
            height: 35px;
            line-height: 35px;
            background: rgb(0, 178, 255);
            padding-left: 20px;
            color: #fff;
            font-weight: bold;
        }

        .hot_book ul {
            padding: 0 20px;
        }

        .hot_book a {
            display: block;
            line-height: 30px;
            height: 30px;
            width: 100%;
            text-overflow: ellipsis;
            overflow: hidden;
            white-space: nowrap;
        }

        .hot_book li + li {
            margin-top: 10px;
        }

        .hot_book .summry {
            height: 79px;
            line-height: 25px;
            overflow: hidden;
        }

        .main_right {
            width: 65%;
            height: 100%;
            float: right;
        }

        .main_right ul {
            padding: 0 25px;
        }

        .main_right li {
            border-top: 1px solid #edf1f2;
            border-bottom: 1px solid #edf1f2;
            padding: 10px 0;
        }

        .main_right .name {
            display: block;
            height: 25px;
            line-height: 25px;
        }

        .main_right p {
            line-height: 25px;
        }
    </style>
</head>
<body>
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
</body>
</html>
