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
 */
public class Main {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AColorfulSubsequence solver = new AColorfulSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class AColorfulSubsequence {

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();

            long[] chars = new long['z' - 'a' + 1];
            for (int i = 0; i < n; i++) {
                chars[s.charAt(i) - 'a']++;
            }
            long ans = 1;
            long MOD = (long) 1e9 + 7;
            for (int i = 0; i < 'z' - 'a' + 1; i++) {
                ans = (ans * (chars[i] + 1)) % MOD;
            }

            out.println((ans + MOD - 1) % MOD);
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
