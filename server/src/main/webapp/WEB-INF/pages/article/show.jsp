<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %><%
  String path = request.getContextPath();
%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title></title>
  <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css"  rel="stylesheet"/>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css"  rel="stylesheet"/>
  <script type="text/javascript" src="<%=path%>/resources/js/bootstrap.min.js"></script>
  <script type="text/javascript">
    var localObj = window.location;
    var contextPath = localObj.pathname.split("/")[1];
    var basePath = localObj.protocol + "//" + localObj.host + "/";
  </script>
  <script type="text/javascript">

  </script>
</head>
<body>
  <div class="container-fluid">
    <div class="row-fluid">
      <!-- 目录-->
      <div class="panel panel-default">
        <div class="panel-heading">
          <h3 class="panel-title">目录</h3>
        </div>
        <div class="panel-body">
          <ol>
            <c:forEach items="${article.catalogs}" var="c">
              <li>
                <a href="#${c.flag}">${c.name}</a>
              </li>
            </c:forEach>
          </ol>
        </div>
      </div>
      <!-- 基本内容-->

    </div>
  </div>
</body>
</html>
