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
<form action="<%=path%>/user/upload.html" method="post" enctype="multipart/form-data">
  选择文件:<input type="file" name="file">
  <input type="submit" value="提交">
</form>
</body>
</html>
