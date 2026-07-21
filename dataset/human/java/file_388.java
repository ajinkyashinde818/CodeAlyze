import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.OptionalInt;
import java.io.BufferedOutputStream;
import java.util.AbstractCollection;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        LightWriter out = new LightWriter(outputStream);
        ECosmicRays solver = new ECosmicRays();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECosmicRays {
        private static final double EPS = 1e-10;

        public void solve(int testNumber, LightScanner in, LightWriter out) {
            double sx = in.doubles(), sy = in.doubles(), gx = in.doubles(), gy = in.doubles();
            int n = in.ints();
            double[] x = new double[n], y = new double[n], r = new double[n];
            int[] visited = new int[n];
            in.doubles(x, y, r);
            double[] dist = new double[n];
            PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.comparing(p -> dist[p]));
            for (int i = 0; i < n; i++) {
                dist[i] = Math.max(0.0, dist(sx, sy, x[i], y[i]) - r[i]);
                q.offer(i);
            }
            while (!q.isEmpty()) {
                int p = q.poll();
                if (visited[p] > 5) continue;
                visited[p]++;
                for (int i = 0; i < n; i++) {
                    double d = Math.max(0.0, dist(x[p], y[p], x[i], y[i]) - r[i] - r[p]);
                    if (dist[p] + d < dist[i] - EPS) {
                        dist[i] = dist[p] + d;
                        q.offer(i);
                    }
                }
            }
            double ans = dist(sx, sy, gx, gy);
            for (int i = 0; i < n; i++) {
                ans = Math.min(ans, dist[i] + Math.max(0.0, dist(gx, gy, x[i], y[i]) - r[i]));
            }
            out.ans(ans, 10).ln();
        }

        private static double dist(double x1, double y1, double x2, double y2) {
            double dx = x1 - x2, dy = y1 - y2;
            return Math.sqrt(dx * dx + dy * dy);
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

        public double doubles() {
            return Double.parseDouble(string());
        }

        public void doubles(double[]... arrays) {
            int l = Arrays.stream(arrays).mapToInt(a -> a.length).min().orElse(0);
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = doubles();
                }
            }
        }

    }

    static class LightWriter implements AutoCloseable {
        private final Writer out;
        private boolean autoflush = false;
        private boolean breaked = true;

        public LightWriter(Writer out) {
            this.out = out;
        }

        public LightWriter(OutputStream out) {
            this(new OutputStreamWriter(new BufferedOutputStream(out), Charset.defaultCharset()));
        }

        public LightWriter print(char c) {
            try {
                out.write(c);
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length());
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter ans(double x, int n) {
            if (!breaked) {
                print(' ');
            }
            if (x < 0) {
                print('-');
                x = -x;
            }
            x += Math.pow(10, -n) / 2;
            print(Long.toString((long) x)).print('.');
            x -= (long) x;
            for (int i = 0; i < n; i++) {
                x *= 10;
                print((char) ('0' + ((int) x)));
                x -= (int) x;
            }
            return this;
        }

        public LightWriter ln() {
            print(System.lineSeparator());
            breaked = true;
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        public void close() {
            try {
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

    }
}
