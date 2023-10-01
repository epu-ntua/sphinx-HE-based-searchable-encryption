package main.java.servlet;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.*;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Logincheck
 */
@WebServlet("/Logincheck")
public class Logincheck extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Logincheck() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String uname=request.getParameter("uname");
		String password=request.getParameter("password");
		String[] allelements= new String[4];
		//if (uname.equals("Admin") && password.equals("12345"))
		//{
	//		response.sendRedirect("member.jsp");
	//	}
		if(uname.length()>0 && password.length()>0)
		{
	        // file is placed under the WEB-INF directory.
	     //   String filename = "/usr/local/namelist/name1.txt";
	        
	          File file = new File("/usr/local/namelist/name1.txt"); 



//	        ServletContext context = getServletContext();

	        // First get the file InputStream using ServletContext.getResourceAsStream()
	        // method.
//	        InputStream is = context.getResourceAsStream(filename);
	BufferedReader br = new BufferedReader(new FileReader(file));         
	      
	        if (br != null) {
	      //      InputStreamReader isr = new InputStreamReader(is);
	      //      BufferedReader reader = new BufferedReader(isr);
	      //      PrintWriter writer = response.getWriter();
	            String text;

	            // We read the file line by line and later will be displayed on the
	            // browser page.
	            while ((text = br.readLine()) != null) {
					    //while ((text = reader.readLine()) != null) {
	            	allelements=text.split(" ");
	              //  writer.println(allelements[2] + "</br>");
	            	   if(  Integer.toString(uname.hashCode()).equals(allelements[2]) && Integer.toString(password.hashCode()).equals(allelements[3]))
		        		{
		        	response.sendRedirect("member.jsp");
		        	return;
		        }
	            }
	        }
		}		else
		{
			request.setAttribute("error","Invalid Username or Password");
			RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
			rd.include(request, response);
		
		}
	}

}
