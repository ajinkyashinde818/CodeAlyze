import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author @MaxHeap
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TripletSum solver = new TripletSum();
        solver.solve(1, in, out);
        out.close();
    }

    static class TripletSum {
        public void solve(int testNumber, FastReader fs, PrintWriter pw) {
            int k = fs.nextInt(), Sum = fs.nextInt();
            int ans = 0;
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    int p = Sum - i - j;
                    if (p < 0 || p > k) continue;
                    ans += 1;
                }
            }
            pw.println(ans);
        }

    }

    static class FastReader {
        BufferedReader bf;
        StringTokenizer st;

        public FastReader(InputStream is) {
            bf = new BufferedReader(new InputStreamReader(is));
            st = null;
        }

        public String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    String line = bf.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
            } catch (Exception e) {
            }

            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
