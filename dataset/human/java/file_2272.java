import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		int N = sc.nextInt();
		int[] dp = new int[N + 2];
		for (int i = 0; i < N; ++i) {
			int a = Integer.parseInt(sc.next());
			int b = Integer.parseInt(sc.next());
			if (a < dp.length) {
				dp[a]++;
			}
			if (b + 1 < dp.length) {
				dp[b + 1]--;
			}
		}
		int ans = 0;
		for (int i = 1; i <= N+1; ++i) {
			dp[i] += dp[i - 1];
			if (dp[i] >= i - 1) ans = i - 1;
		}
		System.out.println(ans);
	}
}
