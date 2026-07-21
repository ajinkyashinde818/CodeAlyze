import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n - 1];
		int answer = 0;

		Map<Integer, Integer> m = new HashMap<>();
		a[0] = sc.nextInt();

		for (int i = 1; i < n; i++) {
			a[i] = sc.nextInt();
			m.put(a[i - 1], a[i]);
		}
		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
			answer += b[i];
		}

		for (int i = 0; i < n - 1; i++) {
			c[i] = sc.nextInt();
			if (!m.containsKey(i + 1)) continue;
			if (m.get(i + 1) == i + 2) {
				answer += c[i];
			}
		}

		System.out.println(answer);
	}
}
