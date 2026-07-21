import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.util.BitSet;
import java.io.BufferedReader;
import java.util.Comparator;
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
        ECosmicRays solver = new ECosmicRays();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECosmicRays {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
            int n = in.nextInt();
            long[] x = new long[n + 2];
            long[] y = new long[n + 2];
            long[] r = new long[n + 2];
            x[0] = a;
            y[0] = b;
            x[n + 1] = c;
            y[n + 1] = d;

            for (int i = 1; i <= n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                r[i] = in.nextInt();
            }

            n = n + 2;

            double[][] adj = new double[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    adj[i][j] = dist(x[i], y[i], r[i], x[j], y[j], r[j]);
                    adj[j][i] = adj[i][j];
                }
            }

            double[] distance = new double[n];
            Arrays.fill(distance, Double.POSITIVE_INFINITY);
            distance[0] = 0;
            PriorityQueue<Integer> vertices = new PriorityQueue<>(Comparator.comparingDouble(i -> distance[i]));
            vertices.add(0);

            BitSet done = new BitSet();

            while (!vertices.isEmpty()) {
                int i = vertices.poll();
                if (done.get(i)) {
                    continue;
                }
                done.set(i);
                for (int j = 0; j < n; j++) {
                    distance[j] = Math.min(distance[j], distance[i] + adj[i][j]);
                    vertices.add(j);
                }
            }

            out.println(distance[n - 1]);
        }

        private static double dist(long x, long y, long r, long x2, long y2, long r2) {
            double d = Math.hypot(x - x2, y - y2);
            d -= (r + r2);
            return Math.max(0, d);
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
