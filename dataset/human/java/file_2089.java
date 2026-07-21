import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

class PrimeUtil {

	private static boolean[] sieve;

	static {
		int sieveSize = 10000007;
		sieve = new boolean[sieveSize + 1];
		Arrays.fill(sieve, 2, sieveSize + 1, true);

		for (int i = 2; i * i <= sieveSize; i += (i > 2) ? 2 : 1) {
			if (!sieve[i]) {
				continue;
			}

			for (int j = i * i; j <= sieveSize; j += i) {
				sieve[j] = false;
			}
		}
	}

	public static boolean isPrimeBySieve(int n) {
		return sieve[n];
	}

	public static boolean isPrime(long n) {
		if (n < 2L) {
			return false;
		} else if (n == 2L) {
			return true;
		}

		for (long i = 3L; i * i <= n; i += 2) {
			if (n % i == 0L) {
				return false;
			}
		}
		return true;
	}

	public static HashMap<Long, Long> factorize(long n) {
		HashMap<Long, Long> res = new HashMap<Long, Long>();
		for (long i = 2L; i * i <= n; i += (i > 2L) ? 2L : 1L) {
			if (!isPrimeBySieve((int) i)) {
				continue;
			}

			long cnt = 0;
			while (n % i == 0L) {
				n /= i;
				++cnt;
			}

			if (cnt > 0) {
				res.put(i, cnt);
			}
		}

		if (n > 1L) {
			res.put(n, 1L);
		}
		return res;
	}

}

public class Main {

	public static void main(String[] args) {
		long[] y = new long[50];
		for (int i = 1; i < 50; ++i) {
			y[i] = i + y[i - 1];
		}

		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		HashMap<Long, Long> factorMap = PrimeUtil.factorize(n);

		long ans = 0;
		for (long base : factorMap.keySet()) {
			long index = factorMap.get(base);
			for (int i = 49; i >= 0; --i) {
				if (index < y[i]) {
					continue;
				}

				ans += i;
				break;
			}
		}

		System.out.println(ans);
	}

}
