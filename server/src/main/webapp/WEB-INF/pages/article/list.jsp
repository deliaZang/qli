<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<%
  String path = request.getContextPath();
%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title></title>
  <script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css"  rel="stylesheet"/>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css"  rel="stylesheet"/>
  <script type="text/javascript" src="<%=path%>/resources/js/SimpleTree1.3/js/SimpleTree.js"></script>
  <link href="<%= path%>/resources/style/tree_themes/SimpleTree.css" rel="stylesheet" type="text/css" >
  <script type="text/javascript">
    var localObj = window.location;
    var contextPath = localObj.pathname.split("/")[1];
    var basePath = localObj.protocol + "//" + localObj.host + "/";
  </script>
  <script type="text/javascript">

  </script>
</head>
<body>
  <div class="container-fluid" align="center">
    <div class="row-fluid">
      <!-- 目录-->
      <table class="table">
        <tr>
          <th>
            <input name="selectAll" type="checkbox" value="全选"/>
          </th>
          <th colspan="2">
            <a href="<%=path%>/article/edit.jsp"><button type="button" class="btn btn-primary">添加课程</button></a>
          </th>
          <th>
            创建时间
          </th>
        </tr>
        <c:forEach items="${article}" var="a">
          <td>
            <tr><input name="title" type="checkbox"/></tr>
            <tr><a href="#${a.title}">${a.title}</a></tr>
            <tr>${a.dateCreated}</tr>
            <tr>
              <div class="btn-group">
                <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
                  <a href="javascript:void(0);"> 编辑</a> <span class="caret"></span>
                </button>
                <ul class="dropdown-menu" role="menu">
                  <li><a href="javascript:void(0);">删除</a></li>
                  <li><a href="#">修改分类</a></li>
                </ul>
              </div>
            </tr>
          </td>
        </c:forEach>
      </table>
    </div>
  </div>
</body>
</html>
