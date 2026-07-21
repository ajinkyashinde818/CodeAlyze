import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[] broken = new boolean[n + 1];
        for (int i = 0; i < m; i++) {
            broken[sc.nextInt()] = true;
        }

        // 累積和的にDPする。抜けた段は0でSKIP
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0);
        dp[0] = 1;
        dp[1] = broken[1] ? 0 : 1; // 最初の段が壊れている可能性

        for (int i = 2; i <= n; i++) {
            if (broken[i]) {
                continue;
            }
            dp[i] = dp[i - 1] + dp[i - 2]; // 遷移元を累積和
            dp[i] %= 1000000007;
        }

        // 2段連続で壊れていないか
        boolean canNotUpStairs = false;
        for (int i = 1; i < broken.length; i++) {
            if (broken[i - 1] && broken[i]) {
                canNotUpStairs = true;
            }
        }

        if (canNotUpStairs) {
            System.out.println(0);
        } else {
            System.out.println(dp[dp.length - 1]);
        }
    }
}
