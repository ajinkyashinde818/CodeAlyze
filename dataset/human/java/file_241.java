import java.util.Scanner;

public class Main {

	public static int A[];
	public static int run = 0;

	public static void main(String[] args) {
		//Input
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());

		A = new int[N];
		for(int i = 0 ; i < N ; i++ ) {
			A[i] = Integer.parseInt(sc.next());
		}

		sc.close();

		//Logic
		long[][] dp = new long[N][2];
		dp[0][0] = A[0];
		dp[0][1] = -1*A[0];

		for(int i = 1 ; i < N ; i++) {
			dp[i][0] = Math.max(dp[i-1][0] + A[i], dp[i-1][1] - A[i]);
			dp[i][1] = Math.max(dp[i-1][0] - A[i], dp[i-1][1] + A[i]);
		}

		long answer = dp[N-1][0];

		//Output
		System.out.println(answer);

	}

}
