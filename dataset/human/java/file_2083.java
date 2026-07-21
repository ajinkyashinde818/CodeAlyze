import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		TreeMap<Long, Integer> map = primeFactorize(n);
		int ans = 0;
		for (Entry<Long, Integer> entry : map.entrySet()) {
			int value = entry.getValue();
			int index = 1;
			while (value >= index) {
				ans++;
				value -= index;
				index++;
			}
		}
		System.out.println(ans);
		sc.close();
	}

	static TreeMap<Long, Integer> primeFactorize(long n) {
		TreeMap<Long, Integer> map = new TreeMap<>();
		if (n < 2) {
			return map;
		}

		for (long i = 2; i * i <= n; i++) {
			if (n % i != 0) {
				continue;
			}
			int times = 0;
			while (n % i == 0) {
				times++;
				n /= i;
			}
			map.put(i, times);
		}
		if (n != 1) {
			map.put(n, 1);
		}
		return map;
	}
}
