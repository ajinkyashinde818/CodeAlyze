import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FasterScanner in = new FasterScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FasterScanner in, PrintWriter out) {
            final int d = in.nextInt();
            final int g = in.nextInt() / 100;

            int[] p = new int[d];
            int[] c = new int[d];

            for (int i = 0; i < d; i++) {
                p[i] = in.nextInt();
                c[i] = in.nextInt() / 100;
            }

            int ans = Integer.MAX_VALUE;

            for (int i = (int) Math.pow(2, d) - 1; i >= 0; i--) {
                int score = 0;
                int ca = 0;
                boolean[] all = new boolean[d];
                for (int j = 0; j < d; j++) all[j] = (1 & (i >> j)) == 1;
                for (int j = 0; j < d; j++) {
                    if (all[j]) {
                        score += p[j] * (j + 1) + c[j];
                        ca += p[j];
                    }
                }
                if (ca >= ans) continue;
                if (score >= g) {
                    if (ca < ans) ans = ca;
                    continue;
                }
                int ds = g - score;
                for (int j = 0; j < d; j++) {
                    if (all[j]) continue;
                    int cm = 1 + ds / (j + 1);
                    if (ds % (j + 1) == 0) cm--;
                    if (cm >= p[j]) continue;
                    if (ca + cm < ans) ans = ca + cm;
                }
            }

            out.println(ans);
        }

    }

    static class FasterScanner {
        private InputStream in;
        private byte[] buffer;
        private int bufPointer;
        private int bufLength;

        public FasterScanner(InputStream in) {
            this.in = in;
            buffer = new byte[1024];
        }

        private boolean hasNextByte() {
            if (bufPointer < bufLength) return true;
            bufPointer = 0;
            try {
                bufLength = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (bufLength > 0);
        }

        private int readByte() {
            if (hasNextByte()) return buffer[bufPointer++];
            return -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[bufPointer])) bufPointer++;
            return hasNextByte();
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || b > '9') throw new NumberFormatException();

            while (true) {
                if (b >= '0' && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

    }
}
