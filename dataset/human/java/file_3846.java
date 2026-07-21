import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            StringBuilder _s2 = new StringBuilder();
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) != 'x') {
                    _s2.append(s.charAt(i));
                }
            }
            String s2 = _s2.toString();
            for (int i = 0; i < s2.length(); ++i) {
                if (s2.charAt(i) != s2.charAt(s2.length() - i - 1)) {
                    out.println(-1);
                    return;
                }
            }
            int ans = 0;
            int p1 = 0, p2 = s.length() - 1;
            for (int i = 0; i < (s2.length() + 1) / 2; ++i) {
                int cnt1 = 0;
                while (s.charAt(p1) != s2.charAt(i)) {
                    p1++;
                    cnt1++;
                }
                int cnt2 = 0;
                while (s.charAt(p2) != s2.charAt(i)) {
                    p2--;
                    cnt2++;
                }
                p1++;
                p2--;
                ans += Math.abs(cnt1 - cnt2);
            }
            out.println(ans);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}
