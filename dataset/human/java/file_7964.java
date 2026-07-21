import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	Scanner sc = new Scanner(System.in);
	void run() {

		int M = 1120;
		boolean[] isPrime = new boolean[M + 1];
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i <= M; i++) {
			if (!isPrime[i]) continue;
			for (int j = i * 2; j <= M; j += i) isPrime[j] = false;
		}

		List<Integer> l = new ArrayList<>();
		for (int i = 0; i <= M; i++) if (isPrime[i]) l.add(i);
		int[] p = new int[l.size()];
		for (int i = 0; i < l.size(); i++) p[i] = l.get(i);

		int[][] dp = new int[15][M + 1];
		dp[0][0] = 1;

		for (int i = 0; i < p.length; i++) {
			for (int j = 13; j >= 0; j--) {
				for (int k = 0; k < M; k++) {
					if (k + p[i] <= M) dp[j + 1][k + p[i]] += dp[j][k];
				}
			}
		}

		for (;;) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			if ((n | k) == 0)
				return;
			System.out.println(dp[k][n]);
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
