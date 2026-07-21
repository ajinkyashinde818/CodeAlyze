/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		long v=s.nextLong();
		long a[]=new long[n];
		for(int i=0;i<k;i++)
		{a[i]=v;}
		if(v>=3)
		{for(int i=k;i<n;i++)
		a[i]=v-1;}
		else
		{for(int i=k;i<n;i++)
		a[i]=v+1;}
		for(int i=0;i<n;i++)
		System.out.print(a[i]+" ");
	}}
