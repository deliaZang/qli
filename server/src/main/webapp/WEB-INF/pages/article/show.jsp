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
    <script type="text/javascript">
        $(function () {
            //获取评论列表
            $.ajax({
                type: "GET",
                url: "<%=path%>/comment/findByArticle.json?id=${article.id}",
                data: "json",
                dataType: "json",
                success: function (list) {
                    var i = 0;
                    for (var p in list) {
                        $("#commentList").append("<li>" + list[p].content + "</li>");
                    }
                }

            });
            $(".glyphicon-pencil").click(
                    function (event) {
                        var id = $(this).attr("id");
                        $("#noteModal").modal({
                            keyboard: false,
                            show: true
                        });
                    });

        });

        //获取评论数据
        function showComment() {
            $(".comment").show();
        }

        //保存评论
        function saveComment(id) {
            var comment = $("#comment").val();
            $.ajax({
                type: "POST",
                url: "<%=path%>/comment/save.html",
                data: {
                    id: id,
                    content: comment
                },
                success: function (json) {
                    if (json == "SUCCESS") {
                        alert("保存成功");
                    }
                    $(".comment").hide();
                }
            });
        }
        //保存笔记
        function saveNote(id) {
            var note = $("#note").val();
            $.ajax({
                type: "POST",
                url: "<%=path%>/note/save.html",
                data: {
                    id: id,
                    content: note
                },
                success: function (json) {
                    if (json == "SUCCESS") {
                        alert("保存成功");
                    }
                    $("#noteModal").on('hidden', function () {
                        $(this).removeData('modal');
                    });

                }
            });
        }
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
    </div>

    <!-- 基本内容-->
    <div class="panel panel-default">
        <div class="panel-heading">
            <h3 class="panel-title">
                课程内容
                <a class="btn" href="#noteModal" data-toggle="modal">
                    <i class="glyphicon glyphicon glyphicon-pencil" title="记笔记" style="margin-left: 80%;"
                       id="${article.id}"></i></a>

                <div class="note" hidden="hidden">

                    <button class="btn btn-primary" onclick="saveNote(${article.id})">保存</button>
                </div>
            </h3>
        </div>
        <div class="panel-body">
            ${article.content}
            </ol>
        </div>
        <div class="panel-footer">
            <a href="javascript:void(0);" onclick="showComment()">评论</a>

            <div class="comment" hidden="hidden">
                <textarea id="comment" name="comment" cols="60" rows="5"></textarea><br>
                <button class="btn btn-primary" onclick="saveComment(${article.id})">发表</button>
            </div>
            <div class="commentList">
                <span>所有评论</span>
                <ul id="commentList">

                </ul>
            </div>
        </div>
    </div>
</div>
<!-- 记笔记 -->
<div id="noteModal" class="modal hide fade" tabindex="-1"
     role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"
                aria-hidden="true">×
        </button>
        <h3 id="myModalLabel">记笔记</h3>
    </div>
    <div class="modal-body">

        内容<textarea id="note" name="note" cols="60" rows="5"></textarea>
    </div>
    <div class="modal-footer">
        <button class="btn" aria-hidden="true" onclick="saveNote(${article.id})">保存</button>
        <button class="btn" data-dismiss="modal" aria-hidden="true">保存</button>
    </div>
</div>
</body>
</html>
