import java.util.*;
import java.io.*;
 
public class Main {
    public static void main (final String[] args) {
        final Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
      	long m = sc.nextLong();
      	
      	if (n > m) System.out.println(n*m/gcd(n,m));
      	else System.out.println(n*m/gcd(m,n));
    }
  
  	static long gcd (long a, long b) {
	    long temp;
	    while((temp = a%b)!=0) {
		    a = b;
		    b = temp;
	    }
	    return b;
    }
}
