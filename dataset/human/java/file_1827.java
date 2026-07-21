import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int d = in.nextInt();
            int g = in.nextInt() / 100;
            int[] p = new int[d];
            int[] c = new int[d];
            for (int i = 0; i < d; i++) {
                p[i] = in.nextInt();
                c[i] = in.nextInt() / 100;
            }

            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < 1 << d; i++) {
                int cnt = 0;
                int sum = 0;
                for (int j = 0; j < d; j++) {
                    if ((i >> j & 1) == 1) {
                        cnt += p[j];
                        sum += p[j] * (j + 1) + c[j];
                    }
                }
                for (int j = d - 1; j >= 0; j--) {
                    if (sum < g && (i >> j & 1) == 0) {
                        int tmp = Math.min(p[j], (g - sum + j) / (j + 1));
                        cnt += tmp;
                        sum += tmp * (j + 1);
                    }
                }

                ans = Math.min(ans, cnt);
            }

            out.println(ans);
        }

    }

    static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }
}
