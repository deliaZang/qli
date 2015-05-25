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
    <script type="text/javascript">
        var localObj = window.location;
        var contextPath = localObj.pathname.split("/")[1];
        var basePath = localObj.protocol + "//" + localObj.host + "/";
    </script>
    <script type="text/javascript">
        $(function(){
            /**获得最热门课程**/
            $.ajax({
                type:"GET",
                url:basePath+"article/hot.json",
                dataType:"json",
                success: function(list){
                    var i = 0;
                    for(var p in list){
                        $("#hot").append("<li><a target='mainView' href='<%=path%>/article/show.html?id="+list[p].id+"'>"+ list[p].title+"</a></li>");
                        i++;
                        if(i>9){
                            break;
                        }
                    }
                }
            });
            /**获得最新课程**/
            $.ajax({
                type:"GET",
                url:basePath+"article/lasted.json",
                dataType:"json",
                success: function(list){
                    var i = 0;
                    for(var p in list){
                        $("#lasted").append("<li><a target='mainView' href='<%=path%>/article/show?id="+list[p].id+"'>"+ list[p].title+"</a></li>");
                        i++;
                        if(i>9){
                            break;
                        }
                    }
                }
            });
            /**获得文件课程**/
            $.ajax({
                type:"GET",
                url:basePath+"article/file.json",
                dataType:"json",
                success: function(list){
                    var i = 0;
                    for(var p in list){
                        $("#fileProgram").append("<li><a target='mainView' href='<%=path%>/article/show?id="+list[p].id+"'>"+ list[p].title+"</a></li>");
                        i++;
                        if(i>9){
                            break;
                        }
                    }
                }
            });
            /**获得网络课程**/
            $.ajax({
                type:"GET",
                url:basePath+"article/web.json",
                dataType:"json",
                success: function(list){
                    var i = 0;
                    for(var p in list){
                        $("#webProgram").append("<li><a target='mainView' href='<%=path%>/article/show?id="+list[p].id+"'>"+ list[p].title+"</a></li>");
                        i++;
                        if(i>9){
                            break;
                        }
                    }
                }
            });

        });
    </script>
</head>
<body>
    <div class="clearfix">
        <div class="container-fluid">
            <div class="row-fluid">
                <div class="row">
                    <div id="listDiv1">
                        <!--最热 -->
                        <div class="panel panel-info col-md-6" style="float: left;">
                            <div class="panel-heading">
                                <h3 class="panel-title">最热课程</h3>
                            </div>
                            <div class="panel-body">
                                <ul id="hot">
                                </ul>
                            </div>
                        </div>

                        <!--最新 -->
                        <div class="panel panel-info col-md-6" style="float: right;">
                            <div class="panel-heading">
                                <h3 class="panel-title">最新课程</h3>
                            </div>
                            <div class="panel-body">
                                <ul id="lasted">
                                </ul>
                            </div>
                        </div>
</div>
                    <div id="listDiv2">
                        <!--分类-->
                        <div class="panel panel-info col-md-12">
                            <div class="panel-heading">
                                <h3 class="panel-title">课程分类</h3>
                            </div>
                            <div class="panel-body">
                                <!--文件编程-->
                                <div class="panel panel-info col-md-6" style="float: left;">
                                    <h3 class="panel-title">文件编程</h3>
                                    <div class="panel-body">
                                        <ul id="fileProgram">
                                        </ul>
                                    </div>
                                </div>

                                <!--网络编程-->
                                <div class="panel panel-info col-md-6" style="float: right;">
                                    <h3 class="panel-title">网络编程</h3>
                                    <div class="panel-body">
                                        <ul id="webProgram">
                                        </ul>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>
</html>
