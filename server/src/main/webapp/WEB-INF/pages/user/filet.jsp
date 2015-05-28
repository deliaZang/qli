<%

  String path = request.getContextPath();

%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>文件上传</title>
</head>
<body>
${fileUrl}
<form action="<%=path%>/article/fileUp.do" method="post" enctype="multipart/form-data">
    <div class="form-group">
        上传PPT
        <input type="file"  name="file" class="form-control">
        <input type="submit" name="上传" class="btn btn-default"/>
    </div>
</form>
</body>
</html>
