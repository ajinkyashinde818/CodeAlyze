import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = scan.nextLong();
        }
        long[][] dp = new long[N][2];
        dp[0][0] = a[0];
        dp[0][1] = -a[0];
        for (int i = 1; i < N - 1; i++) {
            dp[i][0] = Math.max(dp[i-1][0] + a[i], dp[i-1][1] - a[i]);
            dp[i][1] = Math.max(dp[i-1][0] - a[i], dp[i-1][1] + a[i]);
        }
        long answer = dp[N-2][0]+a[N-1];
        answer = Math.max(answer, dp[N-2][1]-a[N-1]);
        System.out.println(answer);
    }
}
