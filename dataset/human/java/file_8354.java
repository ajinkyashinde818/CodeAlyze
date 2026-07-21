import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scn = new Scanner(System.in)) {
			final long a = scn.nextLong();
			final long b = scn.nextLong();

			System.out.println(a / gcd(a, b) * b);
		}
	}

	static long gcd(long a, long b) {
		if (a == 0) {
			return b;
		} else if (b == 0) {
			return a;
		}

		final long m = Math.max(a, b);
		final long n = Math.min(a, b);
		return gcd(n, m % n);
	}
}
