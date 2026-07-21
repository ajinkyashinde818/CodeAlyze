import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		long[] cum = new long[n];
		a[0] = cum[0] = sc.nextLong();
		for(int i = 1; i < n; i++) {
			a[i] = sc.nextLong();
			cum[i] = cum[i - 1] + a[i];
		}
		long ans = Long.MAX_VALUE;
		for(int i = 0; i < n - 1; i++) {
			ans = Math.min(ans, Math.abs(cum[i] - cum[n - 1] + cum[i]));
		}
		System.out.println(ans);
	}
}
