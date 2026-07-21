import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.ThreadLocalRandom;
public class Main 
{
	
	static long gcd(long a, long b) 
	{
		if (b == 0)
		{	
			return a;
		}
		
		else
		{
			 return gcd(b, a % b);
		}
	}
	public static void main(String[] args) throws Exception
	{

		
		   PrintWriter out = new PrintWriter(System.out);
		   Scanner in = new Scanner(System.in);
		 // long n , k , q;
		  
	int k = in.nextInt();
	  int n = in.nextInt();
	  long cnt = 0;
	//long cnt = 0;
	for(int a = 0; a <= k ; a++)
		for(int b = 0; b <=k ; b++)
		{
			if( n - a - b <= k && n - a - b >= 0) cnt++;
		}

	out.println(cnt);
	   out.close();
	}
}
