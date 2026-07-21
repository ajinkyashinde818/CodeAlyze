import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author littlesheep
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long sum = 0;
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextLong();
                sum += a[i];
            }
            if (n == 1) {
                out.println("YES");
                return;
            }

            if (sum % ((1L + n) * n / 2) != 0) {
                out.println("NO");
                return;
            }

            long times = sum / ((1L + n) * n / 2);
            long[] b = new long[n];
            long coef = -(n - 1);
            long bSum = 0;
            for (int i = 0; i < n; ++i) {
                long delta = a[i] - a[(i + n - 1) % n];
                if ((delta - times) % (coef - 1) != 0) {
                    out.println("NO");
                    return;
                }
                b[i] = (delta - times) / (coef - 1);
                if (b[i] < 0) {
                    out.println("NO");
                    return;
                }
                bSum += b[i];
            }

            if (bSum == times) {
                out.println("YES");
            } else {
                out.println("NO");
            }

        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
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
