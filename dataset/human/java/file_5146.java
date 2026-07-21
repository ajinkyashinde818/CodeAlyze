import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here

        FastScanner sc = new FastScanner();

        boolean reverse = false;
        StringBuilder sento = new StringBuilder();
        StringBuilder ushiro = new StringBuilder();
        StringBuilder builder = new StringBuilder(sc.next());
        int q = sc.nextInt();

        for (int i = 0; i < q ; i++) {
            if (sc.nextInt() == 1) {
                reverse = !reverse;
            } else {
                // 先頭に追加
                if (sc.nextInt() == 1) {
                    if (reverse) {
                        StringBuilder reverseUshiro = new StringBuilder(sc.next()).reverse();
                        ushiro.append(reverseUshiro);
                    } else {
                        sento.insert(0, sc.next());
                    }
                } else {
                    if (reverse) {
                        StringBuilder reverseSento = new StringBuilder(sc.next()).reverse();
                        sento.insert(0, reverseSento);
                    } else {
                        ushiro.append(sc.next());
                    }
                }
            }
        }
        builder.append(ushiro);
        builder.insert(0, sento);
        if (reverse) {
            builder.reverse();
        }

        System.out.println(builder);
    }

    private static class FastScanner {
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
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
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
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }
    }
}
