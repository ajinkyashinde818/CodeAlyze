import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long a = in.nextLong();
		long b = in.nextLong();
		long ans = (long)((long)a * (long)b) / (long)gcd(Math.max(a, b), Math.min(a, b));
		System.out.println(ans);
	}
	public static long gcd(long a, long b) {
		if(a % b == 0) return b;
		else return gcd(b, a % b);
	}
}
