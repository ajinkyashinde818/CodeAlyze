import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) throws Exception {
        try (BufferedInputStream in = new BufferedInputStream(System.in);
             PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out))) {

            Scanner sc = new Scanner(in);

            // 10:42-

            int mod = 1_000_000_007;
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] as = new int[m];

            Set<Integer> broken = new HashSet<>();
            for (int i = 0; i < as.length; i++) broken.add(sc.nextInt());

            int[] dp = new int[n + 1];
            dp[0] = 1;

            for (int i = 1; i <= n; i++) if (!broken.contains(i)) {
                dp[i] += dp[i - 1];
                dp[i] %= mod;
                if (i - 2 >= 0) dp[i] += dp[i - 2];
                dp[i] %= mod;
            }

            out.println(dp[n]);
        }
    }
}
