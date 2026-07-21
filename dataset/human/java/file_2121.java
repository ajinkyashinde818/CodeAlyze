import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		long n = Long.parseLong(br.readLine());

		Map<Long, Integer> map = primeFactorization(n);

		long ans = 0;
		for (long key : map.keySet()) {
			int i = 1;
			while (true) {
				if (map.get(key) >= i) {
					ans++;
					map.put(key, map.get(key) - i);
					i++;
				} else {
					break;
				}
			}
		}
		System.out.println(ans);

	}

	static Map<Long, Integer> primeFactorization(long n) {
		Map<Long, Integer> map = new HashMap<>();
		for (long p = 2; p * p <= n; p++) {
			if (n % p != 0)
				continue;
			int cnt = 0;
			while (n % p == 0) {
				cnt++;
				n = n / p;
			}
			map.put(p, cnt);
		}
		if (n > 1)
			map.put(n, 1);

		return map;
	}
}
