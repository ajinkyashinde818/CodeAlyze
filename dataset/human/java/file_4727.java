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
 * @author Jaynil
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EPayment solver = new EPayment();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPayment {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String x = in.next();
            long ans = 0;
            int d[] = new int[x.length() + 1];
            int dp[][] = new int[x.length() + 1][2];
            for (int i = 0; i < x.length(); i++) d[i + 1] = x.charAt(i) - '0';
            dp[x.length()][0] = d[x.length()];
            dp[x.length()][1] = 10 - d[x.length()];
            for (int i = x.length() - 1; i >= 0; i--) {
                dp[i][0] = Math.min(dp[i + 1][0] + d[i], dp[i + 1][1] + 1 + d[i]);
                dp[i][1] = Math.min(dp[i + 1][0] + 10 - d[i], dp[i + 1][1] - 1 + 10 - d[i]);
            }
            out.println(Math.min(dp[0][0], dp[0][1]));
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

    }
}
