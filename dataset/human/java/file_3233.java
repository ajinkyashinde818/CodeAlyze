/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    static Scanner sc ;
	public static void main (String[] args) throws java.lang.Exception
	{
	    sc = new Scanner(System.in) ;
	    int x = sc.nextInt() ;
	    while(x>0)
	    {
	        int d = x%10 ;
	        if(d==9)
	        {
	            System.out.println("Yes") ;
	            return ;
	        }
	        x/=10 ;
	    }
	    System.out.println("No") ;
	}
}
