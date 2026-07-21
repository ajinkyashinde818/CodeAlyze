import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            TaskA solver = new TaskA();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskA {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            Circle begin = new Circle();
            begin.x = in.readInt();
            begin.y = in.readInt();
            Circle end = new Circle();
            end.x = in.readInt();
            end.y = in.readInt();
            List<Circle> circles = new ArrayList<>();
            circles.add(begin);
            circles.add(end);
            int n = in.readInt();
            for (int i = 0; i < n; i++) {
                Circle c = new Circle();
                c.x = in.readInt();
                c.y = in.readInt();
                c.r = in.readInt();
                circles.add(c);
            }

            TreeSet<Circle> set =
                            new TreeSet<>((a, b) -> a.dist == b.dist ? a.id - b.id : Double.compare(a.dist, b.dist));

            begin.dist = 0;
            set.add(begin);
            while (!set.isEmpty()) {
                Circle head = set.pollFirst();
                head.handled = true;
                for (Circle c : circles) {
                    if (c.handled) {
                        continue;
                    }
                    double dist = head.dist + Math.max(0, distOf(c, head) - c.r - head.r);
                    if (dist >= c.dist) {
                        continue;
                    }
                    set.remove(c);
                    c.dist = dist;
                    set.add(c);
                }
            }

            out.printf("%.10f", end.dist);
        }

        public double distOf(Circle a, Circle b) {
            double dx = a.x - b.x;
            double dy = a.y - b.y;
            return Math.sqrt(dx * dx + dy * dy);
        }

    }
    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(1 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput printf(String format, Object... args) {
            cache.append(String.format(format, args));
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

    }
    static class Circle {
        static int alloc = 0;
        boolean handled;
        int x;
        int y;
        int r;
        double dist = 1e50;
        int id = alloc++;

    }
    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }
}
