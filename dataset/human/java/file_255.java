import java.util.Scanner;

public class Main {
	private static final boolean TEST = false;
	private static final int TEST_NUM = 3;

	public static void main(String[] args) {
		int N = 0;
		Integer[] A = {};
		Integer[] A1 = {-10,5,-4};
		Integer[] A2 = {10,-4,-8,-11,3};
		Integer[] A3 = {-1000000000,1000000000,-1000000000,1000000000,-1000000000,0,1000000000,
				-1000000000,1000000000,-1000000000,1000000000};

		switch(TEST_NUM) {
		case 1:
			N = 3;
			A = A1;
			break;
		case 2:
			N = 5;
			A = A2;
			break;
		case 3:
			N = 11;
			A = A3;
			break;
		default:
				break;
		}
		if(!TEST) {
			Scanner sc = new Scanner(System.in);
			N = sc.nextInt();
			A = new Integer[N + 1];
			for(int i = 0; i < N; i++) {
				A[i] = sc.nextInt();
			}
			sc.close();
		}
		solve(A, N);
	}

	static void solve(Integer[] A, int N) {
		// i番目までにおいてのスコア
		// j=0のときAiを反転しておらず、j=1のときAiを反転している状態

		// 初期化
		long[][] dp = new long[N + 1][2];
		dp[1][0] = A[0];
		dp[1][1] = -1 * A[0];

		for(int i = 1; i < N; i++) {
			dp[i + 1][0] = Math.max(dp[i][0] + A[i], dp[i][1] - A[i]);
			dp[i + 1][1] = Math.max(dp[i][0] - A[i], dp[i][1] + A[i]);
 		}

		System.out.println(dp[N][0]);
	}
}
