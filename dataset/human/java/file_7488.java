import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        InputStreamScanner in = new InputStreamScanner(System.in);
        new Main().solve(in, out);
        out.flush();
    }

    private void solve(InputStreamScanner in, PrintWriter out) {
        String[] a = new String[]{
                "dream", "dreamer", "erase", "eraser"
        };

        String s = in.next();

        LinkedList<Integer> q = new LinkedList<>();
        int[] m = new int[s.length()];

        for (int i = 0; i < a.length; ++i) {
            if (s.substring(0, a[i].length()).equals(a[i])) {
                q.push(a[i].length());
                m[a[i].length()] = 1;
            }
        }

        while (!q.isEmpty()) {
            int p = q.remove();
            for (int i = 0; i < a.length; ++i) {
                int np = p + a[i].length();
                if (np == s.length()) {
                    if (s.substring(p, np).equals(a[i])) {
                        out.println("YES");
                        return;
                    }
                }else if (np < s.length()) {
                    if (m[np] == 0) {
                        if (s.substring(p, np).equals(a[i])) {
                            q.push(np);
                            m[np] = 1;
                        }
                    }
                }
            }
        }

        out.println("NO");
    }

    static class P {
        public int i;
        public String t;

        public P(int i, String t) {
            this.i = i;
            this.t = t;
        }

        public String toString() {
            return this.i + this.t;
        }
    }

    static class InputStreamScanner {

        private InputStream in;

        private byte[] buf = new byte[1024];
        private int len = 0;
        private int off = 0;

        InputStreamScanner(InputStream in)	{
            this.in = in;
        }

        String next() {
            StringBuilder sb = new StringBuilder();
            for (int b = skip(); !isSpace(b);){
                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        char nextChar() {
            return (char)skip();
        }

        int skip() {
            for (int b; (b = read()) != -1;) {
                if (!isSpace(b)) {
                    return b;
                }
            }
            return -1;
        }

        private boolean isSpace(int c) {
            return c < 33 || c > 126;
        }

        private int read() {
            if (len == -1) {
                throw new InputMismatchException("End of Input");
            }
            if (off >= len){
                off = 0;
                try {
                    len = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException(e.getMessage());
                }
                if (len <= 0) {
                    return -1;
                }
            }
            return buf[off++];
        }
    }
}
