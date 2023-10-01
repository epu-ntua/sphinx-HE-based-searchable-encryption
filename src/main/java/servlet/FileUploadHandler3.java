package main.java.servlet;


import java.io.IOException;
import java.util.List;
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
import javax.servlet.ServletException;
//import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class FileUploadHandler2
 */
@WebServlet("/upload3")
public class FileUploadHandler3 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FileUploadHandler3() {
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
//	private final String UPLOAD_DIRECTORY = "/home/tec/decrypteddata/";
	private final String UPLOAD_DIRECTORY = "/usr/local/downloadeddata";
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String uname=request.getParameter("filename");
		//
		//TO DO : search using the search query uname
		//
		long starttime=System.nanoTime();
        TechLib tl = new TechLib();
        String str = tl.link(3,uname);
	
	long stoptime=System.nanoTime();
						
						try{
		File file = new File("/usr/local/HE/logs.txt");
		FileWriter fstream = new FileWriter(file,true);
		BufferedWriter out = new BufferedWriter(fstream);
		
		long timet=stoptime-starttime;
		out.write("search time" + timet);
		out.newLine();
		out.close();
		//pw.println("File is created successfully");
		}

		catch (Exception e){
		System.err.println("Error: " + e.getMessage());
						
					}				// File uploaded successfully
				
		//// to encrypt
//				Encryption _enc = new Encryption();
//				_enc.ReadKeys();
//				_enc.EncryptJSONFiles("C:/Users/Zahra/Desktop/Eclipse-for-network/uploads/Encrypt/"+ name2);
//////////////////				
		//		anonymize.anonymize1();
//			} catch (Exception ex) {
//				request.setAttribute("message", "File Decryption Failed due to " + ex);
//			}
//		} else {
//			response.sendRedirect("Result.jsp");
//			request.setAttribute("message", "Sorry this Servlet only handles file decrypt request");
//		
//		}
		
		
		
	//	request.getRequestDispatcher("/Result.jsp").forward(request, response);
//		request.setAttribute("messa212","Valid");
//		RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
//		rd.include(request, response);
		
		
		if (str.length() == 0)
		{
			request.setAttribute("messa212","Invalid");
						RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
	     	rd.include(request, response);
		}
		else
		{
			//request.setAttribute("error","Invalid Username or Password");
		    request.setAttribute("messa212","Valid");
		   // request.setAttribute("responseData", str);
			RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
	     	rd.include(request, response);
		}
		
		
		
		
		
	}

}
