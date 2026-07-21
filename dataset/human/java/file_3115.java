import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			int T = Integer.parseInt(in.readLine());
			for (int i = 0; i < T; i++) {
				int N = Integer.parseInt(in.readLine());
				String str = in.readLine();
				boolean[][] book = new boolean[N + 1][2];
				for (int j = 0; j < 4 * N; j++) {
					if (str.charAt(j) == 'Y') {
						book[(j % (2 * N) + 1) / 2][j / (2 * N)] = true;
					}
				}
				int[][] dp = new int[N + 2][2];
				dp[N + 1][0] = -1;
				dp[N + 1][1] = 0;
				for (int j = N; j >= 0; j--) {
					if (!book[j][0] && !book[j][1]) {
						dp[j][0] = dp[j + 1][0] + 1;
						dp[j][1] = dp[j + 1][1] + 1;
					} else if (book[j][0] && book[j][1]) {
						dp[j][0] = 3 + dp[j + 1][1];
						dp[j][1] = 3 + Math.min(dp[j + 1][0], dp[j + 1][1]);
					} else if (book[j][0]) {
						dp[j][0] = dp[j][1] = 2 + Math.min(dp[j + 1][0], dp[j + 1][1]);
					} else {
						dp[j][0] = 3 + dp[j + 1][1];
						dp[j][1] = 2 + dp[j + 1][1];
					}
				}
				System.out.println(dp[0][0]);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
