import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Ribhav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CTypicalStairs solver = new CTypicalStairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTypicalStairs {
        public void solve(int testNumber, FastReader s, PrintWriter out) {
            int n = s.nextInt();
            int m = s.nextInt();
            HashSet<Integer> set = new HashSet<>();
            for (int i = 0; i < m; i++) {
                set.add(s.nextInt());
            }
            int[] ans = new int[n + 1];
            Arrays.fill(ans, -1);
            out.println(func(0, set, n, ans));
        }

        private int func(int curr, HashSet<Integer> set, int n, int[] ans) {
            if (curr == n) {
                return ans[curr] = 1;
            }

            if (ans[curr] != -1) {
                return ans[curr];
            }
            int ans1 = 0;
            if (curr + 1 <= n && !set.contains(curr + 1)) {
                ans1 = (ans1 + func(curr + 1, set, n, ans)) % 1000000007;
            }

            if (curr + 2 <= n && !set.contains(curr + 2)) {
                ans1 = (ans1 + func(curr + 2, set, n, ans)) % 1000000007;
            }

            return ans[curr] = ans1 % 1000000007;

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
