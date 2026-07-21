import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.io.BufferedWriter;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DDivGame solver = new DDivGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDivGame {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int ntc = 1;
//        ntc = in.nextInt();
            while ((ntc--) > 0) {
                long n = in.nextLong();
                TreeMap<Long, Long> tm = getPrimeFactorsWithPowers(n);
                long ans = 0;
                for (long p : tm.values()) {
                    ans += getCount(p);
                }
                out.println(ans);
            }
        }

        public long getCount(long n) {
            long l = 1;
            long r = (long) 1e9;
            while (l <= r) {
                long mid = l + (r - l + 1) / 2;
                if ((mid * (mid + 1)) / 2 <= n) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return r;
        }

        public static TreeMap<Long, Long> getPrimeFactorsWithPowers(long n) {
            TreeMap<Long, Long> primeFactorsWithPowers = new TreeMap<>();
            while (n % 2L == 0) {
                primeFactorsWithPowers.put(2L, primeFactorsWithPowers.getOrDefault(2L, 0L) + 1);
                n /= 2L;
            }
            for (long i = 3; i * i <= n; i += 2) {
                while (n % i == 0) {
                    primeFactorsWithPowers.put(i, primeFactorsWithPowers.getOrDefault(i, 0L) + 1);
                    n /= i;
                }
            }
            if (n > 2) {
                primeFactorsWithPowers.put(n, primeFactorsWithPowers.getOrDefault(n, 0L) + 1);
            }
            return primeFactorsWithPowers;
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}
