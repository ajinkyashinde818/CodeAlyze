/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	    int looplim=sc.nextInt();
	    boolean hua=false; 
	    int count=0;
	    for(int iter=0;iter<looplim;iter++)
	    {
	        int a=sc.nextInt();
	        int b=sc.nextInt();
	        if(a==b){count++;
	        if(count>=3) hua=true;}
	        else {count=0;}
	        
	    
	    }
	    if (hua)
	    System.out.println("Yes");
	    else
	    System.out.println("No");
	        
	}
}
