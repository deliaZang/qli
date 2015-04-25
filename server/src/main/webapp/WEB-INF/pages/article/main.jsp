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
        $(function(){
            //加载树状菜单
            $(".st_tree").SimpleTree({
                click: function (a) {
                    if (!$(a).attr("hasChild"))
                        alert($(a).attr("ref"));
                }
            });
            $.ajax({
                type:"GET",
                url:basePath+"article/hot.json",
                dataType:"json",
                success: function(list){
                    debugger;
                    var i = 0;
                    for(var p in list){
                        $("#hot").append("<li><a class='hotli' href='<%=path%>/article/show.html?id="+list[p].id+"'>"+ list[p].title+"</a></li>");
                        i++;
                        if(i>9){
                            break;
                        }
                    }
                }
            });

            $.ajax({
                type:"GET",
                url:basePath+"article/lasted.json",
                dataType:"json",
                success: function(list){
                    var i = 0;
                    for(var p in list){
                        $("#lasted").append("<li><a class='lastedli' href='<%=path%>/article/show?id="+list[p].id+"'>"+ list[p].title+"</a></li>");
                        i++;
                        if(i>9){
                            break;
                        }
                    }
                }
            });

        });

        //删除
        function doDelete(id) {
            $.ajx({
                type: "POST",
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
<div class="col-md-12 column">
    <div class="row clearfix">
        <div class="col-md-3 column"  style="flow:right;">

            <div class="st_tree">
                <ul>
                    <li><a href="#" ref="hyjm">linux课程</a></li>
                    <li><a href="#" ref="xtgl">系统编程</a></li>
                        <ul show="true">
                            <li><a href="#" ref="yhgl">用户管理</a></li>
                            <li><a href="#" ref="rzck">日志查看</a></li>
                        </ul>
                    <li><a href="#" ref="ckgl">网络编程</a></li>
                        <ul>
                            <li><a href="#" ref="kcgl">库存管理</a></li>
                            <li><a href="#" ref="shgl">收货管理</a></li>
                            <li><a href="#" ref="fhgl">发货管理</a></li>
                            <ul>
                                <li><a href="#" ref="yhgl">用户管理</a></li>
                                <li><a href="#" ref="rzck">日志查看</a></li>
                            </ul>
                        </ul>
                </ul>
            </div>

        </div>
        <div class="col-md-9 column">

            <div id="listDiv" >
                <!--最热 -->
                <div class="hot" style="width:60%;height:30%;border: dashed;">
                    最热课程
                    <ul id="hot">
                    </ul>
                </div>
                <!--最新 -->
                <div class="latest" style="width:60%;height:30%;border: dotted;" >
                    最新课程
                    <ul id="lasted">
                    </ul>
                </div>
            </div>
            <div id="detailDiv" hidden="hidden">
                <iframe name="mainView" style="border:none; width: 100%; height: 600px; float: inherit;margin-right: 10px;">

                </iframe>
            </div>


        </div>
    </div>
</div>

</body>
</html>
