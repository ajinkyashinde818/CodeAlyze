import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BFusingSlimes solver = new BFusingSlimes();
        solver.solve(1, in, out);
        out.close();
    }

    static class BFusingSlimes {
        static final int mod = (int) 1e9 + 7;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            if (false) {
//            int[] x = {161735902, 211047202, 430302156, 450968417, 628894325, 707723857, 731963982, 822804784, 880895728, 923078537, 971407775, 982631932};
                int[] x = new int[]{1, 2, 4, 8};
                int n = x.length;
                int[] ps = permutation(n - 1);
                long ans = 0;
                long all = 0;
                long[] cnt = new long[n];
                long[] e = new long[n];
                do {
                    all++;
                    int[] y = x.clone();
                    for (int i : ps) {
                        int j = i + 1;
                        while (y[j] == -1) j++;
                        if (y[i + 1] == -1) cnt[i] += y[j] - y[i + 1];
                        e[i] += y[j] - y[i];
                        ans += y[j] - y[i];
                        y[i] = -1;
                    }
                } while (nextPermutation(ps));
                long f = 1;
                for (int i = 1; i < n; i++) {
                    f = f * i % mod;
                }
                dump(e);
                dump(cnt);
                dump(ans, all, f, ans * f % all, cnt);
                dump(e[0], (x[1] - x[0]) * f, e[1], e[0], (x[1] - x[0]) * f + e[1] / 2);
                out.println(ans % mod);
                if (true) return;
            }

            int n = in.nextInt();
            int[] x = in.nextIntArray(n);

//        long[] E = new long[n];
//        long ans = 0;
            long f = 1;
            for (int i = 1; i < n; i++) {
                f = f * i % mod;
            }
//        for (int i = n - 2; i >= 0; i--) {
//            E[i] = ((x[i + 1] - x[i]) * f % mod + E[i + 1] * powmod(2, mod - 2, mod) % mod) % mod;
//            ans += E[i] % mod;
//        }
//        out.println((ans % mod + mod) % mod);

            long ans = 0;
            long c = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                ans += (x[j] - x[j - 1]) * f % mod * powmod(j - i, mod - 2, mod) % mod;
//            }
//        }
            for (int i = 0; i < n - 1; i++) {
                c = (c + powmod(i + 1, mod - 2, mod)) % mod;
                ans += (x[i + 1] - x[i]) * f % mod * c % mod;
            }
            out.println((ans % mod + mod) % mod);
        }

        private static int[] permutation(int n) {
            int[] ps = new int[n];
            for (int i = 0; i < n; i++) ps[i] = i;
            return ps;
        }

        private static final boolean nextPermutation(final int[] xs) {
            for (int i = xs.length - 1; i > 0; i--) {
                if (xs[i - 1] > xs[i]) {
                    continue;
                }

                for (int j = i, k = xs.length - 1; j < k; j++, k--) {
                    swap(xs, j, k);
                }

                for (int j = i; j < xs.length; j++)
                    if (xs[j] > xs[i - 1]) {
                        swap(xs, j, i - 1);
                        break;
                    }

                return true;
            }
            return false;
        }

        static long powmod(long n, long r, int m) {
            long res = 1;
            for (; r != 0; r >>>= 1, n = n * n % m) {
                if ((r & 1) == 1) {
                    res = res * n;
                    if (res >= m) {
                        res %= m;
                    }
                }
            }
            return res;
        }

        static void dump(Object... o) {
            System.err.println(Arrays.deepToString(o));
        }

        static void swap(int[] xs, int i, int j) {
            int t = xs[i];
            xs[i] = xs[j];
            xs[j] = t;
        }

    }

    static class MyInput {
        private final BufferedReader in;
        private static int pos;
        private static int readLen;
        private static final char[] buffer = new char[1024 * 8];
        private static char[] str = new char[500 * 8 * 2];
        private static boolean[] isDigit = new boolean[256];
        private static boolean[] isSpace = new boolean[256];
        private static boolean[] isLineSep = new boolean[256];

        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true;
            }
            isDigit['-'] = true;
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
            isLineSep['\r'] = isLineSep['\n'] = true;
        }

        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }

        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException();
                }
            }
            return buffer[pos++];
        }

        public int nextInt() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }

        public char nextChar() {
            while (true) {
                final int c = read();
                if (!isSpace[c]) {
                    return (char) c;
                }
            }
        }

        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read();
                    if (accept[c]) {
                        break;
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c;
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len;
        }

        public int[] nextIntArray(final int n) {
            final int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}
