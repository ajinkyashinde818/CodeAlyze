import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        long[] count = new long[26];
        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        long mod = 1000000007L;
        long[] dp = new long[27];
        dp[0] = 1L;
        for (int i = 0; i < 26; i++) {
            dp[i + 1] += dp[i];
            dp[i + 1] %= mod;

            dp[i + 1] += dp[i] * count[i];
            dp[i + 1] %= mod;
        }
        System.out.println((dp[26] + mod - 1) % mod);
    }
}
