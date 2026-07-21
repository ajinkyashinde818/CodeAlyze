import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		sc.close();

		Map<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < n; i++) {
			char c = s.charAt(i);
			if (map.containsKey(c)) {
				map.put(c, map.get(c) + 1);
			} else {
				map.put(c, 1);
			}
		}

		long ans = 1L;
		for (int val : map.values()) {
			ans *= (val + 1);
			ans %= 1000000007;
		}
		if (ans == 0) {
			System.out.println(1000000006);
		} else {
			System.out.println(ans - 1);
		}
	}
}
