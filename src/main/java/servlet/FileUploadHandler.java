package main.java.servlet;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.List;
import java.util.UUID;

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

//import sun.rmi.runtime.Log;

//import net.codejava.anonymize;

/**
 * Servlet implementation class FileUploadHandler
 */
//@WebServlet(name ="FileUploadHandler", urlPatterns = {"/upload"})
@WebServlet("/Encryption")
//@MultipartConfig
public class FileUploadHandler extends HttpServlet {

//	private static final long serialVersionUID = 1L;

//	private static final long serialVersionUID = 4470044101132876855L;
	
   /**
     * This constructor initializes a new HTTP POST request with content type
     * is set to multipart/form-data
     *
     * @param requestURL
     * @param charset
     * @return 
     * @throws IOException
     */
    

	
	
	
	private String UPLOAD_DIRECTORY = "/usr/local/textdata";
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse responses)
			throws ServletException, IOException 
	{
		
//		String kPath=null;
    	
 //	   String pathA = "./src/SetGlobalPath.txt";
 //	   FileInputStream fstream = new FileInputStream(pathA);
 	
 //	   DataInputStream in = new DataInputStream(fstream);
 //       BufferedReader br = new BufferedReader(new InputStreamReader(in));
 //   String strLine;
 //   int k=0;
 //   while ((strLine = br.readLine()) != null)   {
// 	   if(k==1) {
// 		   kPath=strLine;
// 	   }
 	    
 //	    }
  //  UPLOAD_DIRECTORY=kPath;
		
		String name2=new String();
//		responses.sendRedirect("Result.jsp");
		if (ServletFileUpload.isMultipartContent(request)) {
		//	responses.sendRedirect("Result.jsp");
			
			try {
				List<FileItem> multiparts = new ServletFileUpload(new DiskFileItemFactory()).parseRequest(request);
				
				for (FileItem item : multiparts) {
					if (!item.isFormField()) {
						String name = new File(item.getName()).getName();
						item.write(new File(UPLOAD_DIRECTORY + File.separator + name));
						name2=name;
                        //TO DO ..
						//encrypt using c++ library
                        //
						long starttime=System.nanoTime();
                        TechLib tl = new TechLib();
                        String str = tl.link(1,name);
                        
               //         System.out.println("indranil start here");
						long stoptime=System.nanoTime();
			//			System.out.println(stoptime-starttime);
						
							try{
		File file = new File("/usr/local/HE/logs.txt");
		FileWriter fstream = new FileWriter(file,true);
		BufferedWriter out = new BufferedWriter(fstream);
		
		long timet=stoptime-starttime;
		out.write("encryption time" + timet);
		out.newLine();
		out.close();
		//pw.println("File is created successfully");
		}

		catch (Exception e){
		System.err.println("Error: " + e.getMessage());
		}
						/////		anonymize.anonymize1(name2);       ///////
			//			System.out.println("yeh name hai"+ name);
					//	request.setAttribute("message", "File Uploaded Successfully" + name);
					}
				}
				// File uploaded successfully
				request.setAttribute("message", "File Uploaded Successfully");
				

			} catch (Exception ex) {
				request.setAttribute("message", "File Upload Failed due to " + ex);
			}
		} else {
			responses.sendRedirect("Result.jsp");
			request.setAttribute("message", "Sorry this Servlet only handles file upload request");
		
		}
		
	//	request.getRequestDispatcher("/Result.jsp").forward(request, responses);
		request.setAttribute("messa","Valid");
	//	request.setAttribute("messa", name2 );
		
		RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
		rd.include(request, responses);

	}

}
