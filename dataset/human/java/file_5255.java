import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n;
		int dp[][];
		int max;

		n = sc.nextInt();
		while (n != 0) {
			max = 0;
			dp = new int[n][n];

			for (int i = 0; i < n; i++) {
				String st = sc.next();
				for (int j = 0; j < n; j++) {
					if (st.charAt(j) == '.') {
						if (1 <= i && 1 <= j) {
							dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
						} else {
							dp[i][j] = 1;
						}
						if (max < dp[i][j]) {
							max = dp[i][j];
						}
					}
				}
			}

			System.out.println(max);

			n = sc.nextInt();
		}
	}
}
