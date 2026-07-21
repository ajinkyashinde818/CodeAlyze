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
		long N = sc.nextLong();
		if (N % 2 == 1) {// N,N-2,N-4,...,1が全て奇数
			System.out.println(0);
			return;
		}
		// N:=2m
		// f(N)=2m * 2(m-1) * ... * 2 * 1=2^m m!
		long c2 = (N / 2) + f(N / 2, 2);
		long c5 = f(N / 2, 5);
		System.out.println(Math.min(c2, c5));
	}

	long f(long n, long d) {
		long ret = 0;
		while (n > 0) {
			ret += n / d;
			n /= d;
		}
		return ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}
