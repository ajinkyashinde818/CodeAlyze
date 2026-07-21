import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i=0; i<n; i++) arr[i] = sc.nextInt();

        long[][] dp = new long[n+1][2];
        dp[0][1] = Integer.MIN_VALUE;

        for (int i=1; i<=n; i++) {
            dp[i][0] = Math.max(dp[i-1][0]+arr[i-1], dp[i-1][1]-arr[i-1]);
            dp[i][1] = Math.max(dp[i-1][0]-arr[i-1], dp[i-1][1]+arr[i-1]);
        }

//        System.out.println(Math.max(dp[n][0], dp[n][1]));
        System.out.println(Math.max(dp[n][0], 0));
//        System.out.println(Math.max(0, dp[n][1]));


    }

    int gcd(int m, int n) {
        if (n == 0) return m;
        return gcd(n, m%n);
    }


}
