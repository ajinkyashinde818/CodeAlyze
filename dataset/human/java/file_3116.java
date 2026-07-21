import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	static boolean[][] need;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; ++i) {
			int N = sc.nextInt();
			String state = sc.next();
			need = new boolean[2][N + 1];
			for (int j = 0; j < 2 * N; ++j) {
				if (state.charAt(j) == 'Y') {
					need[0][(j + 1) / 2] = true;
				}
				if (state.charAt(j + 2 * N) == 'Y') {
					need[1][(j + 1) / 2] = true;
				}
			}
			int[] dp = new int[3];
			dp[1] = dp[2] = 1 << 28;
			for (int j = 0; j <= N; ++j) {
				int[] next = { Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE };
				if (need[1][j]) {
					next[0] = Math.min(next[0], dp[0] + 3);
					next[1] = Math.min(next[1], dp[0] + 2);
				} else if (need[0][j]) {
					next[0] = Math.min(next[0], dp[0] + 1);
					next[1] = Math.min(next[1], dp[0] + 1);
				} else {
					next[0] = dp[0];
					next[1] = Math.min(next[1], dp[0] + 1);
				}
				next[2] = Math.min(next[2], dp[0] + 2);

				if (need[0][j] && need[1][j]) {
					next[1] = Math.min(next[1], dp[1] + 2);
					next[0] = Math.min(next[0], dp[1] + 2);
					next[2] = Math.min(next[2], dp[1] + 2);
				} else if (need[0][j] || need[1][j]) {
					next[1] = Math.min(next[1], dp[1] + 1);
					next[0] = Math.min(next[0], dp[1] + 1 + (need[1][j] ? 1 : 0));
					next[2] = Math.min(next[2], dp[1] + 1 + (need[0][j] ? 1 : 0));
				} else {
					next[1] = Math.min(next[1], dp[1]);
					next[0] = Math.min(next[0], dp[1] + 1);
					next[2] = Math.min(next[2], dp[1] + 1);
				}

				if (need[0][j]) {
					next[2] = Math.min(next[2], dp[2] + 3);
					next[1] = Math.min(next[1], dp[2] + 2);
				} else if (need[1][j]) {
					next[2] = Math.min(next[2], dp[2] + 1);
					next[1] = Math.min(next[1], dp[2] + 1);
				} else {
					next[2] = Math.min(next[2], dp[2]);
					next[1] = Math.min(next[1], dp[2] + 1);
				}
				next[0] = Math.min(next[0], dp[2] + 2);

				++next[0];
				++next[1];
				++next[2];
				dp = next;
			}
			System.out.println(dp[0] - 1);
		}
	}
}
