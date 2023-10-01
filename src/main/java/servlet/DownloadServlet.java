package main.java.servlet;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class DownloadServlet
 */
//@WebServlet("/DownloadServlet1")
public class DownloadServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public static final String FILE_SEPARATOR = System.getProperty("file.separator");
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DownloadServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	// TODO Auto-generated method stub

try {
    // The path below is the root directory of data to be
    // compressed.
//    String path = getServletContext().getRealPath("data");

//    File directory = new File(path);
//    String[] files = directory.list();

	
	File folder = new File("/usr/local/encrypteddata");
	String[] listOfFiles = folder.list();
    // Checks to see if the directory contains some files.
    if (listOfFiles != null && listOfFiles.length > 0) {

        // Call the zipFiles method for creating a zip stream.
        byte[] zip = zipFiles(folder, listOfFiles);

        // Sends the response back to the user / browser. The
        // content for zip file type is "application/zip". We
        // also set the content disposition as attachment for
        // the browser to show a dialog that will let user 
        // choose what action will he do to the sent content.
        ServletOutputStream sos = response.getOutputStream();
        response.setContentType("application/zip");
        response.setHeader("Content-Disposition", "attachment; filename=\"" + "DATA.ZIP" +"\"");

        sos.write(zip);
        sos.flush();
    }
}
catch (Exception e) {
    e.printStackTrace();}
RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
rd.include(request, response);
}



//	response.getWriter().append("Served at: ").append(request.getContextPath());
	
	
	private byte[] zipFiles(File directory, String[] files) throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ZipOutputStream zos = new ZipOutputStream(baos);
        byte bytes[] = new byte[2048];

        for (String fileName : files) {
            FileInputStream fis = new FileInputStream(directory.getPath() + 
            		DownloadServlet.FILE_SEPARATOR + fileName);
            BufferedInputStream bis = new BufferedInputStream(fis);

            zos.putNextEntry(new ZipEntry(fileName));

            int bytesRead;
            while ((bytesRead = bis.read(bytes)) != -1) {
                zos.write(bytes, 0, bytesRead);
            }
            zos.closeEntry();
            bis.close();
            fis.close();
        }
        zos.flush();
        baos.flush();
        zos.close();
        baos.close();

        return baos.toByteArray();
    }

}
