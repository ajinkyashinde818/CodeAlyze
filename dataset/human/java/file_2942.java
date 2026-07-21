import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author MaxHeap
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        SnukeAndVoyage solver = new SnukeAndVoyage();
        solver.solve(1, in, out);
        out.close();
    }

    static class SnukeAndVoyage {
        private static final int INF = 100000000;

        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            List<Integer>[] g = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) g[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int from = in.nextInt();
                int to = in.nextInt();
                g[from].add(to);
                g[to].add(from);
            }
            int[] dist = new int[n + 1];
            ArrayDeque<Integer> q = new ArrayDeque<>();
            Arrays.fill(dist, INF);
            dist[1] = 0;
            q.add(1);
            while (!q.isEmpty()) {
                int cur = q.poll();
                for (int child : g[cur]) {
                    if (dist[child] > dist[cur] + 1) {
                        dist[child] = dist[cur] + 1;
                        q.add(child);
                    }
                }
            }
            out.println(dist[n] > 2 ? "IMPOSSIBLE" : "POSSIBLE");
        }

    }

    static class FastReader {
        BufferedReader reader;
        StringTokenizer st;

        public FastReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            st = null;
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String line = reader.readLine();
                    if (line == null) {
                        return null;
                    }
                    st = new StringTokenizer(line);
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
