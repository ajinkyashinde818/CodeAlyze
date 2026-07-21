import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws Exception {
		final Scanner sc = new Scanner(System.in);
		String nn = sc.next();
		char[] n = new StringBuilder(nn).reverse().append(0).toString().toCharArray();

		int[][] dp = new int[n.length + 1][2];
		for (int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i], 100000000);
		}
		dp[0][0] = 0;
		for (int i = 0; i < n.length; i++) {
			for (int j = 0; j < 2; j++) {
				int x = Integer.parseInt(String.valueOf(n[i]));
				x += j;
				for (int a = 0; a < 10; a++) {
					int b = a - x;
					if (b < 0) {
						b += 10;
						dp[i + 1][1] = Math.min(dp[i + 1][1], dp[i][j] + a + b);
					} else {
						dp[i + 1][0] = Math.min(dp[i + 1][0], dp[i][j] + a + b);
					}
				}
			}
		}

		System.out.println(dp[n.length][0]);
	}
}
