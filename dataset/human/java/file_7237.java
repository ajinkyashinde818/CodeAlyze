// No sorceries shall prevail. //           
import java.util.*;
import java.io.*;
public class Main {
	
	static long gcd(long a, long b) { 
	      if (b == 0) 
	        return a; 
	      return gcd(b, a % b);  
	    }
	static int gcd(int a, int b) { 
	      if (b == 0) 
	        return a; 
	      return gcd(b, a % b);  
	    }
	
	static long mod = 1000000007;
	public static void main(String args[]) {
		Scanner inp=new Scanner(System.in);
		PrintWriter out=new PrintWriter(System.out);
		
		long k=inp.nextLong();
		int n=inp.nextInt();
		long a[]=new long[n];
		for(int i=0;i<n;i++)
			a[i]=inp.nextLong();
		long max=k+a[0]-a[n-1];
		for(int i=1;i<n;i++) {
			max=Math.max(a[i]-a[i-1], max);
		}
		out.println(k-max);
		
		out.close();
		inp.close();
	}
}
