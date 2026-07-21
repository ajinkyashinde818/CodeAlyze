import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			long k = sc.nextLong();
			long n = sc.nextLong();
			List<Long> an = new ArrayList<>();
			for (long i = 0; i < n; i++) {
				an.add(sc.nextLong());
			}
			long max = 0;
			for (int i = 0; i < an.size(); i++) {
				long cand;
				if (i == an.size() - 1) {
					cand = k - an.get(i) + an.get(0);
				} else {
					cand = an.get(i + 1) - an.get(i);
				}
				if (cand > max) {
					max = cand;
				}
			}

			// 出力(整数)
			System.out.println(k - max);
		}
	}

	/**
	 * 最小公倍数
	 */
	static long lcm(long a, long b) {
		long temp;
		long c = a;
		c *= b;
		while ((temp = a % b) != 0) {
			a = b;
			b = temp;
		}
		return c / b;
	}

	/**
	 * 最大公約数
	 */
	static long gcd(long a, long b) {
		long temp;
		while ((temp = a % b) != 0) {
			a = b;
			b = temp;
		}
		return b;
	}
}
