<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%
  String path = request.getContextPath();
%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title></title>
  <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
  <script type="text/javascript" src="<%=path%>/resources/js/bootstrap.min.js"></script>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css" rel="stylesheet"/>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css" rel="stylesheet"/>
</head>
<body>
<input id="id" value="${articleId}" hidden="hidden">
<textarea id="note" name="note" cols="60" rows="5"></textarea><br>
</body>
</html>
