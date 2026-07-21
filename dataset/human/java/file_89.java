import java.util.Scanner;

public class Main {
    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long sum = 0;
        long min = Long.MAX_VALUE;
        int count = 0;
        for (int i = 0; i < n; i++) {
            long a = sc.nextLong();
            sum += Math.abs(a);
            min = Math.min(min, Math.abs(a));
            if (a < 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            System.out.println(sum);
        } else {
            System.out.println(sum - 2 * min);
        }
    }

    void run2() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] as = new long[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextLong();
        }
        long[][] dp = new long[n][2];
        dp[0][0] = as[0];
        dp[0][1] = -as[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.max(dp[i - 1][0] + as[i], dp[i - 1][1] - as[i]);
            dp[i][1] = Math.max(dp[i - 1][0] - as[i], dp[i - 1][1] + as[i]);
        }
        System.out.println(dp[n - 1][0]);
    }

    public static void main(String[] args) {
        new Main().run2();
    }
}
