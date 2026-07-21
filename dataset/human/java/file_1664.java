import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AColorfulSubsequence solver = new AColorfulSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class AColorfulSubsequence {
        private static final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] a = in.nextCharArray(n, 1);
            int[] cnt = new int[30];
            for (int i = 1; i <= n; i++) {
                cnt[a[i] - 'a' + 1]++;
            }
            int ans = 0;
            ArrayList<Integer> cur = new ArrayList<>();
            for (int i = 1; i <= 16; i++) {
                if (cnt[i] == 0) continue;
                int t = cur.size();
                for (int j = 0; j < t; j++) {
                    cur.add(Op.mulMod(cnt[i], cur.get(j), MOD));
                }
                cur.add(cnt[i]);
            }

            for (int i : cur) {
                ans = Op.addMod(ans, i, MOD);
            }
            int ans1 = 0;
            cur = new ArrayList<>();
            for (int i = 17; i <= 29; i++) {
                if (cnt[i] == 0) continue;
                int t = cur.size();
                for (int j = 0; j < t; j++) {
                    cur.add(Op.mulMod(cnt[i], cur.get(j), MOD));
                }
                cur.add(cnt[i]);
            }
            for (int i : cur) {
                ans1 = Op.addMod(ans1, i, MOD);
            }
            int tmp = Op.mulMod(ans, ans1, MOD);
            int tmp1 = Op.addMod(ans, ans1, MOD);

            out.println(Op.addMod(tmp, tmp1, MOD));
        }

    }

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

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
            while (isSpaceChar(c))
                c = read();
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

        public char[] nextCharArray(int length, int stIndex) {
            char[] arr = new char[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextCharacter();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }
}
