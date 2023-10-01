<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Login</title>

<style type="text/css">
.box {
	position: fixed;
	margin-left: -150px; /* half of width */
	margin-top: -150px; /* half of height */
	top: 65%;
	left: 35%;
}

.box2 {
	position: fixed;
	margin-left: -150px; /* half of width */
	margin-top: -150px; /* half of height */
	top: 65%;
	left: 65%;
}
.background-img {
	position: absolute;
	right: 10px;
	bottom: 10px
}

div {
	text-align: center;
}

/*
*/
.column {
 float: left;
  width: 50%;
}

/* Clear floats after the columns */
.row:after {
  content: "";
  display: table;
  clear: both;
}
</style>




</head>
<body>

<!--  <div class="row">
  <div class="column"></div>
  <div class="column"></div>
</div>
-->
<div>
<td colspan="6">
		
				<img src="FortikaLogo.jpg" />
				</td>
	<br />
	<Strong><font size="6"> Homomorphic Encryption </font></Strong>
						<br />
		<%
						String login_msg = (String) request.getAttribute("error");
						if (login_msg != null)
							out.println("<font color=red size=4px>" + login_msg + "</font>");
					%>
</div>
<div class ="row">
<div class="box">
		<form method="post" action="Logincheck">
			<table class="box">
				<td colspan="6">
		
				<strong>Sign In</strong>
				</td>
				

				<tr bgcolor="white">
					<td><strong>Employee Number</strong></td>
					<td><input type="text" name="uname"></td>
				</tr>

				<tr bgcolor="white">
					<td><strong>Password</strong></td>
					<td><input type="password" name="password"></td>
				</tr>

				<tr>
					<td></td>
					<td><strong><input type="submit" value="login" ></strong>
					
						<%
			//			String login_msg = (String) request.getAttribute("error");
			//			if (login_msg != null)
			//				out.println("<font color=red size=4px>" + login_msg + "</font>");
					%>
					
					</td>
				</tr>

			</table>
		</form>
		</div>
		<div class="column">
		<form method="post" action="accountCreation">
			<table class="box2">
				<td colspan="6">
		
				<strong>Create an Account</strong>
				</td>
				<tr bgcolor="white" align="left">
					<td><strong>First Name</strong></td>
					<td><input type="text" name="firstname"></td>
				</tr>

				<tr bgcolor="white" align="left">
					<td><strong>Surname</strong></td>
					<td><input type="text" name="surname"></td>
				</tr>
				<tr bgcolor="white" align="left">
					<td><strong>Employee Number</strong></td>
					<td><input type="text" name="EmployeeNum"></td>
				</tr>
				<tr bgcolor="white" align="left">
					<td><strong>Enter password</strong></td>
					<td><input type="password" name="password"></td>
				</tr>
				<tr bgcolor="white" align="left">
					<td><strong>Re-Enter password</strong></td>
					<td><input type="password" name="password2"></td>
				</tr>

				<tr>
					<td></td>
					<td><strong><input type="submit" value="Sign Up" ></strong>

					</td>
				</tr>

			</table>
		</form>
		</div>
		
	</div>


</body>
</html>