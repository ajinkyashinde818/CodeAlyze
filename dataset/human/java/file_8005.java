import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try(Scanner sc = new Scanner(System.in)) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			long ans = lcm(a, b);
			System.out.println(ans);
		}

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
