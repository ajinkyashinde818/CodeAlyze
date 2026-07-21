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
        DFlippingSigns solver = new DFlippingSigns();
        solver.solve(1, in, out);
        out.close();
    }

    static class DFlippingSigns {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            long[] a = new long[n];

            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            long answer = 0;
            int negative = 0;
            for (long x : a) {
                if (x < 0) {
                    negative++;
                }
            }

            long min = Long.MAX_VALUE;
            for (long x : a) {
                answer += Math.abs(x);
                min = Math.min(min, Math.abs(x));
            }
            if (negative % 2 == 1) {
                answer -= 2 * min;
            }

            out.println(answer);
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
