import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
            int n = in.nextInt();
            long c = in.nextLong();
            long[] v = new long[n];
            long[] x = new long[n];

            for (int i = 0; i < n; i++) {
                x[i] = in.nextLong();
                v[i] = in.nextLong();
            }

            long ans = 0;
            long cur = 0;
            long[] max1 = new long[n + 1];
            long[] max2 = new long[n + 1];
            for (int i = 0; i < n; i++) {
                cur += v[i];
                max1[i + 1] = Math.max(cur - 2 * x[i], max1[i]);
            }
            cur = 0;
            for (int i = n - 1; i >= 0; i--) {
                cur += v[i];
                max2[i] = Math.max(cur - 2 * (c - x[i]), max2[i + 1]);
//            dump(i, max2[i]);
            }

            cur = 0;
            for (int i = 0; i < n; i++) {
                cur += v[i];
                ans = Math.max(ans, cur - x[i] + max2[i + 1]);
//            if (i == 9) dump(cur - x[i], max2[i+1]);
//            dump(i, cur - x[i] + max2[i+1]);
            }
            cur = 0;
            for (int i = n - 1; i >= 0; i--) {
                cur += v[i];
                ans = Math.max(ans, cur - (c - x[i]) + max1[i]);
//            dump(i, cur - (c-x[i]) + max1[i]);
            }

//        ans = 0;
//        cur = 0;
//        for (int i = 0; i < n; i++) {
//            cur += v[i];
//            long sum = 0;
//            for (int j = n - 1; j > i; j--) {
//                sum += v[j];
//                long val = cur + sum - x[i] - (c-x[j]) - Math.min(x[i], (c-x[j]));
//                ans = Math.max(ans, val);
//                if (val == 6500000000L) {
//                    dump(i, j, x[i] < (c-x[j]));
//                }
//            }
//        }
            out.println(ans);
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

        public long nextLong() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            long ret = 0;
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

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}
