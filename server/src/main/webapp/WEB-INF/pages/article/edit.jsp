<%--
  Created by IntelliJ IDEA.
  User: shouhutsh
  Date: 15-4-12
  Time: 下午1:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String path = request.getContextPath();
%>
<html>
<head>

    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <title>编辑文章</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
    <link href="<%=path%>/resources/bootstrap-3.3.4-dist/css/bootstrap.min.css">
    <link href="/resources/js/umeditor/themes/default/css/umeditor.css" type="text/css" rel="stylesheet">
    <script type="text/javascript" src="/resources/js/umeditor/third-party/jquery.min.js"></script>
    <script type="text/javascript" charset="utf-8" src="/resources/js/umeditor/umeditor.config.js"></script>
    <script type="text/javascript" charset="utf-8" src="/resources/js/umeditor/umeditor.min.js"></script>
    <script type="text/javascript" src="/resources/js/umeditor/lang/zh-cn/zh-cn.js"></script>
</head>
<body>
<div class="container-fluid">
    <div class="row-fluid">
        <div class="span2" style="background-color: red">
        </div>
        <div class="span6">
            <h1>文章编辑</h1>
            <input type="hidden" id="id" value="${article.id}"/>

            <h3>题目</h3>
            <input type="text" id="title" value="${article.title}"/>

            <h3>内容</h3>
            <script type="text/plain" id="myEditor" style="width:1000px;height:240px;">${article.content}</script>

            <button class="btn" onclick="sendContent()">发表</button>
        </div>
        <div class="span4" style="background-color: green" >
        </div>
    </div>
</div>


<script type="text/javascript">
    UM.getEditor('myEditor');

    // FIXME
    function sendContent() {
        var xmlhttp;
        if (window.XMLHttpRequest) {// code for IE7+, Firefox, Chrome, Opera, Safari
            xmlhttp = new XMLHttpRequest();
        }
        else {// code for IE6, IE5
            xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
        }

        var id = document.getElementById("id").value;
        var title = document.getElementById("title").value;
        var content = UM.getEditor('myEditor').getContent().
                replace(/%/g, "%25").replace(/\&/g, "%26").replace(/\+/g, "%2B").replace(/\n/g, '');
        xmlhttp.onreadystatechange=function() {
            if (xmlhttp.readyState == 4) {
                if (xmlhttp.status == 200) {
                    alert(xmlhttp.responseText);
                    window.location.href = "/article/list.html";
                } else {
                    alert("Error!");
                }
            }
        };
        xmlhttp.open("POST", "/article/do.html", true);
        xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xmlhttp.send("id=" + id + "&title=" + title + "&content=" + content);

    }
</script>
</body>
</html>
