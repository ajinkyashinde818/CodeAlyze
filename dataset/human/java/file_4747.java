import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            String N = sc.next();

            long[][] dp = new long[2][N.length() + 1];
            dp[0][0] = 0;
            dp[1][0] = 1;

            for (int i = 0; i < N.length(); i++) {
                int n = N.charAt(i) - '0';

                dp[0][i + 1] = Math.min(dp[0][i] + n, dp[1][i] + 10 - n);
                dp[1][i + 1] = Math.min(dp[0][i] + n + 1, dp[1][i] + 10 - n - 1);
            }

            System.out.println(dp[0][N.length()]);
        }
    }

}
