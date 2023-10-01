package main.java.servlet;


import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class encryptinput
 */
@WebServlet("/encryptinput")
public class encryptinput extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public encryptinput() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String unamee=request.getParameter("surrogateIdd");
		String outii=new String();
//		outii=anonymize.search(unamee);
	//	String password=request.getParameter("passworde");
	//	if (uname.equals("Red") && password.equals("12"))
	//	{
			//response.sendRedirect("member.jsp");
		HttpSession session= request.getSession();
		String vali=(String) session.getAttribute("login_msge");
		
		if (vali=="Valid") {
			request.setAttribute("output",outii);
			RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
			rd.include(request, response);}
		else {
			request.setAttribute("output","Login again");
			RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
			rd.include(request, response);
		}
			
				
	//	}
	}

}
