<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: shouhutsh
  Date: 15-4-19
  Time: 下午9:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String path = request.getContextPath();
%>
<html>
<head>
    <title></title>
    <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
    <link href="<%=path%>/resources/bootstrap-3.3.4-dist/css/bootstrap.min.css">
</head>
<body>
<div class="container-fluid">
    <div class="row-fluid">
        <div class="span2">
        </div>
        <div class="span6">
        </div>
        <div class="span4">
        </div>
    </div>
</div>
<%--<table border="1">
    <c:forEach items="${catalogs}" var="c">
        <tr>
            <td>${c.name}</td>
        </tr>
    </c:forEach>
</table>--%>
</body>
</html>
