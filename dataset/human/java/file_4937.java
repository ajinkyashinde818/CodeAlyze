import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s=new Scanner(System.in);
	long n=s.nextLong();
	long ans=0;
	if(n%2==1)
	System.out.println("0");
	else
	{	n=n/2;
	    for(int i=1;n>=(long)Math.pow(5,i);i++)
	{ans+=(n/(long)Math.pow(5,i));}
	    System.out.println(ans);}}
	}
