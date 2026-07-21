// package arc.arc096;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long c = in.nextLong();
        long[][] sushi = new long[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                sushi[i][j] = in.nextLong();
            }
        }
        out.println(solve2(c, sushi));
        out.flush();
    }

    private static long solve2(long C, long[][] sushi) {
        long a = solve(C, sushi);

        for (int i = 0; i < sushi.length; i++) {
            sushi[i][0] = C - sushi[i][0];
        }
        Arrays.sort(sushi, Comparator.comparingLong(u -> u[0]));
        long b = solve(C, sushi);
        return Math.max(a, b);
    }

    private static long solve(long C, long[][] sushi) {
        int n = sushi.length;

        long sum = 0;
        for (int i = n-1 ; i >= 0 ; i--) {
            sum += sushi[i][1];
        }
        long best = Math.max(0, sum - (C - sushi[0][0]));
        
        long gomax = 0;
        long current = 0;
        for (int i = 0 ; i+1 < n ; i++) {
            sum -= sushi[i][1];
            long doa = sum - (C - sushi[i+1][0]) * 2;
            current -= sushi[i][0] - (i == 0 ? 0 : sushi[i-1][0]);
            current += sushi[i][1];
            gomax = Math.max(gomax, current);
            long score = doa + gomax;
            best = Math.max(best, score);
        }
        return Math.max(gomax, best);
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
