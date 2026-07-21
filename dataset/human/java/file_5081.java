import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Deque;
import java.util.LinkedList;
import java.util.ArrayList;
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
        DStringFormation solver = new DStringFormation();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStringFormation {
        public void solve(int testNumber, FastReader s, PrintWriter out) {
            String str = s.nextString();
            int t = s.nextInt();
            Deque<Character> q = new LinkedList<>();
            for (int i = 0; i < str.length(); i++) {
                q.add(str.charAt(i));
            }
            boolean isReversed = false;

            while (t-- > 0) {
                int type = s.nextInt();
                if (type == 1) {
                    isReversed = !isReversed;
                } else {
                    int last = s.nextInt();
                    char ch = s.nextCharacter();
                    if (isReversed) {
                        if (last == 1) {
//                        str = str + "" + ch;
                            q.addLast(ch);
                        } else {
//                        str = ch + "" + str;
                            q.addFirst(ch);
                        }
                    } else {
                        if (last == 1) {
//                        str = ch + "" + str;
                            q.addFirst(ch);
                        } else {
//                        str = str + "" + ch;
                            q.addLast(ch);
                        }
                    }
                }
            }

            ArrayList<Character> arr = new ArrayList<>(q);
            if (isReversed) {
                for (int i = arr.size() - 1; i >= 0; i--) {
                    char c = arr.get(i);
                    out.print(c);
                }
            } else {
                for (int i = 0; i < arr.size(); i++) {
                    char c = arr.get(i);
                    out.print(c);
                }
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

        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
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

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}
