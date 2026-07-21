import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author teiwa
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        long bigInteger = 1_000_000_007;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            boolean[] brokenStairs = new boolean[n + 1];
            Arrays.fill(brokenStairs, true);
            for (int i = 0; i < m; i++) {
                int broken = in.nextInt();
                brokenStairs[broken] = false;
            }

            long[] dp = new long[n + 1];
            dp[0] = 1;
            for (int now = 0; now < n; now++) {
                for (int next = now + 1; next <= Math.min(n, now + 2); next++) {
                    if (brokenStairs[next]) {
                        dp[next] += dp[now];
                        dp[next] = dp[next] % bigInteger;
                    }
                }
            }
            out.println(dp[n]);
        }

    }
}
