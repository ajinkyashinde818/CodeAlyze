import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
		}
		long[][] dp = new long[n + 1][2];
		dp[0][0] = 0;
		dp[0][1] = -1_000_000_009;
		for (int i = 1; i < n; i++) {
			dp[i][0] = Math.max(dp[i - 1][0] + a[i - 1], dp[i - 1][1] - a[i - 1]);
			dp[i][1] = Math.max(dp[i - 1][0] - a[i - 1], dp[i - 1][1] + a[i - 1]);
		}

		System.out.println(Math.max(dp[n - 1][0] + a[n - 1], dp[n - 1][1] - a[n - 1]));
	}
}
