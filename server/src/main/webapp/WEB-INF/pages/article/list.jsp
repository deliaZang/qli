<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>目录</title>
    <%@include file="../common/header.jsp" %>
    <script type="text/javascript" src="<%=path%>/resources/js/bootstrap-modal.js"></script>
    <script type="text/javascript">
        $(function ($) {

            /* 全选 */
            $("#selectAll").click(
                    function () {
                        $("input[name=articleId][type=checkbox]").each(function () {
                            $(this).prop("checked",
                                    $("#selectAll").prop("checked"));
                        });
                    });

            $("a[href='<%=path%>/article/list.html?pageIndex=${counter}']").parent().addClass("bright");
        });
        //删除
        function doDelete(id) {
            if (window.confirm("确认要删除吗?")) {
                $.ajax({
                    type: "post",
                    url: "<%=path%>/article/delete.html",
                    data: {id: id},
                    success: function (json) {
                        if (json == 'SUCCESS') {
                            alert('删除成功');
                        }

                    },
                    error: function () {
                        alert("删除失败");
                    }
                });
            }
        }

        //批量删除
        function deleteBatch() {
            var checkObjects = $("input[name='articleId'][type='checkbox']:checked");
            var checkedNum = checkObjects.length;
            if (checkedNum != 0) {
                if (window.confirm("确认要全部删除吗?")) {
                    var ids = new Array();
                    for(var i = 0 ; i<checkedNum ; i++){
                        ids[i] = checkObjects[i].value;
                    }

                    $.ajax({
                        type: "post",
                        url: "<%=path%>/article/deleteBatch.html",
                        data: {ids: ids},
                        success: function (json) {
                            if (json == 'SUCCESS') {
                                alert('删除成功');
                            }

                        },
                        error: function () {
                            alert("删除失败");
                        }
                    });
                    return true;
                }
            }
            else {
                alert("未选中任何项,请至少选择一项");
            }
            return false;

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
<%@include file="../common/top.jsp" %>
<div class="container-fluid index_container">
    <div class="panel panel-default" style="height: 57px;width: 1019px;margin: 0 auto 20px;">
        <c:if test="${user.role == 'teacher'}">
            <div class="panel-heading" style="float: left;">
                <a>
                    <button type="button" class="btn btn-primary" onclick="deleteBatch()">批量删除</button>
                </a>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <a href="<%=path%>/article/edit.html">
                    <button type="button" class="btn btn-primary">添加课程</button>
                </a>
            </div>
        </c:if>
    </div>

    <div class="row-fluid" style="width: 1019px;margin: 0 auto;">
        <!-- 目录-->
        <table class="table">
            <tr>
                <th>
                    <input id="selectAll" name="selectAll" type="checkbox"/>全选
                </th>
                <th>
                    标题
                </th>
                <th>
                    创建时间
                </th>
                <c:if test="${user.role == 'teacher'}">
                    <th>
                        操作
                    </th>
                </c:if>
            </tr>
            <c:forEach items="${page.content}" var="a">
                <tr>
                    <td><input name="articleId" id="articleId" type="checkbox" value="${a.id}"/></td>
                    <td><a href="<%=path%>/article/show.html?id=${a.id}">${a.title}</a></td>
                    <td>${a.dateCreated}</td>
                    <c:if test="${user.role == 'teacher'}">
                        <td>
                            <div class="btn-group">
                                <button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown"
                                        aria-expanded="false">
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
                    </c:if>
                </tr>
            </c:forEach>
        </table>
    </div>
    <div>
        <nav style="height: 65px;text-align: center;">
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
                        <li><a href="<%=path%>/article/list.html?pageIndex=${counter}">${counter}</a></li>
                    </c:forEach>
                </c:if>
                <!--如果总页数不小于6,而且当前页比总页数小3-->
                <c:if test="${page.totalPages >=6 and page.totalPages-page.number>4}">
                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.number+1}">${page.number+1}</a></li>
                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.number+2}">${page.number+2}</a></li>
                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.number+3}">${page.number+3}</a></li>
                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.number+4}">${page.number+4}</a></li>

                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.totalPages}"
                           aria-label="Next">...${page.totalPages}</a></li>
                </c:if>
                <!--如果总页数不小于6-->
                <c:if test="${page.totalPages >=6 and page.totalPages-page.number<=4}">
                    <li><a href="<%=path%>/article/list.html?pageIndex=1">1...</a></li>
                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.totalPages-3}">${page.totalPages-3}</a>
                    </li>
                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.totalPages-2}">${page.totalPages-2}</a>
                    </li>
                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.totalPages-1}">${page.totalPages-1}</a>
                    </li>

                    <li><a href="<%=path%>/article/list.html?pageIndex=${page.totalPages}"
                           aria-label="Next">${page.totalPages}</a></li>
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
<%@include file="../common/foot.jsp" %>
</body>
</html>
