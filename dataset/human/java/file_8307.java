import java.util.*;

public class Main {
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long m =sc.nextLong();
		long n =sc.nextLong();
		long ans = lcm(m,n);
		System.out.println(ans);
		
	}
		private static long lcm(long m, long n) {
		    return m * n / gcd(m, n);
		}
		private static long gcd(long m, long n) {
		    if(m < n) return gcd(n, m);
		    if(n == 0) return m;
		    return gcd(n, m % n);
		}


	
}
