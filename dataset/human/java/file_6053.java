// package arc.arc092;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
    static class NumWithMask {
        int a;
        int lowmask;
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n ; i++) {
            b[i] = in.nextInt();
        }

        NumWithMask[] nm = new NumWithMask[n];
        for (int i = 0; i < n ; i++) {
            nm[i] = new NumWithMask();
            nm[i].a = a[i];
        }

        int xor = 0;
        int[] imos = new int[n+1];
        for (int k = 0; k <= 28 ; k++) {
            int mask = 1<<k;
            for (int i = 0; i < n ; i++) {
                nm[i].lowmask = nm[i].a & (mask-1);
            }
            Arrays.sort(nm, Comparator.comparingInt(u -> u.lowmask));

            long count = 0;
            for (int i = 0; i < n ; i++) {
                if ((nm[i].a & mask) >= 1) {
                    imos[i+1] = imos[i] + 1;
                } else {
                    imos[i+1] = imos[i];
                }
            }

            for (int i = 0; i < n ; i++) {
                int lowmask = b[i] & (mask - 1);
                int max = n;
                int min = -1;
                while (max - min > 1) {
                    int med = (max + min) / 2;
                    if (nm[med].lowmask + lowmask >= mask) {
                        max = med;
                    } else {
                        min = med;
                    }
                }
                long kc = imos[max] + ((n - max) - (imos[n] - imos[max]));
                if ((b[i] & mask) >= 1) {
                    kc = n - kc;
                }
                count += kc;
            }

            if (count % 2 == 1) {
                xor ^= mask;
            }
        }

        out.println(xor);
        out.flush();
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
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
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}
