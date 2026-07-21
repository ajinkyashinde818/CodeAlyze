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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int N;
        long C;
        long[] X;
        int[] V;
        long[] prefR;
        long[] prefL;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            N = in.nextInt();
            C = in.nextLong();
            X = new long[N + 1];
            V = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                X[i] = in.nextLong();
                V[i] = in.nextInt();
            }
            long ans = 0;

            long[] R = new long[N + 1];
            long[] L = new long[N + 1];

            R[0] = 0;
            for (int i = 1; i <= N; i++) {
                R[i] = R[i - 1] - (X[i] - X[i - 1]) + V[i];
            }

            L[0] = 0;

            for (int i = N; i >= 1; i--) {
                if (i == N) {
                    L[N - i + 1] = -(C - X[i]) + V[i];
                } else {
                    L[N - i + 1] = L[N - i] - (X[i + 1] - X[i]) + V[i];
                }
            }

            prefL = new long[N + 1];
            prefR = new long[N + 1];

            for (int i = 1; i <= N; i++) {
                prefL[i] = Math.max(prefL[i - 1], L[i]);
            }

            for (int i = 1; i <= N; i++) {
                prefR[i] = Math.max(prefR[i - 1], R[i]);
            }

            long ansRight = goRight(L.clone(), R.clone());
            long ansLeft = goLeft(L.clone(), R.clone());
            out.println(Math.max(ans, Math.max(ansRight, ansLeft)));
        }

        private long goLeft(long[] L, long[] R) {
            long ans = 0;
            for (int l = 0; l <= N; l++) {
                long total = L[l];
                long distBack = l == 0 ? 0 : (C - X[N - l + 1]);

                ans = Math.max(ans, total);

                total -= distBack;

//            for (int r = 0; r <= N - l; r++) {
//                ans = Math.max(ans, total + R[r]);
//            }

                ans = Math.max(ans, total + prefR[N - l]);
            }
            return ans;
        }

        private long goRight(long[] L, long[] R) {
            long ans = 0;
            for (int r = 0; r <= N; r++) {
                long total = R[r];
                long distBack = X[r];

                ans = Math.max(ans, total);

                total -= distBack;

//            for (int l = 0; l <= N - r; l++) {
//                ans = Math.max(ans, total + L[l]);
//            }
                ans = Math.max(ans, total + prefL[N - r]);
            }
            return ans;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
