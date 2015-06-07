<%--
  Created by IntelliJ IDEA.
  User: zl
  Date: 15-6-7
  Time: 上午11:21
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title></title>
    <link href="/resources/style/demo.css" rel="stylesheet" type="text/css"/>
    <script src="/resources/js/miniUI/boot.js" type="text/javascript"></script>
</head>
<body>
<h1>DataGrid 数据表格</h1>

<div style="width:800px;">
    <div class="mini-toolbar" style="border-bottom:0;padding:0px;">
        <table style="width:100%;">
            <tr>
                <td style="width:100%;">
                    <a class="mini-button" iconCls="icon-add" onclick="add()">增加</a>
                    <a class="mini-button" iconCls="icon-add" onclick="edit()">编辑</a>
                    <a class="mini-button" iconCls="icon-remove" onclick="remove()">删除</a>
                </td>
                <td style="white-space:nowrap;">
                    <input id="key" class="mini-textbox" emptyText="请输入姓名" style="width:150px;" onenter="onKeyEnter"/>
                    <a class="mini-button" onclick="search()">查询</a>
                </td>
            </tr>
        </table>
    </div>
</div>
<div id="datagrid1" class="mini-datagrid" style="width:800px;height:280px;" allowResize="true"
     url="/user/list.json" idField="id" multiSelect="true"
        >
    <div property="columns">
        <div field="nick" width="120" headerAlign="center" allowSort="true">昵称</div>
        <div field="name" width="120" headerAlign="center" allowSort="true">姓名</div>
        <div field="role" width="120" headerAlign="center" allowSort="true">角色</div>
    </div>
</div>


<script type="text/javascript">
    mini.parse();

    var grid = mini.get("datagrid1");
    grid.load();
    grid.sortBy("createtime", "desc");


    function add() {

        mini.open({
            url: "/resources/html/UserEdit.html",
            title: "新增员工", width: 600, height: 360,
            onload: function () {
                var iframe = this.getIFrameEl();
                var data = {action: "new"};
                iframe.contentWindow.SetData(data);
            },
            ondestroy: function (action) {

                grid.reload();
            }
        });
    }
    function edit() {

        var row = grid.getSelected();
        if (row) {
            mini.open({
                url: "/resources/html/UserEdit.html",
                title: "编辑员工", width: 600, height: 360,
                onload: function () {
                    var iframe = this.getIFrameEl();
                    var data = {action: "edit", id: row.id};
                    iframe.contentWindow.SetData(data);

                },
                ondestroy: function (action) {
                    grid.reload();

                }
            });

        } else {
            alert("请选中一条记录");
        }

    }
    function remove() {

        var rows = grid.getSelecteds();
        if (rows.length > 0) {
            if (confirm("确定删除选中记录？")) {
                var ids = [];
                for (var i = 0, l = rows.length; i < l; i++) {
                    var r = rows[i];
                    ids.push(r.id);
                }
                var id = ids.join(',');
                grid.loading("操作中，请稍后......");
                $.ajax({
                    url: "/user/delete.html?id=" + id,
                    success: function (text) {
                        grid.reload();
                    },
                    error: function () {
                    }
                });
            }
        } else {
            alert("请选中一条记录");
        }
    }
    function search() {
        var key = mini.get("key").getValue();
        grid.load({key: key});
    }
    function onKeyEnter(e) {
        search();
    }
    /////////////////////////////////////////////////
    function onBirthdayRenderer(e) {
        var value = e.value;
        if (value) return mini.formatDate(value, 'yyyy-MM-dd');
        return "";
    }
    function onMarriedRenderer(e) {
        if (e.value == 1) return "是";
        else return "否";
    }
    var Genders = [{id: 1, text: '男'}, {id: 2, text: '女'}];
    function onGenderRenderer(e) {
        for (var i = 0, l = Genders.length; i < l; i++) {
            var g = Genders[i];
            if (g.id == e.value) return g.text;
        }
        return "";
    }
</script>

</body>
</html>
