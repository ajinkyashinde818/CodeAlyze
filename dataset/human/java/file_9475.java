/* package codechef; // don't place package name! */
 
import java.util.*;
import java.lang.*;
import java.io.*;
 
/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
  /* Name of the class has to be "Main" only if the class is public. */
	public static void main (String[] args) throws java.lang.Exception
	{
      /* Name of the class has to be "Main" only if the class is public. */
	    Scanner syed=new Scanner(System.in);
	    int looplim=syed.nextInt();
	    boolean hua=false; 
	    int count=0;
	    for(int iter=0;iter<looplim;iter++)
	    {
	        int a=syed.nextInt();
	        int b=syed.nextInt();
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
