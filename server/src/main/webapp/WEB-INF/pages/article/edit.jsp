<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
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
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css" rel="stylesheet"/>
    <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css" rel="stylesheet"/>
    <link href="/resources/js/umeditor/themes/default/css/umeditor.css" type="text/css" rel="stylesheet">
    <script type="text/javascript" src="/resources/js/umeditor/third-party/jquery.min.js"></script>
    <script type="text/javascript" charset="utf-8" src="/resources/js/umeditor/umeditor.config.js"></script>
    <script type="text/javascript" charset="utf-8" src="/resources/js/umeditor/umeditor.min.js"></script>
    <script type="text/javascript" src="/resources/js/umeditor/lang/zh-cn/zh-cn.js"></script>
</head>
<body>
<div class="clearfix">
    <div class="container-fluid">
        <div class="row-fluid">
            <div class="span12">
                <form class="form-inline" action="/article/fileUp.do" method="post" enctype="multipart/form-data">
                    <div class="form-group">
                        <label for="inputFile">上传PPT</label>
                        <input type="file" id="inputFile" name="file" class="form-control">
                        <input type="submit" name="上传" class="btn btn-default"/>
                    </div>
                </form>
                <div class="panel panel-default">
                    <div class="panel-heading">
                        <h3 class="panel-title">文章编辑</h3>
                    </div>
                    <div class="panel-body">
                        <input type="hidden" id="id" value="${article.id}"/>
                        <div class="form-group">
                            <label for="title">标题</label>
                            <input type="text" id="title" value="${article.title}" class="form-control" style="width: 80%;"/>
                        </div>
                        <div class="form-group">
                            分类
                            <input type="radio" name="type" value="fileProgram"/>文件编程
                            <input type="radio" name="type" value="webProgram" />网络编程
                        </div>
                        <h4>内容</h4>
                        <script type="text/plain" id="myEditor"
                                style="width:80%;height:60%;">${article.content}</script>
                        <br>
                        <button class="btn btn-primary" onclick="sendContent()">发表</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<script type="text/javascript">
    $(window).load(function () {
        <c:if test="${message =='SUCCESS'}">
            alert('上传成功');
        </c:if>
        <c:if test="${message =='ERROR'}">
        alert('上传失败');
        </c:if>
        <c:if test="${message =='WARN'}">
        alert('只支持PPT格式');
        </c:if>
    });
</script>

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
        var types = document.getElementsByName("type");
        var type;
        var types = document.getElementsByName("type");
        for(var i=0;i<types.length;i++){
            if(types[i].checked){
                type=types[i].value;
                break;
            }
        }
        var content = UM.getEditor('myEditor').getContent().
                replace(/%/g, "%25").replace(/\&/g, "%26").replace(/\+/g, "%2B");
        xmlhttp.onreadystatechange = function () {
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
        xmlhttp.send("id=" + id + "&title=" + title +"&type="+type+ "&content=" + content);

    }
</script>
</body>
</html>
