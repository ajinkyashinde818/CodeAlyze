import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        long startTime = System.nanoTime();
        int t = 1;
        while (t-- > 0) {
            solveSimple();
        }
        long endTime = System.nanoTime();
        err.println("Execution Time : +" + (endTime - startTime) / 1000000 + " ms");
        exit(0);
    }

    static void solve() {
        int k = in.nextInt();
        int N = in.nextInt();
        int[] data = in.readAllInts(N, 1);
        int[] diff = new int[N + 1];
        for (int i = 1; i + 1 < data.length; i++) {
            diff[i] = data[i + 1] - data[i];
        }
        diff[0] = k - data[N];
        long sum = Arrays.stream(diff).sum();
        long ans = Long.MAX_VALUE;
        for (int i = 1; i < N + 1; i++) {
            if (i == N) {
                ans = Math.min(ans, sum - diff[i - 1]);
                ans = Math.min(ans, sum - diff[0]);
                continue;
            }
            ans = Math.min(ans, sum - diff[i - 1]);
            ans = Math.min(ans, sum - diff[i + 1]);
        }
        out.println(ans);
    }

    static void solveSimple() {
        int k = in.nextInt();
        int N = in.nextInt();
        int[] data = in.readAllInts(N, 1);
        int[] diff = new int[N + 1];
        for (int i = 1; i + 1 < data.length; i++) {
            diff[i] = data[i + 1] - data[i];
        }
        diff[0] = k - data[N] + data[1];
        long ans = Arrays.stream(diff).sum() - Arrays.stream(diff).max().getAsInt();
        out.println(ans);
    }

    static void debug(Object... args) {
        for (Object a : args) {
            out.println(a);
        }
    }

    static void y() {
        out.println("YES");
    }

    static void n() {
        out.println("NO");
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

        public int[] readAllInts(int n) {
            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt();
            }
            return p;
        }

        public int[] readAllInts(int n, int s) {
            int[] p = new int[n + s];
            for (int i = s; i < n + s; i++) {
                p[i] = in.nextInt();
            }
            return p;
        }

        public long[] readAllLongs(int n) {
            long[] p = new long[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt();
            }
            return p;
        }

        public long[] readAllLongs(int n, int s) {
            long[] p = new long[n + s];
            for (int i = s; i < n + s; i++) {
                p[i] = in.nextInt();
            }
            return p;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    static void exit(int a) {
        out.close();
        err.close();
        System.exit(a);
    }

    static InputStream inputStream = System.in;
    static OutputStream outputStream = System.out;
    static OutputStream errStream = System.err;
    static InputReader in = new InputReader(inputStream);
    static PrintWriter out = new PrintWriter(outputStream);
    static PrintWriter err = new PrintWriter(errStream);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

}
