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
 * @author Abhas Jain
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
            int n = in.ni();
            long mod = (long) 1e9 + 7L;
            String s = in.next();
            int[] ar = new int[26];
            for (int i = 0; i < n; ++i) ar[s.charAt(i) - 'a']++;
            long ans = 1;
            for (int i = 0; i < 26; ++i) {
                ans = (ans % mod * (ar[i] + 1L) % mod) % mod;
            }
            ans--;
            if (ans < 0) ans += mod;
            out.print(ans);
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

        public int ni() {
            return Integer.parseInt(next());
        }

    }
}
