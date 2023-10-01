package main.java.servlet;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class accountCreation
 */
@WebServlet("/accountCreation")
public class accountCreation extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public accountCreation() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	//	doGet(request, response);
		
		

		
		
		String firstname=request.getParameter("firstname");
		String surname=request.getParameter("surname");
		String EmployeeNum=request.getParameter("EmployeeNum");
		String password=request.getParameter("password");
		String password2=request.getParameter("password2");

		PrintWriter pw = response.getWriter();
		
		
		if (firstname.length()!=0) {
		if(surname.length()!=0) {
			if(EmployeeNum.length()!=0) {
		
		if (password.equals(password2) && password.length()>0)
		{
		try{
		File file = new File("/usr/local/namelist/name1.txt");
		FileWriter fstream = new FileWriter(file,true);
		BufferedWriter out = new BufferedWriter(fstream);
		
		
		out.write(firstname.hashCode()+" "+surname.hashCode()+" "+EmployeeNum.hashCode()+ " " +password.hashCode());
		out.newLine();
		out.close();
		//pw.println("File is created successfully");
		}

		catch (Exception e){
		System.err.println("Error: " + e.getMessage());
		}
	
		
/*		response.setContentType("text/plain");
        response.setHeader("Content-Disposition", "attachment; filename=\"WEB-INF\"example.txt\"");
        try {
            OutputStream outputStream = response.getOutputStream();
            String outputResult = firstname + "," + surname + "," + EmployeeNum +"," + password;
            outputStream.write(outputResult.getBytes());
            outputStream.flush();
            outputStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
		
*/		
		
		
		response.setContentType("text/html");
		
		

        // We are going to read a file called configuration.properties. This
        // file is placed under the WEB-INF directory.
        String filename = "/WEB-INF/name.txt";

        ServletContext context = getServletContext();

        // First get the file InputStream using ServletContext.getResourceAsStream()
        // method.
        InputStream is = context.getResourceAsStream(filename);
        if (is != null) {
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader reader = new BufferedReader(isr);
            PrintWriter writer = response.getWriter();
            String text;

            // We read the file line by line and later will be displayed on the
            // browser page.
        //    while ((text = reader.readLine()) != null) {
              //  writer.println(text + "</br>");
         //   }
        }
        
        request.setAttribute("error","Account Created Successfully");
		RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
		rd.include(request, response);
		
		
		}
		else {
			request.setAttribute("error","Passwords donot match");
			RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
			rd.include(request, response);
		}
		}
			else{
				request.setAttribute("error","Kindly enter Employee Number");
		RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
		rd.include(request, response);
		}
			}
		else
		{
			request.setAttribute("error","Kindly enter surname");
			RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
			rd.include(request, response);
		}
		}  // first name check
		else {
			request.setAttribute("error","Kindly enter firstname");
			RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
			rd.include(request, response);
		}
		
		
/*		if (password.equals(password2))
		{
			response.sendRedirect("member.jsp");
		}
		else
		{
			request.setAttribute("error","Invalid Username or Password");
			RequestDispatcher rd=request.getRequestDispatcher("/Login.jsp");            
			rd.include(request, response);
		
		}
*/		
		
	}

}
