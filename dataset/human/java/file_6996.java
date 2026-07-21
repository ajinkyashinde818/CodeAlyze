/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class Main {
	public static void main (String[] args)   {
	   Scanner s=new Scanner(System.in); 
       int k=s.nextInt();
       int n=s.nextInt();
       int arr[]=new int[n];
       for(int i=0;i<n;i++)
       {
           arr[i]=s.nextInt();
       }
       int maxdiff=0;
       for(int i=1;i<n;i++)
       {
           if(maxdiff<arr[i]-arr[i-1])
           maxdiff=arr[i]-arr[i-1];
       }
       if(maxdiff<k-arr[n-1]+arr[0])
       {
           System.out.println(k-(k-arr[n-1]+arr[0]));
       }
       else
       {
           System.out.println(k-maxdiff);
       }
	   
	    
 
	}
	
}
