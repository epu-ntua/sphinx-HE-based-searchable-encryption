<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>




<style type="text/css">
.background-img {
	position: absolute;
	right: 10px;
	bottom: 10px
}

div {
	text-align: center;
}
</style>

</head>
<body>
	<!--  <p style="text-align: center">
		<img
			src="C:\Users\Zahra\Desktop\Eclipse-for-network\Workspace\Red-Alert\logo.jpg" />
	</p>
-->
	<br />
	<Strong><font size="8"> Homomorphic Encryption </font></Strong>
	<br />
	<Strong><font size="3"> Encryption </font></Strong>
	<br /> Use this link to Encrypt all incoming files.
	<br />
	<center>
		
		
		
				
	 	<form method="post" action="Encryption" enctype="multipart/form-data" name="form1" id="form1">
			Select a file: <input type="file" name="file" accept=".txt" id="file" multiple/>
 <input name="submit" type="submit" value="Encrypt" />
			<%
				String login_msge = (String) request.getAttribute("messa");
			//   out.println("<font color=red size=4px>" + login_msge+ "</font>");
				//if (login_msg != null)
				if (login_msge == "Invalid") {
					out.println("<font color=red size=4px>" + "Invalid File/Folder" + login_msge+ "</font>");
				}
				if (login_msge == "Valid") {
					out.println("<font color=red size=4px>" + "File Successfully Encrypted" + "</font>");
				}
				//	else
				//		{out.println("<font color=red size=4px>" + "Cool you are there" + "</font>");}
			%>
		</form>   
		<br />
	<div id="clickk">  <a href="DownloadServlet1">Download the Encrypted Data</a></div>
		</center>
<br />
	<Strong><font size="3"> Upload </font></Strong>
	<br /> Use this link to upload files
		<center>
	
<!-- 		<form action="http://localhost:8080/uploadFile" method="post" enctype="multipart/form-data">
		<br />
		<label for="file"> Select a file:</label>
		<input type="file" name="file" multiple id="file"/> <br>
		<br />
		<input type="submit" value="upload">
		
		</form>
 -->
 
 <form id='file-catcher'>
 <br />
		<label for="file"> Select a file:</label>
  <input id='file-input' type='file' multiple/>
 <button type='submit'>
    Submit
  </button>
</form>

<div id='file-list-display'></div>
<script>
 (function () {
	var fileCatcher = document.getElementById('file-catcher');
  var fileInput = document.getElementById('file-input');
  var fileListDisplay = document.getElementById('file-list-display');
  
  var fileList = [];
  var renderFileList, sendFile;
  
  fileCatcher.addEventListener('submit', function (evnt) {
  	evnt.preventDefault();
    fileList.forEach(function (file) {
    	sendFile(file);
    });
  });
  
  fileInput.addEventListener('change', function (evnt) {
 		fileList = [];
  	for (var i = 0; i < fileInput.files.length; i++) {
    	fileList.push(fileInput.files[i]);
    }
    renderFileList();
  });
  
  renderFileList = function () {
  	fileListDisplay.innerHTML = '';
    fileList.forEach(function (file, index) {
    	var fileDisplayEl = document.createElement('p');
      fileDisplayEl.innerHTML = (index + 1) + ': ' + file.name;
      fileListDisplay.appendChild(fileDisplayEl);
    });
  };
  
  sendFile = function (file) {
  	var formData = new FormData();
    var request = new XMLHttpRequest();
 
    formData.set('file', file);
    request.open("POST", 'https:/fortika-he-component.xlab.si/uploadFile');
    request.send(formData);
  };
})();
</script> 
 
	</center>

	<div id="background-img" class="background-img">
		<img
			src="FortikaLogo.jpg"
			width="140" height="90" />
	</div>


	<hr />
	<hr />
	<Strong><font size="3"> Search </font></Strong>
	<br /> Enter the Keyword that you need to search
	<center>
	<form method="post" action="SearchFormation">
  Enter Keyword:
  <input type="text" name="firstname" >
  <input type="submit" value="Submit">
  <br />
  			<%
			//requestt.setAttribute("messaa","Valid");
				String login_msge21 = (String) request.getAttribute("messaa");
				//requestt.setAttribute("responseData", resp);
				String ResponseMessage = (String) request.getAttribute("responseData");
				//if (login_msg != null)
				if (login_msge21 == "Invalid") {
					out.println("<font color=red size=4px>" + "No Files found having this search request" + "</font>" );
				}
				if (login_msge21 == "Valid") {
					out.println("<font color=red size=4px>" + "The Search was conducted Successfully and resulted in:" + "</font>");
									
				//	out.println("<font color=red size=4px>" + ResponseMessage + "</font>");
				}
				//	else
				//		{out.println("<font color=red size=4px>" + "Cool you are there" + "</font>");}
			%>
			<br />
		<%	if (login_msge21 == "Valid") {
								
					out.println("<font color=red size=4px>" + ResponseMessage + "</font>");
				}   %>
</form> 
</center>
	
	
	<hr />
	<hr />
	
	<Strong><font size="3"> Download </font></Strong>
	<br /> Enter the file name that you need to be downloaded
	<center>
	
	<form id = "your_form" onsubmit="yourFunction()">
  <label>File name:  <input type="text" name="keywords">
    <input type="submit" value="Download">
</form>

<script type="text/javascript">
 function yourFunction(){
    var action_src = "https:/fortika-he-component.xlab.si/downloadFile/" + document.getElementsByName("keywords")[0].value;
    var your_form = document.getElementById('your_form');
    your_form.action = action_src ;
}
 </script>

	</center>

<Strong><font size="3"> Decrypt </font></Strong>
	<br /> Select the files that you want to decrypt
	<center>
	
		<form method="post" action="upload2" enctype="multipart/form-data" name="form1" id="form1">
			Select a file: <input type="file" name="file" accept=".txt" id="file" multiple/>
 <input name="submit" type="submit" value="Decrypt" />
			<%
				String login_msgeee = (String) request.getAttribute("messa212");
			//   out.println("<font color=red size=4px>" + login_msge+ "</font>");
				//if (login_mseeg != null)
				if (login_msgeee == "Invalid") {
					out.println("<font color=red size=4px>" + "Invalid File/Folder" + login_msge+ "</font>");
				}
				if (login_msgeee == "Valid") {
					out.println("<font color=red size=4px>" + "File Successfully Decrypted" + "</font>");
				}
				//	else
				//		{out.println("<font color=red size=4px>" + "Cool you are there" + "</font>");}
			%>
		</form>   
<br />
	<div id="clickk">  <a href="DownloadServlet12">Download the Decrypted Data</a></div>

</body>

</html>