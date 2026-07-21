import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
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
        BTemplateMatching solver = new BTemplateMatching();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTemplateMatching {
        public void solve(int testNumber, InputReader in, OutputWriter out) {

            int N, M;
            N = in.readInt();
            M = in.readInt();
            int nmmax = 50;
            char[][] A = new char[nmmax][nmmax];
            char[][] B = new char[nmmax][nmmax];
            for (int y = 0; y < N; ++y) {
                for (int x = 0; x < N; ++x) {
                    A[y][x] = in.readCharacter();
                }
            }

            for (int y = 0; y < M; ++y) {
                for (int x = 0; x < M; ++x) {
                    B[y][x] = in.readCharacter();
                }
            }

            boolean exist = false;

            for (int ly = 0; ly < N; ++ly) {
                for (int lx = 0; lx < N; ++lx) {
                    if (ly + M - 1 >= N || lx + M - 1 >= N) continue;

                    boolean match = true;
                    for (int y = 0; y < M; ++y) {
                        for (int x = 0; x < M; ++x) {
                            if (A[ly + y][lx + x] != B[y][x]) match = false;
                        }
                    }
                    if (match) exist = true;
                }
            }

            if (exist)
                out.printLine("Yes");
            else
                out.printLine("No");
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

        public char readCharacter() {
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}
