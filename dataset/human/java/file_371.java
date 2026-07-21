import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Rustam Musin (t.me/musin_acm)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        ECosmicRays solver = new ECosmicRays();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECosmicRays {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            ECosmicRays.Circle c0 = new ECosmicRays.Circle(ECosmicRays.Point.read(in), 0);
            ECosmicRays.Circle c1 = new ECosmicRays.Circle(ECosmicRays.Point.read(in), 0);
            int n = in.readInt();
            ECosmicRays.Circle[] a = new ECosmicRays.Circle[n + 2];
            for (int i = 0; i < n; i++) a[i] = ECosmicRays.Circle.read(in);
            a[n] = c0;
            a[n + 1] = c1;
            double ans = findDistance(a);
            out.printFormat("%.20f", ans);
        }

        double findDistance(ECosmicRays.Circle[] a) {
            int n = a.length;
            int from = n - 2;
            double[] dist = new double[n];
            boolean[] used = new boolean[n];
            Arrays.fill(dist, Double.POSITIVE_INFINITY);
            dist[from] = 0;
            for (int t = 0; t < n; t++) {
                int v = -1;
                for (int i = 0; i < n; i++) if (!used[i] && (v == -1 || dist[i] < dist[v])) v = i;
                used[v] = true;
                for (int i = 0; i < n; i++) {
                    double d1 = dist[v] + a[v].distance(a[i]);
                    if (dist[i] > d1) {
                        dist[i] = d1;
                    }
                }
            }
            return dist[n - 1];
        }

        static class Point {
            double x;
            double y;

            public Point(double x, double y) {
                this.x = x;
                this.y = y;
            }

            static ECosmicRays.Point read(InputReader in) {
                double x = in.readDouble();
                double y = in.readDouble();
                return new ECosmicRays.Point(x, y);
            }

            double distance(ECosmicRays.Point p) {
                double dx = p.x - x;
                double dy = p.y - y;
                return Math.sqrt(dx * dx + dy * dy);
            }

        }

        static class Circle {
            ECosmicRays.Point center;
            double r;

            public Circle(ECosmicRays.Point center, double r) {
                this.center = center;
                this.r = r;
            }

            static ECosmicRays.Circle read(InputReader in) {
                ECosmicRays.Point center = ECosmicRays.Point.read(in);
                double r = in.readDouble();
                return new ECosmicRays.Circle(center, r);
            }

            double distance(ECosmicRays.Circle c) {
                return Math.max(0, c.center.distance(center) - (r + c.r));
            }

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

        public void printFormat(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
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

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, readInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, readInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}
