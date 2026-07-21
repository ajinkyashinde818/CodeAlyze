import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		long ans = lcm(a, b);
		System.out.println(ans);
	}

	public static long lcm(long m, long n) {
		return m * n / gcd(m, n);
	}

	public static long gcd(long m, long n) {
		if (m < n)
			return gcd(n, m);
		if (n == 0)
			return m;
		return gcd(n, m % n);
	}
}
