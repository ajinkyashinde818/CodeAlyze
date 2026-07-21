import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CSkillUp solver = new CSkillUp();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSkillUp {
        public void solve(int testNumber, FastReader s, PrintWriter out) {

            int n = s.nextInt();
            int m = s.nextInt();
            int x = s.nextInt();
            long[][] arr = new long[n][m];
            long[] cost = new long[n];

            for (int i = 0; i < n; i++) {
                cost[i] = s.nextLong();
                for (int j = 0; j < m; j++) {
                    arr[i][j] = s.nextLong();
                }
            }

            long minCost = Long.MAX_VALUE;
            for (int i = 0; i < (1 << n); i++) {
                long[] understandings = new long[m];
                long c1 = 0L;
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        c1 += cost[j];
                        for (int k = 0; k < m; k++) {
                            understandings[k] += arr[j][k];
                        }
                    }
                }

                boolean canBeFound = true;
                for (int j = 0; j < m; j++) {
                    if (understandings[j] < x) {
                        canBeFound = false;
                        break;
                    }
                }

                if (canBeFound) {
                    minCost = Math.min(minCost, c1);
                }
            }

            if (minCost == Long.MAX_VALUE) {
                out.println(-1);

            } else {
                out.println(minCost);
            }
        }

    }

    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private FastReader.SpaceCharFilter filter;

        public FastReader(InputStream stream) {
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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
