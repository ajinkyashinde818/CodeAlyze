import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String s = in.next();

            StringBuilder sb = new StringBuilder();
            sb.append(s);

            while (sb.length() > 0) {
                if (sb.length() >= 5 && sb.substring(sb.length() - 5, sb.length()).equals("dream")) {
                    sb.delete(sb.length() - 5, sb.length());
                    continue;
                }
                if (sb.length() >= 7 && sb.substring(sb.length() - 7, sb.length()).equals("dreamer")) {
                    sb.delete(sb.length() - 7, sb.length());
                    continue;
                }
                if (sb.length() >= 5 && sb.substring(sb.length() - 5, sb.length()).equals("erase")) {
                    sb.delete(sb.length() - 5, sb.length());
                    continue;
                }
                if (sb.length() >= 6 && sb.substring(sb.length() - 6, sb.length()).equals("eraser")) {
                    sb.delete(sb.length() - 6, sb.length());
                    continue;
                }
                out.println("NO");
                return;
            }
            out.println("YES");
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isPrintableChar(int c) {
            return c >= 33 && c <= 126;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();

            int b = readByte();
            while (!isPrintableChar(b))
                b = readByte();

            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }

            return sb.toString();
        }

    }
}
