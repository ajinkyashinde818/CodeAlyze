import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextInt();
		long B = sc.nextInt();
		long mul = A * B;
		System.out.print(mul / gcd(A, B));
	}

	private static long gcd(long a, long b) {
		while (a * b != 0) {
			if (a >= b) {
				a = a % b;
			} else {
				b = b % a;
			}
		}
		return Math.max(a, b);
	}
}
