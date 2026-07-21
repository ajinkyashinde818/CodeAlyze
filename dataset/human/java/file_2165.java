import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		double sqrt = Math.sqrt(N);
		sc.close();
		Map<Long, Integer> map = new TreeMap<Long, Integer>();
		for (long i = 2; i <= sqrt; i++) {
			if (N == 1) {
				break;
			}
			while (N % i == 0) {
				// 因数をmapに記録
				if (map.containsKey(i)) {
					map.put(i, map.get(i) + 1);
				} else {
					map.put(i, 1);
				}
				N /= i;
			}
		}
		if (N != 1) {
			map.put(N, 1);
		}
		long ans = 0;
		for (int cnt : map.values()) {
			int order = 1;
			int sum = 1;
			while (true) {
				if (cnt - sum >= 0) {
					ans++;
				} else {
					break;
				}
				order++;
				sum = sum + order;
			}
		}
		System.out.println(ans);
	}
}
