/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{try{BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String str[] = br.readLine().split(" ");
	long k=Long.parseLong(str[0]);
	int n= Integer.parseInt(str[1]);
	String str1[]= br.readLine().split(" ");
	long max =-1;
	int i;
	for(i=0;i<n-1;i++){
		if((Long.parseLong(str1[i+1])-Long.parseLong(str1[i]))>max) max = Long.parseLong(str1[i+1])-Long.parseLong(str1[i]);
	}
	long t = k+Long.parseLong(str1[0])-Long.parseLong(str1[n-1]);
	if(t>max)max =t;
	System.out.print(k-max);
		
	}catch(Exception e){}
		
	}
}
