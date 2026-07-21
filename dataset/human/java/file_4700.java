import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] chars = sc.next().toCharArray();
        int length = chars.length;
        int[] arr = new int[length + 1];
        for (int i = 1; i <= length; i++) {
            arr[i] = chars[i - 1] - '0';
        }
        int[][] dp = new int[length + 2][2];
        dp[length + 1][1] = 10;
        for (int i = length; i >= 0; i--) {
            dp[i][0] = Math.min(dp[i + 1][0] + arr[i], dp[i + 1][1] + arr[i] + 1);
            dp[i][1] = Math.min(dp[i + 1][0] + 10 - arr[i], dp[i + 1][1] + 10 - arr[i] - 1);
        }
        System.out.println(dp[0][0]);
    }
}
