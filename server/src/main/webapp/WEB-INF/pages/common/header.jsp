<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%
    String path = request.getContextPath();
%>
<script type="text/javascript" src="<%=path%>/resources/js/jquery-1.11.2.min.js"></script>
<script type="text/javascript" src="<%=path%>/resources/js/bootstrap.min.js"></script>
<link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap.css" rel="stylesheet"/>
<link href="<%=path%>/resources/style/bootstrap-3.3.4-dist/css/bootstrap-theme.css" rel="stylesheet"/>
<script type="text/javascript" src="<%=path%>/resources/js/SimpleTree1.3/js/SimpleTree.js"></script>
<link href="<%= path%>/resources/style/tree_themes/SimpleTree.css" rel="stylesheet" type="text/css">
<link href="<%=path%>/resources/style/css.css" rel="stylesheet"/>
<script type="text/javascript" src="<%=path%>/resources/js/jquery.validate.js"></script>
<script type="text/javascript" src="<%=path%>/resources/js/messages_zh.js"></script>
<script type="text/javascript">
    var localObj = window.location;
    var contextPath = localObj.pathname.split("/")[1];
    var basePath = localObj.protocol + "//" + localObj.host + "/";
</script>
