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
        DStringFormation solver = new DStringFormation();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStringFormation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String x = in.next();
            int q = in.nextInt();
            StringBuilder a[] = new StringBuilder[2];
            a[0] = new StringBuilder();
            a[1] = new StringBuilder();
            int r = 0;
            while (q-- > 0) {
                int t = in.nextInt();
                if (t == 1) {
                    r++;
                    continue;
                }
                int p = in.nextInt() - 1;
                String c = in.next();
                a[(p + r) % 2].append(c);
            }
            StringBuilder ans = new StringBuilder();
            if (r % 2 == 0) {
                ans.append(a[0].reverse());
                ans.append(x);
                ans.append(a[1]);
            } else {
                ans.append(a[1].reverse());
                ans.append(new StringBuilder(x).reverse().toString());
                ans.append(a[0]);
            }
            out.println(ans.toString());
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
