<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>课程详情</title>
    <%@include file="../common/header.jsp" %>
    <script type="text/javascript">
        $(function () {
            //获取评论列表
            getComment();
        });
        //获取评论列表
        function getComment() {
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
        }
        //获取评论数据
        function showComment() {
            $(".comment").show();
        }

        //保存评论
        function saveComment(id) {
            var comment = $("#comment").val();
            $.ajax({
                type: "GET",
                url: "<%=path%>/comment/save.html",
                data: {
                    id: id,
                    content: comment
                },
                success: function (json) {
                    if (json == "SUCCESS") {
                        alert("保存成功");
                    }
                    //刷新评论列表
                    getComment();
                    $(".comment").hide();
                }
            });
        }
        //保存笔记
        function saveNote(id) {
            var title = $("#title").val();
            var note = $("#note").val();
            $.ajax({
                type: "POST",
                url: "<%=path%>/note/save.html",
                data: {
                    id: id,
                    title:title,
                    content: note
                },
                success: function (json) {
                    if (json == "SUCCESS") {
                        alert("保存成功");
                    }
/*
                    $("#myModal").modal('hide');
*/
                    $("#title").val("");
                    $("#note").val("");
                }
            });
        }
    </script>
    <style>
        #modal{
            position:absolute;
            left:0px;
            top:0px;
            z-index: 100px;
        }
        .modal-body{
            height: 200px;
        }
    </style>
</head>
<body>
<%@include file="../common/top.jsp"%>
<div class="container-fluid index_container">
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
                <a class="btn" href="#myModal" data-toggle="modal"  style="margin-left: 80%;">
                    <i class="glyphicon glyphicon glyphicon-pencil" title="记笔记" id="${article.id}"></i>
                </a>
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
<!-- 记笔记的模态框 -->
<div id="modal" class="index_container">
    <div class="modal fade" id="myModal" tabindex="-1" data-backdrop="false" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span
                            aria-hidden="true">&times;</span></button>
                    <h4 class="modal-title" id="myModalLabel">记笔记</h4>
                </div>
                <div class="modal-body">
                    <form class="form-horizontal">
                        <div class="form-group">
                            <label for="title" class="col-sm-2 control-label">标题</label>
                            <div class="col-sm-10">
                                <input type="text" class="form-control" id="title">
                            </div>
                        </div>
                        <div class="form-group">
                            <label for="note" class="col-sm-2 control-label">内容</label>
                            <div class="col-sm-10">
                                <textarea class="form-control" rows="6" id="note"></textarea>
                            </div>
                        </div>
                    </form>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-primary" onclick="saveNote(${article.id})">保存</button>
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
                </div>
            </div>
        </div>
    </div>
</div>
<%@include file="../common/foot.jsp"%>
</body>
</html>
