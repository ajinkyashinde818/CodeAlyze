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
            boolean check = false;
            int m = in.nextInt();
            int a[] = new int[m];
            int b[] = new int[m];
            boolean vis[] = new boolean[n];
            for (int i = 0; i < m; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                if (x == 1) {
                    if (vis[y]) {
                        check = true;
                    }
                    vis[y] = true;
                }
                if (y == n) {
                    if (vis[x]) {
                        check = true;
                    }
                    vis[x] = true;
                }
            }
            if (check)
                out.println("POSSIBLE");
            else
                out.println("IMPOSSIBLE");
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

    }
}
