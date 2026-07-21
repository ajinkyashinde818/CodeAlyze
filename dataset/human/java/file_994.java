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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            long c = in.nextLong();
            long[] x = new long[n], v = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextLong();
                v[i] = in.nextLong();
            }

            long ans = solve(x, v, c);
            for (int i = 0; i < n; i++) {
                x[i] = c - x[i];
            }
            for (int i = 0, j = n - 1; i < j; i++, j--) {
                long tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;

                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
            out.println(Math.max(ans, solve(x, v, c)));
        }

        private long solve(long[] x, long[] v, long c) {
            int n = x.length;
            long[] sufMax = new long[n + 1];
            long cur = 0;
            for (int i = n - 1; i >= 0; i--) {
                cur += v[i];
                sufMax[i] = Math.max(sufMax[i + 1], cur - (c - x[i]));
            }

            cur = 0;
            long ans = 0;
            for (int i = 0; i < n; i++) {
                cur += v[i];
                ans = Math.max(ans, cur - x[i]);
                ans = Math.max(ans, cur - 2 * x[i] + sufMax[i + 1]);
            }
            return ans;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
