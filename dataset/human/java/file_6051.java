import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int xor = 0;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[] b = in.nextIntArray(n);
            int sumA = 0, sumB = 0;
            for (int aa : a) {
                sumA += aa;
            }
            for (int bb : b) {
                sumB += bb;
            }

            int ans = 0;
            int[] b2 = new int[n];
            for (int i = 1; i <= 29; i++) {
                for (int j = 0; j < n; j++) {
                    b2[j] = b[j] % (1 << i);
                }
                Arrays.sort(b2);
                for (int j = 0; j < n; j++) {
                    final int v = a[j] % (1 << i);
                    int m1 = (1 << (i - 1));
                    int m2 = (2 << (i - 1));
                    int m3 = (3 << (i - 1));
                    int m4 = (4 << (i - 1));
                    int i1 = lowerBound(b2, m1 - v);
                    int i2 = upperBound(b2, m2 - 1 - v);
                    int i3 = lowerBound(b2, m3 - v);
                    int i4 = upperBound(b2, m4 - 1 - v);
                    ans ^= (((i2 - i1) + (i4 - i3)) % 2) << (i - 1);
                }
            }
            out.println(ans);
        }

        int lowerBound(int[] xs, int key) {
            int low = -1, high = xs.length;
            while (high - low > 1) {
                int mid = (low + high) >>> 1;
                if (xs[mid] >= key) high = mid;
                else low = mid;
            }
            return high;
        }

        int upperBound(int[] xs, int key) {
            return lowerBound(xs, key + 1);
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
