import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jaynil
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CTypicalStairs solver = new CTypicalStairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTypicalStairs {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            long mod = 10000_0000_7;
            long dp[] = new long[n + 1];
            dp[0] = 1;
            HashSet<Integer> hs = new HashSet<>();
            for (int i = 0; i < m; i++) hs.add(in.nextInt());
            if (!hs.contains(1)) dp[1] = 1;
            for (int i = 2; i <= n; i++) if (!hs.contains(i)) dp[i] = (dp[i] + dp[i - 1] + dp[i - 2] + mod) % mod;
            out.println(dp[n]);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
