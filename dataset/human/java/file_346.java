import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;

class Main {
    static In in = new In();
    static Out out = new Out();
    static long mod = 1000000007;
    static long inf = 0xfffffffffffffffL;

    void solve() {
        double xs = in.nextInt();
        double ys = in.nextInt();
        double xt = in.nextInt();
        double yt = in.nextInt();
        int n = in.nextInt();
        double[] x = new double[n];
        double[] y = new double[n];
        double[] r = new double[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            r[i] = in.nextInt();
        }
        double[][] cost = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = Math.max(0, Math.sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]);
            }
        }
        double[] dist = new double[n];
        PriorityQueue<Edge> queue = new PriorityQueue<>(Comparator.comparingDouble(e -> e.d));
        for (int i = 0; i < n; i++) {
            dist[i] = Math.max(0, Math.sqrt((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys)) - r[i]);
            queue.add(new Edge(i, dist[i]));
        }
        while (!queue.isEmpty()) {
            Edge v = queue.poll();
            if (v.d > dist[v.i]) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (i != v.i && dist[i] > dist[v.i] + cost[v.i][i]) {
                    dist[i] = dist[v.i] + cost[v.i][i];
                    queue.add(new Edge(i, dist[i]));
                }
            }
        }
        double ans = inf;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, dist[i] + Math.max(0, Math.sqrt((x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt)) - r[i]));
        }
        ans = Math.min(ans, Math.sqrt((xs - xt) * (xs - xt) + (ys - yt) * (ys - yt)));
        out.println(ans);
    }

    static class Edge {
        int i;
        double d;

        public Edge(int i, double d) {
            this.i = i;
            this.d = d;
        }
    }

    public static void main(String[]$) {
        new Main().solve();
        out.flush();
    }
}

class In {
    private BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 0x10000);
    private StringTokenizer tokenizer;

    String next() {
        try {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
        } catch (IOException ignored) {
        }
        return tokenizer.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    char[][] nextCharArray(int n, int m) {
        char[][] a = new char[n][m];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        return a;
    }

    int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    int[] nextIntArray(int n, IntUnaryOperator op) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = op.applyAsInt(nextInt());
        }
        return a;
    }

    long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        return a;
    }

    long[] nextLongArray(int n, LongUnaryOperator op) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = op.applyAsLong(nextLong());
        }
        return a;
    }
}

class Out {
    private static PrintWriter out = new PrintWriter(System.out);

    void println(Object... a) {
        StringJoiner joiner = new StringJoiner(" ");
        for (Object obj : a) {
            joiner.add(String.valueOf(obj));
        }
        out.println(joiner);
    }

    void flush() {
        out.flush();
    }
}
