import java.util.Arrays;
import java.util.Scanner;

public class Main {
	Scanner sc;

	int nn = 1121;
	int kk = 15;
	int dp[][] = new int[nn][kk];

	Main() {
		sc = new Scanner(System.in);

		dp[0][0] = 1;

		boolean pp[] = new boolean[nn];
		Arrays.fill(pp, true);
		pp[0] = false;
		pp[1] = false;
		pp[2] = true;

		for (int i = 0; i < nn; i++) {
			if (pp[i]) {
				for (int j = i << 1; j < nn; j += i) {
					pp[j] = false;
				}
			}
		}
		// System.out.println(Arrays.toString(pp));
		for (int k = 0; k < nn; k++) {
			if (!pp[k]) {
				continue;
			}
			for (int i = nn - 1; i >= k; i--) {
				for (int j = 14; j > 0; j--) {
					dp[i][j] += dp[i - k][j - 1];
				}
			}
		}
//		 System.out.println(Arrays.deepToString(dp));
	}

	void run() {
		for (;;) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			if (n + k == 0) {
				break;
			}
			System.out.println(dp[n][k]);

		}
	}

	public static void main(String args[]) {
		Main m = new Main();
		m.run();
	}
}
