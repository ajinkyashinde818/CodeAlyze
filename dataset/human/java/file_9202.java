import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        static final int mod = 1000000007;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int N = Integer.parseInt(in.next());
            int M = Integer.parseInt(in.next());
            int[] a = new int[N];
            boolean[] broken = new boolean[N + 1];
            for (int i = 0; i < M; i++) {
                a[i] = Integer.parseInt(in.next());
                broken[a[i]] = true;
            }
            int[] dp = new int[N + 1];
//        Arrays.fill(dp,0);

            //dp[x]=dp[x-1]+dp[x-2]
            dp[0] = 1;
            if (broken[1]) {
                dp[1] = 0;
            } else {
                dp[1] = 1;
            }
            for (int i = 2; i <= N; i++) {
                if (!broken[i - 1]) dp[i] += dp[i - 1];
                if (!broken[i - 2]) dp[i] += dp[i - 2];
                dp[i] %= mod;
            }

            out.println(dp[N]);

        }

    }
}
