import java.io.*;
import java.util.*;
class Main
{
	 public static void  main (String[] args) throws IOException
    {
       try{
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       int a=0;
       a=Integer.parseInt(br.readLine());
       	int n[][]=new int[a][2];
       	for(int i=0;i<n.length;i++)
       	{
       	  String c[]=br.readLine().split(" ");
           n[i][0]=Integer.parseInt(c[0]);
           n[i][1]=Integer.parseInt(c[1]);
       	}
       	boolean b=false;
       	for(int i=0;i<n.length-2;i++)
       	{
       		if(n[i][0]==n[i][1]&&n[i+1][0]==n[i+1][1]&&n[i+2][0]==n[i+2][1])
       		{
       			System.out.println("Yes");
       			b=true;
       			break;
       		}
       	}
       	if(b==false)
       	{
       		System.out.println("No");
       	}
       	}
    catch(Exception e){}
}}
