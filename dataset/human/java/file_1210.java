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
 * @author SimplyDivine
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            long a[] = new long[n];
            long sum = 0;
            long pre[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
                if (i == 0) pre[i] = a[i];
                else
                    pre[i] = pre[i - 1] + a[i];
                sum += a[i];
            }
            //System.out.println(Arrays.toString(pre));
            long diff = Long.MAX_VALUE;
            for (int i = 0; i < n - 1; i++) {
                diff = Math.min(diff, Math.abs(2 * pre[i] - sum));

            }
            out.println(diff);

        }

    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream i) {
            br = new BufferedReader(new
                    InputStreamReader(i));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
