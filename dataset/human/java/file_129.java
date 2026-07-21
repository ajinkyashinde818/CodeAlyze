import java.util.Scanner;

public class Main {

    static final long inf = (long)1e16;

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        for(int i = 1; i <= n; i++){
            a[i] = sc.nextInt();
        }
        long[][] dp = new long[n + 1][2];
        dp[1][0] = a[1];
        dp[1][1] = -inf;
        for(int i = 2; i <= n; i++){
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]) + a[i];
            long A = dp[i - 1][0] - 2L * a[i - 1] - a[i];
            long B = dp[i - 1][1] + 2L * a[i - 1] - a[i];
            dp[i][1] = Math.max(A, B);
        }
        System.out.print(Math.max(dp[n][0], dp[n][1]));
    }
}
