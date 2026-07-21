import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.NavigableMap;
import java.util.TreeMap;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.SortedMap;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CLexicographicConstraints solver = new CLexicographicConstraints();
        solver.solve(1, in, out);
        out.close();
    }

    static class CLexicographicConstraints {
        int[] a;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            a = in.readIntArray(n);
            int left = 1;
            int right = n;
            while (left < right) {
                int middle = (left + right) >> 1;
                if (can(middle)) {
                    right = middle;
                } else {
                    left = middle + 1;
                }
            }
            out.printLine(left);
        }

        private boolean can(int letters) {
            int curLength = 0;
            NavigableMap<Integer, Integer> nonA = new TreeMap<>();
            for (int i : a) {
                if (i > curLength) {
                    curLength = i;
                } else {
                    if (letters == 1) {
                        return false;
                    }
                    while (!nonA.isEmpty() && nonA.lastKey() >= i) {
                        nonA.pollLastEntry();
                    }
                    boolean ok = false;
                    for (int j = i - 1; j >= 0; j--) {
                        if (!nonA.containsKey(j)) {
                            nonA.put(j, 1);
                            ok = true;
                            break;
                        }
                        int value = nonA.get(j);
                        value++;
                        if (value != letters) {
                            nonA.put(j, value);
                            ok = true;
                            break;
                        }
                        nonA.remove(j);
                    }
                    if (!ok) {
                        return false;
                    }
                    curLength = i;
                }
            }
            return true;
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

        public void printLine(int i) {
            writer.println(i);
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

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
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

        public int readInt() {
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
