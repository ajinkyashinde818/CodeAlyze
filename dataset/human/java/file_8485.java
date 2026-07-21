import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
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
        PrintWriter out = new PrintWriter(outputStream);
        DConnectivity solver = new DConnectivity();
        solver.solve(1, in, out);
        out.close();
    }

    static class DConnectivity {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints(), k = in.ints(), l = in.ints();
            UnionFind road = new UnionFind(n);
            for (int i = 0; i < k; i++) {
                road.union(in.ints() - 1, in.ints() - 1);
            }
            UnionFind rail = new UnionFind(n);
            for (int i = 0; i < l; i++) {
                rail.union(in.ints() - 1, in.ints() - 1);
            }
            Map<Long, Integer> count = new HashMap<>();
            for (int i = 0; i < n; i++) {
                count.merge(road.find(i) + 300_000L * rail.find(i), 1, (x, y) -> x + y);
            }
            for (int i = 0; i < n; i++) {
                out.println(count.get(road.find(i) + 300_000L * rail.find(i)));
            }
        }

    }

    static class UnionFind {
        private final int[] groups;

        public UnionFind(int size) {
            groups = IntStream.range(0, size).toArray();
        }

        public int find(int i) {
            int ans = groups[i];
            while (ans != groups[ans]) {
                ans = groups[ans];
            }
            return groups[i] = ans;
        }

        public int union(int a, int b) {
            return groups[find(b)] = find(a);
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

    }
}
