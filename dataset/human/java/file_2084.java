import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long n = sc.nextLong();
		if (n == 1) {
			System.out.println(0);
			System.exit(0);
		}

		long sqrt = (long) Math.sqrt(n) + 1;
		long tmp = n;
		ArrayList<Long> primeFactorCount = new ArrayList<Long>();

		// prime factorization
		for (long i = 2; i < sqrt; i++) {
			if (tmp % i == 0) {
				long count = 0;
				while (tmp % i == 0) {
					count++;
					tmp /= i;
				}
				primeFactorCount.add(count); // only need exponent.
			}
		}
		// if tmp != 1, it's last prime factor.
		// if there is no prime factor, n is prime number.
		if (tmp != 1 || primeFactorCount.size() == 0)
			primeFactorCount.add((long) 1);

		int ansCount = 0;
		for (long exp : primeFactorCount) {
			long used = 0;
			while (exp > used) { // exponent > (1+2+3+...)
				ansCount++;
				used++;
				exp -= used;
			}
		}
		System.out.println(ansCount);
	}
}
