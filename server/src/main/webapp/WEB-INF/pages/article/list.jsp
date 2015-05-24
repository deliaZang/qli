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
  <script type="text/javascript" src="<%=path%>/resources/js/bootstrap.min.js"></script>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css"  rel="stylesheet"/>
  <link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css"  rel="stylesheet"/>
  <script type="text/javascript">
    var localObj = window.location;
    var contextPath = localObj.pathname.split("/")[1];
    var basePath = localObj.protocol + "//" + localObj.host + "/";
  </script>
  <script type="text/javascript">
    $(function($){
      $("a[href='<%=path%>/article/list.html?pageIndex=${counter}']").parent().addClass("bright");
    });
    function doDelete(id){
      $.ajax({
        type: "post",
        url: "<%=path%>/article/delete.html",
        data:{id:id},
        success: function (json) {
          alert(json);

        },
        error: function () {
          alert("删除失败");
        }
      });
    }
  </script>
  <style type="text/css">
    .bright {
      font-weight: bolder;
      font-style: italic;
    }
  </style>
</head>
<body>
  <div class="container-fluid" align="center">
    <div class="row-fluid" style="height:45%">
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
        <c:forEach items="${page.content}" var="a">
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
        总共${page.totalElements}条
        总共${page.totalPages}页
        当前页${page.number+1}

        <ul class="pagination">
          <!--如果是第一页-->
          <c:if test="${page.number == 0}">
            <li>
              <a href="javascript:void(0)" aria-label="Previous" title="第一页">
                <span aria-hidden="true">&laquo;</span>
              </a>
            </li>
          </c:if>
          <!--如果不是第一页-->
          <c:if test="${page.number > 0}">
            <li>
              <a href="<%=path%>/article/list.html?pageIndex=${page.number}" aria-label="Previous">
                <span aria-hidden="true">&laquo;</span>
              </a>
            </li>
          </c:if>
          <!--如果总页数小于6-->
          <c:if test="${page.totalPages < 6}">
            <c:forEach var="counter" begin="1" end="${page.totalPages}">
              <li> <a href="<%=path%>/article/list.html?pageIndex=${counter}">${counter}</a></li>
            </c:forEach>
          </c:if>
          <!--如果总页数不小于6,而且当前页比总页数小3-->
          <c:if test="${page.totalPages >=6 and page.totalPages-page.number>4}">
            <li> <a href="<%=path%>/article/list.html?pageIndex=${page.number+1}">${page.number+1}</a></li>
            <li> <a href="<%=path%>/article/list.html?pageIndex=${page.number+2}">${page.number+2}</a></li>
            <li> <a href="<%=path%>/article/list.html?pageIndex=${page.number+3}">${page.number+3}</a></li>
            <li> <a href="<%=path%>/article/list.html?pageIndex=${page.number+4}">${page.number+4}</a></li>

            <li><a href="<%=path%>/article/list.html?pageIndex=${page.totalPages}" aria-label="Next">...${page.totalPages}</a></li>
          </c:if>
          <!--如果总页数不小于6-->
          <c:if test="${page.totalPages >=6 and page.totalPages-page.number<=4}">
            <li> <a href="<%=path%>/article/list.html?pageIndex=1">1...</a></li>
            <li> <a href="<%=path%>/article/list.html?pageIndex=${page.totalPages-3}">${page.totalPages-3}</a></li>
            <li> <a href="<%=path%>/article/list.html?pageIndex=${page.totalPages-2}">${page.totalPages-2}</a></li>
            <li> <a href="<%=path%>/article/list.html?pageIndex=${page.totalPages-1}">${page.totalPages-1}</a></li>

            <li><a href="<%=path%>/article/list.html?pageIndex=${page.totalPages}" aria-label="Next">${page.totalPages}</a></li>
          </c:if>

          <c:if test="${page.number+1 >= page.totalPages}">
            <li>
              <a href="javascript:void(0)" aria-label="Next" title="最后一页">
                <span aria-hidden="true">&raquo;</span>
              </a>
            </li>
          </c:if>
          <c:if test="${page.number+1 < page.totalPages}">
            <li>
              <a href="<%=path%>/article/list.html?pageIndex=${page.totalPages}" aria-label="Next">
                <span aria-hidden="true">&raquo;</span>
              </a>
            </li>
          </c:if>
        </ul>
      </nav>
    </div>
  </div>
</body>
</html>
