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
 * @author Stirbul
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BGoToJail solver = new BGoToJail();
        solver.solve(1, in, out);
        out.close();
    }

    static class BGoToJail {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] a = new int[n];
            int[] b = new int[n];


            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }

            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == b[i]) {
                    count++;
                    if (count == 3) {
                        break;
                    }
                } else {
                    count = 0;
                }
            }

            if (count == 3) {
                out.println("Yes");
            } else {
                out.println("No");
            }
        }

    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
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
