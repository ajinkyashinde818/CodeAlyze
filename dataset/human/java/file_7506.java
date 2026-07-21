import java.util.Scanner;

public class Main {
	char[] c;
	int[] dp;
	char[][] w = { "dream".toCharArray(),
			"dreamer".toCharArray(),
			"erase".toCharArray(),
			"eraser".toCharArray() };

	int dp(int k) {
		if (c.length <= k) {
			return 1;
		}
		if (dp[k] != 0) {
			return dp[k];
		}

		int ret = -1;
		for (int i = 0; i < 4; i++) {
			if (check(k, i)) {
				ret = Math.max(ret, dp(k + w[i].length));
			}
		}

		return dp[k] = ret;
	}

	boolean check(int i, int k) {
		for (int j = 0; j < w[k].length; j++) {
			if (c.length <= i + j) {
				return false;
			}
			if (c[i + j] != w[k][j]) {
				return false;
			}
		}
		return true;
	}

	void run() {
		Scanner sc = new Scanner(System.in);

		c = sc.next().toCharArray();
		dp = new int[c.length];
		System.out.println(dp(0) == 1 ? "YES" : "NO");
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
