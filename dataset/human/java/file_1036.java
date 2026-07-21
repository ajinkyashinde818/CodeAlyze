import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.io.InputStream;

/**
 * @author khokharnikunj8
 */

public class Main {
    public static void main(String[] args) {
        new Thread(null, new Runnable() {
            public void run() {
                new Main().solve();
            }
        }, "1", 1 << 26).start();
    }

    void solve() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CCellInversion solver = new CCellInversion();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCellInversion {
        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            int n = in.scanInt();
            char[] ar = in.scanChars(2 * n);
            long ans = 1;
            long mod = 1000000007;
            long Left = 1;
            long Right = 0;
            boolean[] checker = new boolean[2 * n];
            for (int i = 1; i < 2 * n; i++) {
                if (ar[i] != ar[i - 1]) {
                    checker[i] = checker[i - 1];
                } else {
                    checker[i] = checker[i - 1] ^ true;
                }
                if (checker[i]) {
                    ans = (ans * Math.max(Left - Right, 0)) % mod;
                    Right++;
                } else Left++;
            }
            if (Left != Right) ans = 0;
            if (ar[0] == 'W') ans = 0;
            if (ar[2 * n - 1] == 'W') ans = 0;
            for (int i = 1; i <= n; i++) {
                ans = (ans * i) % mod;
            }
            out.println(ans);
        }

    }

    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int index;
        private BufferedInputStream in;
        private int total;

        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }

        private int scan() {
            if (index >= total) {
                index = 0;
                try {
                    total = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (total <= 0) return -1;
            }
            return buf[index++];
        }

        public int scanInt() {
            int integer = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    integer *= 10;
                    integer += n - '0';
                    n = scan();
                }
            }
            return neg * integer;
        }

        public char[] scanChars(int n) {
            char[] ar = new char[n];
            int c = scan();
            boolean flag = true;
            while (isWhiteSpace(c)) c = scan();
            ar[0] = (char) c;
            for (int i = 1; i < n; i++) ar[i] = (char) (c = scan());
            return ar;
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

    }
}
