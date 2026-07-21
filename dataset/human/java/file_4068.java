/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int [] a=new int [n];
		for(int i=0;i<n;i++)
		{
		    a[i]=in.nextInt();
		}
		int [] b=new int [n];
		for(int i=0;i<n;i++)
		{
		    b[i]=in.nextInt();
		}
		int [] c=new int [n-1];
		for(int i=0;i<n-1;i++)
		{
		    c[i]=in.nextInt();
		}
		int ans=0;
		int prev=-2;
		for(int i=0;i<n;i++)
		{
		    ans=ans+b[a[i]-1];
		    if(a[i]==prev+1)
		    {
		        ans=ans+c[prev-1];
		    }
		    prev=a[i];
		}
		System.out.println(ans);
		  
	}
}
