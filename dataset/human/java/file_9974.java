import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int[] C = new int[N];
		int[][] A = new int[N][M];
		for (int i = 0; i < N; i++) {
			C[i] = sc.nextInt();
			for (int j = 0; j < M; j++) {
				A[i][j] = sc.nextInt();
			}
		}
		int res = Integer.MAX_VALUE;
		loop: for (int i = 0; i < (1 << N); i++) {
			int[] dp = new int[M];
			int tmpRes = 0;
			for (int j = 0; j < N; j++) {
				if (((i >> j) & 1) == 1) {
					tmpRes += C[j];
					for (int j2 = 0; j2 < dp.length; j2++) {
						dp[j2] += A[j][j2];
					}
				}
			}
			for (int j2 = 0; j2 < dp.length; j2++) {
				if (dp[j2] < X) {
					continue loop;
				}
			}
			if (res > tmpRes) {
				res = tmpRes;
			}
		}
		if (res == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(res);
		}
	}
}
