import java.io.*;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();

        StringBuilder s = new StringBuilder(fs.next());
        int q = fs.nextInt();
        boolean isReverse = false;
        int t;
        int f;
        StringBuilder head = new StringBuilder();
        for (int i = 0; i < q; i++) {
            t = fs.nextInt();
            if (t % 2 == 1) {
                isReverse = !isReverse;
            } else {
                f = fs.nextInt();
                if (isReverse) {
                    if (f==1) {
                        s.append(fs.next());
                    } else {
                        head.append( fs.next() );
                    }
                } else {
                    if (f==1) {
                        head.append( fs.next() );
                    } else {
                        s.append(fs.next());
                    }
                }
            }
        }

        head.reverse();
        head.append( s );

        if (isReverse) {
            head.reverse();
        }

        System.out.println(head.toString());

    }

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) {
                return buffer[ptr++];
            } else {
                return -1;
            }
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
                ptr++;
            }
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
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

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
                throw new NumberFormatException();
            }
            return (int) nl;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
