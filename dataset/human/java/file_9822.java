import java.util.Scanner;

public class Main {
	static int dp[][];

	static int solve(int i, int C[], int A[][], int X, int curUnd[], int M, int price) {
		int flag = 0;
		for (int j = 0; j < curUnd.length; j++) {
			if (curUnd[j] < X) {
				flag = 1;
			}
		}
		if (flag == 0)
			return price;
		if (i < 0)
			return Integer.MAX_VALUE;
		int a = solve(i - 1, C, A, X, curUnd, M, price);
		int newCur[] = new int[M];
		for (int j = 0; j < newCur.length; j++)
			newCur[j] = curUnd[j] + A[i][j];
		int b = solve(i - 1, C, A, X, newCur, M, price + C[i]);
		return Integer.min(a, b);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt(), X = sc.nextInt();
		int C[] = new int[N], A[][] = new int[N][M];
		for (int i = 0; i < N; i++) {
			C[i] = sc.nextInt();
			for (int j = 0; j < M; j++)
				A[i][j] = sc.nextInt();
		}
		dp = new int[N][2];
		dp[0][0] = 0;
		int curUnd[] = new int[M];
		int ans = solve(N - 1, C, A, X, curUnd, M, 0);
		System.out.println((ans != Integer.MAX_VALUE) ? ans : -1);
		sc.close();
	}
}
