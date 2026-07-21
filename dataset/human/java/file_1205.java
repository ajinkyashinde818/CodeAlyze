import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Hamza Hasbi
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        C_Splitting_Pile solver = new C_Splitting_Pile();
        solver.solve(1, in, out);
        out.close();
    }

    static class C_Splitting_Pile {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
            long pre = 0, post = 0;
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
                pre = a[0];
                post += a[i];
            }
            long ans = Integer.MAX_VALUE;
            for (int i = 0; i < n - 1; i++) {
                if (i != 0) pre += a[i];
                post -= a[i];
                ans = Math.min(Math.abs(pre - post), ans);
            }
            //out.printLine(r+" "+l);
            out.printLine(ans);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printLine(long i) {
            writer.println(i);
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer st;

        public InputReader(InputStream stream) {
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
