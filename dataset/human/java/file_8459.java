import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author gaidash
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DConnectivity solver = new DConnectivity();
        solver.solve(1, in, out);
        out.close();
    }

    static class DConnectivity {
        private static final int UNDEF = -1;
        private int nCities;

        private void addEdge(int v, int u, DConnectivity.Vertex[] vs) {
            vs[v].outgo.add(u);
            vs[u].outgo.add(v);
        }

        private void dfs(int v, DConnectivity.Vertex[] vs, int curComp) {
            vs[v].comp = curComp;
            for (int next : vs[v].outgo) {
                if (vs[next].comp == UNDEF) {
                    dfs(next, vs, curComp);
                }
            }
        }

        private void findComps(DConnectivity.Vertex[] vs) {
            int curComp = 0;
            for (int i = 0; i < nCities; i++) {
                if (vs[i].comp == UNDEF) {
                    dfs(i, vs, curComp++);
                }
            }
        }

        private DConnectivity.Vertex[] readGraph(InputReader in, int n) {
            DConnectivity.Vertex[] vs = new DConnectivity.Vertex[nCities];
            for (int i = 0; i < nCities; i++) {
                vs[i] = new DConnectivity.Vertex();
            }
            for (int i = 0; i < n; i++) {
                addEdge(in.nextInt() - 1, in.nextInt() - 1, vs);
            }
            return vs;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            nCities = in.nextInt();
            int nRoads = in.nextInt();
            int nRails = in.nextInt();
            DConnectivity.Vertex[] roads = readGraph(in, nRoads);
            DConnectivity.Vertex[] rails = readGraph(in, nRails);

            findComps(roads);
            findComps(rails);

            DConnectivity.Common[] common = new DConnectivity.Common[nCities];
            for (int i = 0; i < nCities; i++) {
                common[i] = new DConnectivity.Common(i, roads[i].comp, rails[i].comp);
            }
            Arrays.sort(common);
            int[] ret = new int[nCities];
            for (int i = 0; i < nCities; i++) {
                DConnectivity.Common c1 = common[i];
                int left = i - 1;
                int right = nCities;
                while (left + 1 < right) {
                    int mid = (left + right) / 2;
                    DConnectivity.Common c2 = common[mid];
                    if (c1.equals(c2)) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                for (int j = i; j <= left; j++) {
                    ret[common[j].id] = left - i + 1;
                }
                i = left;
            }

            out.println(ret);
        }

        private static class Common implements Comparable<DConnectivity.Common> {
            private int id;
            private int compRoad;
            private int compRail;

            private Common(int id, int compRoad, int compRail) {
                this.id = id;
                this.compRoad = compRoad;
                this.compRail = compRail;
            }

            public int compareTo(DConnectivity.Common other) {
                if (compRoad == other.compRoad) {
                    return Integer.compare(compRail, other.compRail);
                }
                return Integer.compare(compRoad, other.compRoad);
            }

            public boolean equals(Object o) {
                if (o == this) {
                    return true;
                }
                if (!(o instanceof DConnectivity.Common)) {
                    return false;
                }
                DConnectivity.Common c = (DConnectivity.Common) o;
                return compRoad == c.compRoad && compRail == c.compRail;
            }

        }

        private static class Vertex {
            private int comp = UNDEF;
            private ArrayList<Integer> outgo = new ArrayList<>();

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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
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

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}
