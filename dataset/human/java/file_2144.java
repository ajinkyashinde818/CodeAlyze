import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author maheshwari29
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
            int i, j;
            long n = in.nl();
            HashMap<Long, Integer> hm = primeFactors(n);
            //out.println(hm);
            long ans = 0;
            for (long c : hm.keySet()) {
                double temp = -1.0 + Math.sqrt(1.0 + 8.0 * hm.get(c));
                //out.println("temp="+temp);
                long temp2 = (long) Math.floor(temp / 2.0);
                //out.println("temp2="+temp2);
                ans += temp2;
            }
            out.println(ans);
        }

        public HashMap<Long, Integer> primeFactors(long n) {
            HashMap<Long, Integer> hm = new HashMap<Long, Integer>();
            // Print the number of 2s that divide n
            while (n % 2 == 0) {
                if (hm.containsKey((long) 2))
                    hm.put((long) 2, hm.get((long) 2) + 1);
                else
                    hm.put((long) 2, 1);
                n /= 2;
            }

            // n must be odd at this point.  So we can
            // skip one element (Note i = i +2)
            for (int i = 3; i <= Math.sqrt(n); i += 2) {
                // While i divides n, print i and divide n
                while (n % i == 0) {
                    if (hm.containsKey((long) i))
                        hm.put((long) i, hm.get((long) i) + 1);
                    else
                        hm.put((long) i, 1);
                    n /= i;
                }
            }

            // This condition is to handle the case whien
            // n is a prime number greater than 2
            if (n > 2)
                hm.put((long) n, 1);
            return hm;
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

        public long nl() {
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
