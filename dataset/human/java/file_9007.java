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
        CTypicalStairs solver = new CTypicalStairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTypicalStairs {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int mod = 1_000_000_007;
            int n = in.nextInt();
            int m = in.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < m; i++)
                arr[i] = in.nextInt();
            //dp[k] : nb of steps to get to get to the N-1th from the kth step
            //dp[k] = if arr[k]==0 => 0 else dp[k+1] + dp[k+2]
            //dp[n-1] = 1
            long[] dp = new long[n + 2];
            dp[n + 1] = 0;
            dp[n] = 1;
            int cur = m == 0 ? -1 : arr[m - 1];
            int indM = m - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (i == cur) {
                    indM--;
                    if (indM >= 0)
                        cur = arr[indM];
                    dp[i] = 0;
                } else {
                    dp[i] = dp[i + 1] + dp[i + 2];
                    dp[i] %= mod;
                }
            }
            out.println(dp[0]);
        }

    }
}
