import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DStaticSushi solver = new DStaticSushi();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStaticSushi {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long c = in.nextLong();
            long[] x = new long[n + 1];
            long[] v = new long[n + 1];
            for (int i = 0; i < n; i++) {
                x[i + 1] = in.nextLong();
                v[i + 1] = in.nextLong();
            }

            // positive direction
            long[] balance = balance(n, x, v);

            // negative direction
            long[] xRev = new long[n + 1];
            long[] vRev = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                xRev[n + 1 - i] = c - x[i];
                vRev[n + 1 - i] = v[i];
            }
            long[] balanceRev = balance(n, xRev, vRev);

            long answer = 0;
            for (int i = 1; i <= n; i++) {
                answer = Math.max(answer, balance[i]);
                answer = Math.max(answer, balanceRev[i]);
                answer = Math.max(answer, balance[i] - x[i] + balanceRev[n - i]);
                answer = Math.max(answer, balanceRev[i] - xRev[i] + balance[n - i]);
            }

            out.println(answer);
        }

        long[] balance(int n, long[] x, long[] v) {
            long[] balance = new long[n + 1];
            balance[0] = 0;
            for (int i = 1; i <= n; i++) {
                balance[i] = balance[i - 1];
                balance[i] -= (x[i] - x[i - 1]);
                balance[i] += (v[i]);
            }

            for (int i = 1; i <= n; i++) {
                balance[i] = Math.max(balance[i], balance[i - 1]);
            }

            return balance;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
