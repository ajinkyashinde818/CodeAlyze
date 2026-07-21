import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        arc_tenka_d solver = new arc_tenka_d();
        solver.solve(1, in, out);
        out.close();
    }

    static class arc_tenka_d {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int ss = -1;
            int nos = -1;
            for (int i = 1; i * (i + 1) <= 2 * n; i++) {
                if ((i * (i + 1)) / 2 == n) {
                    ss = i;
                    nos = i + 1;
                    break;
                }
            }

            if (ss == -1) {
                out.println("No");
                return;
            }

            out.println("Yes");

            out.println(nos);

            int nn = 1;

            List<TreeSet<Integer>> tsl = new ArrayList<>();

            int[] cnt = new int[n + 1];

            int si = 0;
            for (int i = 0; i < nos; i++) {
                TreeSet<Integer> ts = new TreeSet<>();
                for (int j = si; j < i; j++) {
                    TreeSet<Integer> cs = tsl.get(j);
                    if (cs.size() > 0) {
                        int first = cs.first();
                        cs.remove(first);
                        ts.add(first);
                    } else {
                        si = j + 1;
                    }
                }

                int c = 0;
                while (ts.size() < ss) {
                    c++;
                    ts.add(nn);
                    nn++;
                }

                out.print(ts.size() + " ");

                for (int val : ts) {
                    out.print(val + " ");
                }

                out.println();

                for (int j = 0; j < ss - c; j++) {
                    int first = ts.first();
                    ts.remove(first);
                }

                tsl.add(ts);
            }
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println() {
            writer.println();
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}
