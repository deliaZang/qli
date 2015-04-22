<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<%--
  Created by IntelliJ IDEA.
  User: shouhutsh
  Date: 15-4-12
  Time: 下午1:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title></title>
</head>
<body>

<table border="1">
    <tr>
        <th>ID</th>
        <th>标题</th>
        <th>内容</th>
    </tr>
    <c:forEach items="${articles}" var="a">
        <tr>
            <td>${a.id}</td>
            <td><a href="/article/update.html?id=${a.id}">${a.title}</a></td>
            <td>${a.content}</td>
        </tr>
    </c:forEach>

    <script type="text/javascript">
        function doDelete(id){
            var xmlhttp;
            if (window.XMLHttpRequest) {// code for IE7+, Firefox, Chrome, Opera, Safari
                xmlhttp = new XMLHttpRequest();
            }
            else {// code for IE6, IE5
                xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
            }

            xmlhttp.open("DELETE", "/article/doDelete.html", true);
            xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xmlhttp.send("id="+id);
        }
    </script>
</table>
</body>
</html>
