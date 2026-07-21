import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	final long m = (long) 1e9 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		System.out.println(A / gcd(A, B) * B);
	}

	long gcd(long a, long b) {
		if (a > b)
			return gcd(b, a);
		if (a == 0)
			return b;
		return gcd(a, b % a);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}
