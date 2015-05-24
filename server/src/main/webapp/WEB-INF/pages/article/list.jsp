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
  <script type="text/javascript" src="<%=path%>/resources/js/bootstrap.min.js"></script>
  <script type="text/javascript" src="<%=path%>/resources/js/SimpleTree1.3/js/SimpleTree.js"></script>
  <link href="<%= path%>/resources/style/tree_themes/SimpleTree.css" rel="stylesheet" type="text/css" >
  <script type="text/javascript">
    var localObj = window.location;
    var contextPath = localObj.pathname.split("/")[1];
    var basePath = localObj.protocol + "//" + localObj.host + "/";
  </script>
  <script type="text/javascript">
    $(function($){

    });
    function doDelete(id){
      $.ajx({
        type: "DELETE",
        url: basePath+"/article/do.html",
        success: function (json) {
          alert(json);
        },
        error: function () {
          alert("删除失败");
        }
      });
    }
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
          <th>
            <a href="<%=path%>/article/edit.html"><button type="button" class="btn btn-primary">添加课程</button></a>
          </th>
          <th>
            创建时间
          </th>
          <th>
            操作
          </th>
        </tr>
        <c:forEach items="${articles}" var="a">
          <tr>
            <td><input name="title" type="checkbox" value="全选"/></td>
            <td><a href="<%=path%>/article/show.html?id=${a.id}">${a.title}</a></td>
            <td>${a.dateCreated}</td>
            <td>
              <div class="btn-group">
                <button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
                  操作
                  <span class="caret"></span>
                </button>

                <ul class="dropdown-menu">
                  <li>
                    <a target="mainView" href="<%=path%>/article/edit.html?id=${a.id}">编辑</a>
                  </li>
                  <li>
                    <a href="javascript:void(0);" onclick="doDelete(${a.id})">删除</a>
                  </li>
                </ul>
              </div>
            </td>
          </tr>
        </c:forEach>
      </table>
    </div>
    <div>
      <nav>
        <ul class="pagination">
          <li>
            <a href="#" aria-label="Previous">
              <span aria-hidden="true">&laquo;</span>
            </a>
          </li>
          <li><a href="#">1</a></li>
          <li><a href="#">2</a></li>
          <li><a href="#">3</a></li>
          <li><a href="#">4</a></li>
          <li><a href="#">5</a></li>
          <li>
            <a href="#" aria-label="Next">
              <span aria-hidden="true">&raquo;</span>
            </a>
          </li>
        </ul>
      </nav>
    </div>
  </div>
</body>
</html>
