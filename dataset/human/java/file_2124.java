import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        sc.close();

        Map<Long, Integer> map = bunkai(n);
        int ans = 0;
        for (int v : map.values()) {
        	int sum = 0;
        	for (int i = 1; i < 50; i++) {
				sum += i;
				if (sum > v) {
					break;
				}
				ans++;
			}
        }
        System.out.println(ans);
    }

	static Map<Long, Integer> bunkai(long n) {
		Map<Long, Integer> soinsu = new HashMap<>();
		int end = (int) Math.sqrt(n);
		long d = 2;
		while (n > 1) {
			if (n % d == 0) {
				n /= d;
				if (soinsu.containsKey(d)) {
					soinsu.put(d, soinsu.get(d) + 1);
				} else {
					soinsu.put(d, 1);
				}
				end = (int) Math.sqrt(n);
			} else {
				if (d > end) {
					d = n - 1;
				}
				d++;
			}
		}
		return soinsu;
	}
}
