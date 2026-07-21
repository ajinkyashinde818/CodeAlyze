import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		a[0] = sc.nextInt();
		for (int i = 1; i < n; i++) {
			a[i] = a[i - 1] + sc.nextInt();
		}
		sc.close();

		long ans = Long.MAX_VALUE;
		for (int i = 0; i < n - 1; i++) {
			long x = a[i];
			long y = a[n - 1] - a[i];
			ans = Math.min(ans, Math.abs(x - y));
		}
		System.out.println(ans);
	}
}
