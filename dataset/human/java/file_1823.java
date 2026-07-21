import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
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
        MyScan in = new MyScan(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, MyScan in, PrintWriter out) {
            int d = in.nextInt();
            int g = in.nextInt();

            Map<Integer, Integer> x = new HashMap<>();

            x.put(0, 0);
            for (int s = 1; s <= d; s++) {

                Map<Integer, Integer> next = new HashMap<>();


                int xx = in.nextInt();
                int pp = in.nextInt();

                for (Map.Entry<Integer, Integer> mins : x.entrySet()) {
                    for (int i = 0; i < xx; i++) {
                        next.merge(mins.getKey() + i, mins.getValue() + i * s * 100, Math::max);
                    }
                    next.merge(mins.getKey() + xx, mins.getValue() + xx * s * 100 + pp, Math::max);
                }

                x = next;
            }

            int ans = 100000000;
            for (Map.Entry<Integer, Integer> mins : x.entrySet()) {
                if (mins.getValue() >= g) {
                    ans = Math.min(ans, mins.getKey());
                }
            }
            out.println(ans);


        }

    }

    static class MyScan {
        private final InputStream in;
        private byte[] inbuf = new byte[1024];
        public int lenbuf = 0;
        public int ptrbuf = 0;

        public MyScan(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = in.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }
}
