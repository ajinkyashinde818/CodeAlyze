import java.io.*;
import java.util.*;
public class Main {
	public static void main (String[] args) {
	    Scanner s=new Scanner(System.in);
	long a=s.nextLong();
	long b=s.nextLong();
	
	long p=a*b;
	long h=gcd(a,b);
	
	System.out.println(p/h);
	
	}
	static long gcd(long a, long b) 
    { 
      if (b == 0) 
        return a; 
      return gcd(b, a % b);  
    } 
}
