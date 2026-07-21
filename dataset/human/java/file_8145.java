//package atcoder;
 
import java.util.*;
//import java.math.BigDecimal;
 
public class Main{
	static boolean[] targetNumbers;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long gcd = calcGcd(A,B);
		
		System.out.println(A*B/gcd);
	}
	public static long calcGcd(long m,long n) {
		if(m < n) {
            long tmp = m;
            m = n;
            n = tmp;
        }
        long remainder = 0;
        while ((remainder = m % n) != 0) {
            m = n;
            n = remainder;
        }
        return n;
    }
	
}
