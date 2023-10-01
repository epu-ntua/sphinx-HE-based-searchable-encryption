package main.java.servlet;
//package target;


import java.util.Scanner;


public class TechLib{

public native String techHELib(int i, String sh);
static
{
    System.loadLibrary("techinspireHELib");
}

public TechLib()
{
//    System.out.println("hello world");
}

public String link(int ii, String str)
//public static void main(String a[])//int ii, String str)
{
    TechLib tl = new TechLib();
//    Scanner reader=new Scanner(System.in);

   
//   System.out.println("request type  = " + ii);
   // String str="No";//reader.nextLine();

    String result = tl.techHELib(ii,str); // 1 is for search and 2 is for decryption
  //  System.out.println("files are = " + result);
   return result;
}
}
