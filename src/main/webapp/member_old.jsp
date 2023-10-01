<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Anonymizer</title>

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
			src="logo1.jpg" />
	</p>
-->

	<br />
	<Strong><font size="8"> User Privacy </font></Strong>
	<br />
	<Strong><font size="3"> Anonymization </font></Strong>
	<br /> The General Data Protection Regulation (GDPR) aims at ensuring a
	consistent level of protection for persons throughout the European
	Union. To ensure user identity/data privacy kindly anonymize the available dataset using the following link:(Note: you can only anonymize a .json file format)
	<br />
	<center>
		<form method="post" action="upload" enctype="multipart/form-data">
			Select file to upload: <input type="file" name="file" accept=".json"/> 
		
			
		 <input name="submit" type="submit" value="Upload" />
			

			
			
			<%
				String login_msge = (String) request.getAttribute("messa");
			//   out.println("<font color=red size=4px>" + login_msge+ "</font>");
				//if (login_msg != null)
				if (login_msge == "Invalid") {
					out.println("<font color=red size=4px>" + "Invalid File/Folder" + login_msge+ "</font>");
				}
				if (login_msge == "Valid") {
					out.println("<font color=red size=4px>" + "File Successfully Uploaded" + "</font>");
				}
				//	else
				//		{out.println("<font color=red size=4px>" + "Cool you are there" + "</font>");}
				String fileName=(String) request.getAttribute("namee");
				
			%>
		</form>
		
	</center>
<br/>
<center>
<form method="post" action="anony">
					Use the following checkboxes to select level of Anonymization (Note: Node-id will always be anonymized by this tool): <br>

<input type="checkbox" name="location" value="On" checked="checked"/> Location 
<input type="checkbox" name="Images" value="On" checked="checked"/> Images 

<br> <INPUT TYPE=submit name=submit Value="Anonymize">

<% 
				session.setAttribute("file_name",fileName);
				String login_msgeee = (String) request.getAttribute("messaa");
			//   out.println("<font color=red size=4px>" + login_msge+ "</font>");
				//if (login_msg != null)
				if (login_msgeee == "Invalid") {
					out.println("<font color=red size=4px>" + "Invalid File/Folder</font>");
				}
				if (login_msgeee == "Valid") {
					out.println("<font color=red size=4px>" + "File Successfully Anonymized" + "</font>");
				}
				//	else
				//		{out.println("<font color=red size=4px>" + "Cool you are there" + "</font>");}

			%>


</form>
<a href="DownloadServlet">Click to Download the Anonymized file</a>
</center>




	<div id="background-img" class="background-img">
		<img
			src="logo.jpg"
			width="140" height="90" />
	</div>

	<Strong><font size="3"> Encryption </font></Strong>
	<br /> Once terrorists have been identified, the list of these
	individuals needs to be uploaded on the server to enable LEAs from
	different geographical location to search in this list. Kindly use the
	bellow button to select and encrypt the desired list.
	<center>
		<form method="post" action="upload2" enctype="multipart/form-data">
			Select file to upload: <input type="file" name="file" accept=".json" />
			<br />
			<br /> <input name="submit" type="submit" value="Encrypt" />
			<%
				String login_msge2 = (String) request.getAttribute("messa2");

				//if (login_msg != null)
				if (login_msge2 == "Invalid") {
					out.println("<font color=red size=4px>" + "Invalid File/Folder" + "</font>");
				}
				if (login_msge2 == "Valid") {
					out.println("<font color=red size=4px>" + "File Successfully Encrypted" + "</font>");
				}
				//	else
				//		{out.println("<font color=red size=4px>" + "Cool you are there" + "</font>");}
			%>
		</form>
	</center>

	<hr />
	<hr />

	<Strong><font size="6"> Limited Access </font></Strong>
	<br /> The next available options on this page require special access.
	Kindly login again:

<%!
public String myString="Validi";
%>

	<div>

		<form method="post" action="Authenticate">
			<table class="box">

				<tr bgcolor="white">
					<td><strong>User Name</strong></td>
					<td><input type="text" name="unamee" id="unamee"></td>
				</tr>

				<tr bgcolor="white">
					<td><strong>Password</strong></td>
					<td><input type="password" name="passworde"></td>
				</tr>

				<tr>
					<td></td>
					<td><strong><input type="submit" value="login"></strong></td>
					<%
						String login_msg = "cool";
						login_msg = (String) request.getAttribute("error");

						//if (login_msg != null)
						if (login_msg == "Invalid") {
							out.println("<font color=red size=4px>" + "Invalid Username or Password" + "</font>");
							myString="Invalid";
						}
						if (login_msg == "Valid") {

							out.println("<font color=red size=4px>" + "Logged In" + "</font>");
							myString="Valid";
						}
						//	else
						//		{out.println("<font color=red size=4px>" + "Cool you are there" + "</font>");}
					%>
				</tr>

			</table>
		</form>
	</div>




	<Strong><font size="3"> Search in the Anonymized data </font></Strong>
	<br /> You can search in the anonymized dataset for the true UserId of
	an individual. Kindly, input the specific ID value that you need to
	check against. In case of multiple IDs, separate each ID with a comma. (example id1,id2,id3)
	<center>
		<form name="frm" method="post" action="textInput">
			<table>
				<tr>
					<td>Enter the ID that you want to search against:</td>
					<td><input type="text" name="surrogateId"></td>
					<td>&nbsp;</td>
					<td><input type="submit" id="submit_button" name="submit"
						value="Submit"></td>

					<%
						session.setAttribute("login_msg", myString);
									String login_msg2 = "cool";
									login_msg2 = (String) request.getAttribute("output");

									if (login_msg2 != null) {
										out.println("<font color=red size=4px>" + login_msg2 + "</font>");
									}
					%>
				</tr>
			</table>
		</form>
	</center>

	<Strong><font size="3"> Search in the Encrypted data </font></Strong>
	<br /> You can search in the Encrypted dataset for the true UserId of
	an individual. Kindly, input the specific ID value that you need to
	check against.
	<center>
		<form name="frm" method="post" action="textInput2">
			<table>
				<tr>
					<td>Enter the ID that you want to search against:</td>
					<td><input type="text" name="surrogateIdd"></td>

					<td>&nbsp;</td>
					<td><input type="submit" name="submitt" value="Submit"></td>
					<%
						session.setAttribute("login_msge", myString);
									String login_msg3 = "cool";
									login_msg3 = (String) request.getAttribute("outputt");

									if (login_msg3 != null) {
										out.println("<font color=red size=4px>" + login_msg3 + "</font>");
									}
					%>
				</tr>
			</table>
		</form>
	</center>












</body>
</html>