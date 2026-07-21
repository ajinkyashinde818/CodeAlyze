import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    public static long gcd(long a,long b)
    {if (b == 0) 
        return a; 
    return gcd(b, a % b);  }
    public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s=new Scanner(System.in);
		long a=s.nextLong();
		long b=s.nextLong();
		long k=gcd(a,b);
		System.out.println((a*b)/k);
	}}
