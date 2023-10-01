package main.java.servlet;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.io.FileOutputStream;

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
@WebServlet("/DownloadServlet1")
public class DownloadServlet3 extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public static final String FILE_SEPARATOR = System.getProperty("file.separator");
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DownloadServlet3() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	// TODO Auto-generated method stub

    // The path below is the root directory of data to be
    // compressed.
//    String path = getServletContext().getRealPath("data");

//    File directory = new File(path);
//    String[] files = directory.list();

	
	File folder = new File("/usr/local/encrypteddata");
	String folder1="/usr/local/encrypteddata/";
	zipFiles(folder1);
 final String filename = "/usr/local/encrypteddata/data.zip";

        BufferedInputStream buf = null;
        ServletOutputStream myOut = null;

        try {
            myOut = response.getOutputStream();

            File myfile = new File(filename);

            if (myfile.exists()) {
                //myfile.createNewFile();
                //set response headers
                response.setHeader("Cache-Control", "max-age=60");
                response.setHeader("Cache-Control", "must-revalidate");
                response.setContentType("application/zip");

                response.addHeader("Content-Disposition", "attachment; filename=" + filename);

                response.setContentLength((int) myfile.length());

                FileInputStream input = new FileInputStream(myfile);
                buf = new BufferedInputStream(input);
                int readBytes = 0;

                //read from the file; write to the ServletOutputStream
                while ((readBytes = buf.read()) != -1) {
                    myOut.write(readBytes);
                }
            }

        } catch (Exception exp) {
        } finally {
            //close the input/output streams
            if (myOut != null) {
                try {
                    myOut.close();
                } catch (IOException ex) {
                }
            }
            if (buf != null) {
                try {
                    buf.close();
                } catch (IOException ex) {
                }
            }

        }

RequestDispatcher rd=request.getRequestDispatcher("/index.jsp");            
rd.include(request, response);
}



//	response.getWriter().append("Served at: ").append(request.getContextPath());
	
	
	private void zipFiles(String dirPath) throws IOException {
final Path sourceDir = Paths.get(dirPath);
        String zipFileName = dirPath.concat("data.zip");
        try {
            final ZipOutputStream outputStream = new ZipOutputStream(new FileOutputStream(zipFileName));
            Files.walkFileTree(sourceDir, new SimpleFileVisitor<Path>() {
                @Override
                public FileVisitResult visitFile(Path file, BasicFileAttributes attributes) {
                    try {
                        Path targetFile = sourceDir.relativize(file);
                        outputStream.putNextEntry(new ZipEntry(targetFile.toString()));
                        byte[] bytes = Files.readAllBytes(file);
                        outputStream.write(bytes, 0, bytes.length);
                        outputStream.closeEntry();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    return FileVisitResult.CONTINUE;
                }
            });
            outputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
      //  return baos.toByteArray();
    }

}
