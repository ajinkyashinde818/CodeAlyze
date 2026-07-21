import java.util.Scanner;

public class Main {

	private static long g1(long n, long p) {
		if (n == 0) return 0;
		return n / p + g1(n / p, p);
	}

	private static long g2(long n, long p) {
		if (n % 2 == 1) return 0;
		long a = g1(n / 2, p);
		if (p == 2) a += n / 2;
		return a;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		System.out.println(Math.min(g2(n, 2), g2(n, 5)));
	}
}
