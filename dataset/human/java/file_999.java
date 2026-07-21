import java.util.*;

public class Main {
	static Scanner scanner = new Scanner(System.in);

	public static void main(String[]$) {
		int n = scanner.nextInt();
		long c = scanner.nextLong();
		long[][] a = new long[n][2];
		long[] a1 = new long[n];
		long[] a2 = new long[n];
		long[] b1 = new long[n];
		long[] b2 = new long[n];
		long sum = 0;
		for (int i = 0; i < n; i++) {
			long x = scanner.nextLong();
			sum += a[i][1] = scanner.nextInt();
			a1[i] = sum - x * 2;
			a2[i] = sum - x;
			if (i > 0) {
				a2[i] = Math.max(a2[i], a2[i - 1]);
			}
			a[i][0] = c - x;
		}
		sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			sum += a[i][1];
			b1[i] = sum - a[i][0] * 2;
			b2[i] = sum - a[i][0];
			if (i < n - 1) {
				b2[i] = Math.max(b2[i], b2[i + 1]);
			}
		}
		long ans = Math.max(0, Math.max(a2[0], b2[0]));
		for (int i = 1; i < n; i++) {
			ans = Math.max(ans, Math.max(Math.max(a1[i - 1] + b2[i], b1[i] + a2[i - 1]), Math.max(a2[i], b2[i])));
		}
		System.out.println(ans);
	}
}
