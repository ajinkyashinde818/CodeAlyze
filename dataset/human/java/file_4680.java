import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }

    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String S = scan.next();
        char[] d = S.toCharArray();
        int len = d.length;
        int[] digits = new int[len+1];
        digits[0] = 0;
        for (int i = 1; i <= len; i++) {
            digits[i] = d[i-1] - '0';
        }
        int[][] dp = new int[len+1][2];
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i <= len; i++) {
            dp[i][0] = Math.min(dp[i - 1][0] + digits[i], dp[i - 1][1] + 10 - digits[i]);
            dp[i][1] = Math.min(dp[i - 1][0] + digits[i] + 1, dp[i - 1][1] + 10 - digits[i] - 1);
        }
        System.out.println(dp[len][0]);
    }
}
