import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try (Scanner sc = new Scanner(System.in)) {

			long A = sc.nextInt();
			long B = sc.nextInt();

			System.out.println(lcm(A, B));
		}
	}

	static long lcm(long a, long b) {

		long gcd = gcd(a, b);
		return gcd * (a / gcd) * (b / gcd);
	}

	static long gcd(long a, long b) {

		long max = Math.max(a, b);
		long min = Math.min(a, b);

		if (max - min == 1) {
			return 1;
		}

		if (max % min == 0) {
			return min;
		} else {
			return gcd(min, max % min);
		}
	}

}
