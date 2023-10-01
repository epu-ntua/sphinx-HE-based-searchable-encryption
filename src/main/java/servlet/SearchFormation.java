package main.java.servlet;


import java.io.IOException;
import java.io.InputStream;
import java.net.URI;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.util.List;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;


/**
 * Servlet implementation class SearchFormation
 */
@WebServlet("/SearchFormation")
public class SearchFormation extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SearchFormation() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest requestt, HttpServletResponse responsee) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String uname=requestt.getParameter("firstname");
		//
		//TO DO : search using the search query uname
		//
		long starttime=System.nanoTime();
        TechLib tl = new TechLib();
        String str = tl.link(2,uname);
	
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
						
					}

        //////////////////////////////////////////////////////////////
    /*    String resp=new String();

		ApacheHttpClientPost newcode = new ApacheHttpClientPost();
		ApacheHttpClientPost2 newcode2 = new ApacheHttpClientPost2();

		File file = new File("/usr/local/trapdoor/trapdoor.txt");



		BufferedReader br = new BufferedReader(new FileReader(file));
		 BufferedReader br2 = new BufferedReader(new FileReader(file));

		  String st;
		  String st2;
		  int val=0;
		  while ((st = br.readLine()) != null)
		    { val=val+1;}

		 resp=newcode2.Apach(Integer.toString(val));

		  while ((st2 = br2.readLine()) != null)
		    {//System.out.println(st2);

		 resp=newcode.Apach(st2);}






*/





         //////////////////////////////////////////////////////////


		//ApacheHttpClientPost newcode = new ApacheHttpClientPost();
		//String resp=newcode.Apach(uname);

		 
		 //String password=request.getParameter("password");
		if (str.length() == 0)
		{
			requestt.setAttribute("messaa","Invalid");
						RequestDispatcher rd=requestt.getRequestDispatcher("/index.jsp");            
	     	rd.include(requestt, responsee);
		}
		else
		{
			//request.setAttribute("error","Invalid Username or Password");
		    requestt.setAttribute("messaa","Valid");
		    requestt.setAttribute("responseData", str);
			RequestDispatcher rd=requestt.getRequestDispatcher("/index.jsp");            
	     	rd.include(requestt, responsee);
		}
		}
	}


