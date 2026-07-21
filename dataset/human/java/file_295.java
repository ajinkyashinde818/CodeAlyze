import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] al = new long[n];
        for(int i = 0 ; i < n; i++){
            al[i] = sc.nextLong();
        }
        long[][] dp = new long[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = -Integer.MAX_VALUE;
        for(int i = 1; i <= n; i++){
            dp[i][0] = Math.max(dp[i-1][0] + al[i-1], dp[i-1][1] - al[i-1]);
            dp[i][1] = Math.max(dp[i-1][0] - al[i-1], dp[i-1][1] + al[i-1]);
        }
        System.out.println(dp[n][0]);
    }
}
