<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <%@include file="../common/header.jsp" %>
    <script type="text/javascript">
        $(function () {
            /**获得最热门课程**/
            $.ajax({
                type: "GET",
                url: basePath + "article/hot.json",
                dataType: "json",
                success: function (list) {
                    var i = 0;
                    for (var p in list) {
                        $("#hot").append("<li><a target='mainView' href='<%=path%>/article/show.html?id=" + list[p].id + "'>" + list[p].title + "</a></li>");
                        i++;
                        if (i > 16) {
                            break;
                        }
                    }
                }
            });
            /**获得最新课程**/
            $.ajax({
                type: "GET",
                url: basePath + "article/lasted.json",
                dataType: "json",
                success: function (list) {
                    var i = 0;
                    for (var p in list) {
                        $("#lasted").append("<li><a target='mainView' href='<%=path%>/article/show?id=" + list[p].id + "'>" + list[p].title + "</a></li>");
                        i++;
                        if (i > 16) {
                            break;
                        }
                    }
                }
            });
        });
    </script>
</head>
<body>
<%@include file="../common/top.jsp" %>
<div class="container-fluid index_container">
    <div class="row-fluid" id="main">
        <div class="span12">
            <div class="row-fluid">
                <div class="row">
                    <div id="listDiv1">
                        <!--最热 -->
                        <div class="panel panel-info col-md-6 hot" style="float: left;">
                            <div class="panel-heading">
                                <h3 class="panel-title con_title">最热课程</h3>
                            </div>
                            <div class="panel-body">
                                <ul id="hot">
                                </ul>
                            </div>
                        </div>

                        <!--最新 -->
                        <div class="panel panel-info col-md-6 new" style="float: right;">
                            <div class="panel-heading">
                                <h3 class="panel-title con_title">最新课程</h3>
                            </div>
                            <div class="panel-body">
                                <ul id="lasted">
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<%@include file="../common/foot.jsp" %>
</body>
</html>