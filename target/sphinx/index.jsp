
<!DOCTYPE html>
<html lang="en">
  <meta charset="UTF-8">
<head>





  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="description" content="">
  <meta name="author" content="">

  <title>Visualization Tool - Dashboard</title>

  <!-- Custom fonts for this template-->
  <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
  <link href="https://fonts.googleapis.com/css?family=Nunito:200,200i,300,300i,400,400i,600,600i,700,700i,800,800i,900,900i" rel="stylesheet">

  <!-- Custom styles for this template-->
  <link href="css/sb-admin-2.min.css" rel="stylesheet">
 <link href='https://fonts.googleapis.com/css?family=Montserrat:400,700' rel='stylesheet' type='text/css'>
 
  <link rel="stylesheet" href="css/ol.css" type="text/css">
   <script src="build/ol.js"></script>
   <script src='js/cytoscape.min.js'></script>
   <link rel="stylesheet" type="text/css" href="css/style.css">

</head>



<!-- this is for the initial search request -------------------->


<!--
<script>
window.onload=defaultcode;
	//	$(document).ready(function () {
	//				$('#bt_caseid').click(function () {
	function defaultcode(){
const Http =new XMLHttpRequest();
const url='https://redalert.siveco.ro:5443/api/v1/search/cases';
//const url='http://195.82.130.140:8084/api/v1/search';
Http.open("GET",url);
Http.send();

Http.onreadystatechange=function(){

//if (Http.readyState == 4 && Http.status == 200)
 //     {
        if (Http.responseText)
         {
                //put your code here 
           parse(Http.responseText);
          }
 //      }

//parse(Http.responseText);
}
//console.log(Http.responseText)
window.pkrback=[];

window.ui=0;
var responseText=document.getElementById('response_caseid');
var array=null;
function parse (text){
//console.log(text);
pkrbb=[];
array=text.split(",");
var pkr=null;
//console.log(array)
for(io=0;io<array.length;io++){
	if(io==0){
	//console.log(array[io]);
	array[io]=array[io].split("[")[1].split(":")[1].split("}")[0];
//	console.log(JSON.stringify(array[io]))
//	window.pkrback[io]=JSON.stringify(array[io]);
pkrbb[io]=JSON.stringify(array[io]);
	pkr=array[io]+" , ";}
	else{
	if(io==array.length-1){
	array[io]=array[io].split("]")[0];
	//	console.log(JSON.stringify(array[io]))
//	window.pkrback[io]=JSON.stringify(array[io]);
	}
	if(io==array.length-1){
	pkr=pkr+array[io].split(":")[1].split("}")[0];
	//	console.log(JSON.stringify(array[io].split(":")[1].split("}")[0]))
	pkrbb[io]=JSON.stringify(array[io].split(":")[1].split("}")[0]);
	
	}
	else{
	pkr=pkr+array[io].split(":")[1].split("}")[0]+" , ";
		//	console.log(JSON.stringify(array[io].split(":")[1].split("}")[0]))
	pkrbb[io]=JSON.stringify(array[io].split(":")[1].split("}")[0]);
	}
	}
	
	
}
//  responseText.innerHTML=pkr;

//window.ui=window.ui+1;

//console.log(window.pkrback);
var select = document.getElementById("caseidd_function"); 
//var options = ["1", "2", "3", "4", "5"]; 
var hrty =[];
var tu=0;
//console.log((hrty.includes(pkrbb[0].split("\"")[1])))

var tpp=0;
for(var ht=0;ht<pkrbb.length;ht++){
var tp=0;
if(ht==0){hrty[tpp]=pkrbb[ht].split("\"")[1]; tpp=tpp+1;tp=1;}
else{
for(var htt=0; htt<hrty.length;htt++){
if(tp==0){
if(hrty[htt]==pkrbb[ht].split("\"")[1]){tp=1;}
}
}
if(tp==0){
hrty[tpp]=pkrbb[ht].split("\"")[1];
tpp=tpp+1;}
}
}


//console.log(hrty)

for(var i = 0; i < hrty.length; i=i+1){
    var opt = hrty[i];
//	console.log(opt)
	if (opt != null){
    var el = document.createElement("option");
    el.textContent = opt;
    el.value = opt;
    select.appendChild(el);}
	}



}



//$('#idTable').append(array[0]);
//			});});	
}		
				
		   </script>


-->








  <!-- Page Wrapper -->
  <div id="wrapper">

    <!-- Sidebar -->
    <ul class="navbar-nav bg-gray-800 sidebar sidebar-dark accordion" id="accordionSidebar">

      <!-- Sidebar - Brand -->
  <!--    <a class="sidebar-brand d-flex align-items-center justify-content-center" href="index.html">
        <div class="sidebar-brand-icon rotate-n-15">
         </div>
        <div class="sidebar-brand-text mx-3" href="https://www.sphinx-project.eu"><img
			src="SPHINX_logo.png"
			width="140" height="60" /></div>
      </a> -->
	  
	   

      <!-- Divider -->
      <hr class="sidebar-divider my-0">


	   

      <!-- Divider -->
      <hr class="sidebar-divider">

      <!-- Nav Item - Charts -->
      <li class="nav-item">
        <a class="nav-link" href="index.html">
          <i class="fas fa-fw fa-chart-area"></i>
          <span> <h1 style="color:white;font-size:30px;">Homomorphic Encryption</h1></span></a>
      </li>
	  
         <li class="nav-item">
        <a class="nav-link" href="https://www.sphinx-project.eu">
          <i class="fas fa-fw fa-chart-area"></i>
          <img
			src="SPHINX_logo.png"
			width="170" height="60" /></a>
      </li>
        
	        <!-- Nav Item - Charts -->
      <li class="nav-item">
        <a class="nav-link" href="https://www.techinspire.co.uk">
          <i class="fas fa-fw fa-chart-area"></i>
          <img
			src="logo.png"
			width="170" height="60" /></a>
      </li>
	  
	  	        <!-- Nav Item - Charts -->


      <!-- Divider -->
      <hr class="sidebar-divider d-none d-md-block">

      <!-- Sidebar Toggler (Sidebar) -->
      <div class="text-center d-none d-md-inline">
        <button class="rounded-circle border-0" id="sidebarToggle"></button>
      </div>

       

    </ul>
    <!-- End of Sidebar -->

    <!-- Content Wrapper -->
    <div id="content-wrapper" class="d-flex flex-column">

      <!-- Main Content -->
      <div id="content">

        <!-- Topbar -->
        <nav class="navbar navbar-expand navbar-light bg-white topbar mb-4 static-top shadow">

          <!-- Sidebar Toggle (Topbar) -->
          <button id="sidebarToggleTop" class="btn btn-link d-md-none rounded-circle mr-3">
            <i class="fa fa-bars"></i>
          </button>

         
  

          </ul>

        </nav>
        <!-- End of Topbar -->
		
		        <!-- Begin Page Content -->
<div class="container">
<div id='someDetails'></div>
<!--	<div class="d-sm-flex align-items-center justify-content-between mb-4">
             <button onclick="javascript:keycloak.login();"><a> Login</a><button onclick="javascript:keycloak.logout();"><a> Logout</a>
          </div>
-->
	
    <!--  
	   <div class="d-sm-flex align-items-center justify-content-between mb-4">
            <h1 class="h3 mb-0 text-gray-800">Retrieve all Case-IDs</h1>
       </div>
	  -->
	    <!-- Page Heading -->
		<!--
 <div class="row">
    <p>
        <input type="button" class="btn_3" value="Retrieve Case IDs" id="bt_caseid" />
    </p>
 </div>
 <div class="row">
    
    <table width="50%" class="table" id="idTable">
       <tr>
          <td>Case-IDs</td>
		  
		  <td> <p id="response_caseid"></p> </td>
       </tr>
    </table>
 
 </div> -->
	  
<hr>	  
	  
	  
	  
	  <!--  <p style="text-align: center">
		<img
			src="C:\Users\Zahra\Desktop\Eclipse-for-network\Workspace\Red-Alert\logo.jpg" />
	</p>
-->
	
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
<!--<br />
	<Strong><font size="3"> Upload </font></Strong>
	<br /> Use this link to upload files
		<center>
	
		<form action="http://localhost:8080/uploadFile" method="post" enctype="multipart/form-data">
		<br />
		<label for="file"> Select a file:</label>
		<input type="file" name="file" multiple id="file"/> <br>
		<br />
		<input type="submit" value="upload">
		
		</form>
 
 <!--
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
 -->
	</center>

<!--	<div id="background-img" class="background-img">
		<img
			src="FortikaLogo.jpg"
			width="140" height="90" />
	</div>
-->

	<hr />
	<hr />
	<Strong><font size="3"> Search </font></Strong>
    <center>
     
     <br />   
       <div class="contact-form">
  <div class="row"> 
             <div class="grid_4">
             <!-- <label>Case ID:</label> -->
			   <label>Select which database you want to search in :</label>
             </div>
             <div class="grid_5">
			 <select  name="field12" id="caseidd_function">  
               <option value="">--SELECT-- </option>
    <option value="category_id">DYPE</option>
    <option value="category_id">HESE</option>
    <option value="category_id">POLARIS</option>
<option value="category_id">TECNALIA</option>
			 
            </select>
            <!--  <input type="text" name="case_iid" value="" id="caseidd_function"> -->
             </div>
           </div>
		   <p></p>
         
		  
		  
       </div>  
    </center>
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
<!-- 
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

-->
	</center>
<Strong><font size="3"> Decrypt </font></Strong>
	<br /> Select the files that you want to decrypt
	<center>
	
	<form method="post" action="upload3">
  Enter Filename:
  <input type="text" name="filename" >
  <input type="submit" value="Submit">
<!--  		<form method="post" action="upload2" enctype="multipart/form-data" name="form1" id="form1">
			Select a file: <input type="file" name="file" accept=".txt" id="file" multiple/>
 <input name="submit" type="submit" value="Decrypt" />  -->
			<%
				String login_msgeee = (String) request.getAttribute("messa212");
			//   out.println("<font color=red size=4px>" + login_msge+ "</font>");
				//if (login_mseeg != null)
				if (login_msgeee == "Invalid") {
					out.println("<font color=red size=4px>" + "File Successfully Decrypted" + "</font>");
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

	  
	  
        

<br>
<br>

<!--      
<div class="dropdown">
  <button onclick="myFunction11()" class="dropbtn">Calendar</button>
  <div id="myDropdown" class="dropdown-content">
    <a href="#home">Today</a>
    <a href="#yes">Yesterday</a>
    <a href="#3days">Last 3 Days</a>
    <a href="#7days">Last 7 Days</a>
    <a href="#14days">Last 14 Days</a>
    <a href="#28days">Last 28 Days</a>
    <a href="#90days">Last 90 Days</a>
    <a href="#lastyear">Last Year</a>
      </div></th></tr> </table>
      <br>
      <button type="submit" class="searchButton">
        <i class="fa fa-search"></i>
     </button>
</u></form></th> 
</div>
-->



<br>
<br>
<br>

          <!-- Content Row -->


            <!-- Pie Chart -->
            
   <!--       </div>    <!-- yahan per tha pehlay rooo-->


<!-- Content Row -->

		
		
      </div>
      <!-- End of Main Content -->

    </div>
    <!-- End of Content Wrapper -->

  </div>
  <!-- End of Page Wrapper -->

  <!-- Scroll to Top Button-->
  <a class="scroll-to-top rounded" href="#page-top">
    <i class="fas fa-angle-up"></i>
  </a>

  <!-- Logout Modal-->
  <div class="modal fade" id="logoutModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog" role="document">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="exampleModalLabel">Ready to Leave?</h5>
          <button class="close" type="button" data-dismiss="modal" aria-label="Close">
            <span aria-hidden="true">×</span>
          </button>
        </div>
        <div class="modal-body">Select "Logout" below if you are ready to end your current session.</div>
        <div class="modal-footer">
          <button class="btn btn-secondary" type="button" data-dismiss="modal">Cancel</button>
          <a class="btn btn-primary" href="login.html">Logout</a>
        </div>
      </div>
    </div>
  </div>
  
  
  
  
  <!-- Bootstrap core JavaScript-->
  <script src="vendor/jquery/jquery.min.js"></script>
  <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

  <!-- Core plugin JavaScript-->
  <script src="vendor/jquery-easing/jquery.easing.min.js"></script>

  <!-- Custom scripts for all pages-->
  <script src="js/sb-admin-2.min.js"></script>

  <!-- Page level plugins -->
  <script src="vendor/chart.js/Chart.min.js"></script>

  <!-- Page level custom scripts -->
 <!--  <script src="js/demo/chart-area-demo.js"></script>
  <script src="js/demo/chart-pie-demo.js"></script>
   <script src="js/demo/chart-bar-demo.js"></script> -->
  
  <div id="map"></div>

 <!--       <script src="https://code.jquery.com/jquery-1.12.0.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
        <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBu5nZKbeK-WHQ70oqOWo-_4VmwOwKP9YQ"></script>
        <script src="js/custom.js"></script> -->
  
  

</body>

</html>
