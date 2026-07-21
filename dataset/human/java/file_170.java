import java.util.Scanner;

import static java.lang.Math.max;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long A[] = new long[N+1];

        for (int i = 1; i < N+1; i++) {
            A[i] = sc.nextInt();
        }

        long dp[][] = new long[N+1][2];
        dp[0][0] = 0;
        dp[0][1] = -100000000000000000L;

        for (int i = 0; i < N; i++) {
            dp[i + 1][0] = max(dp[i][0] + A[i+1], dp[i][1] - A[i+1]);
            dp[i + 1][1] = max(dp[i][0] - A[i+1], dp[i][1] + A[i+1]);
        }

        System.out.println(dp[N][0]);
    }
}
