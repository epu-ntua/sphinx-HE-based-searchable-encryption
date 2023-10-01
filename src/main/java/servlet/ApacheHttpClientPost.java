package main.java.servlet;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;

public class ApacheHttpClientPost {

    public String Apach(String valuee) throws IOException {

//    	String kPath=null;
    	
    	//   String pathA = "./SetGlobalPath.txt";
//    	   FileInputStream fstream = new FileInputStream("./SetGlobalPath.txt");
    	//   ifstream myfileA (pathA.c_str());
 ///   	   DataInputStream in = new DataInputStream(fstream);
 //          BufferedReader br = new BufferedReader(new InputStreamReader(in));
  //     String strLine;
 //      int k=0;
 //      while ((strLine = br.readLine()) != null)   {
 //   	   if(k==3) {
 //   		   kPath=strLine;
 //   	   }
 //   	    
 //   	    }
    	
    	
    	
    	String builderr = new String();
        try (CloseableHttpClient client = HttpClientBuilder.create().build()) {

            HttpPost request = new HttpPost("https:/fortika-he-component.xlab.si/Search");
 //           HttpPost request = new HttpPost(kPath+"Search");
            request.setHeader("User-Agent", "Java client");
            request.setEntity(new StringEntity(valuee));

            HttpResponse response = client.execute(request);

            BufferedReader bufReader = new BufferedReader(new InputStreamReader(
                    response.getEntity().getContent()));

            StringBuilder builder = new StringBuilder();

            String line;

            while ((line = bufReader.readLine()) != null) {
                builder.append(line);
                builder.append(System.lineSeparator());
            }

           // System.out.println(builder);
            builderr= builder.toString();
        }
        
        return builderr;
    }
}
