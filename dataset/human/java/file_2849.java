import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main {

    static final long DIV = 1000000007;
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int n = sc.nextInt();
        long[] x = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextLong();
        }

        long[] small = new long[n-1];
        long[] large = new long[n-1];
        small[0] = 1;
        large[n-2] = n-1;
        for (int i = 0; i < n-2; i++) {
            small[i+1] = small[i] * (i+2);
            small[i+1] %= DIV;
            large[n-i-3] = large[n-i-2] * (n-i-2);
            large[n-i-3] %= DIV;
        }
        long[] mdata = new long[n];
        mdata[0] = 0;
        mdata[1] = large[1];
        if(n >= 3) mdata[n-1] = small[n-3];
        if( n >= 4) mdata[n-2] = small[n-4] * (n-1) % DIV;
        for (int i = 2; i < n-2; i++) {
            mdata[i] = small[i-2] * large[i];
            mdata[i] %= DIV;
        }

        long lsum = 0;
        long ans = 0;
        for (int i = 0; i < n-1; i++) {
            long di = x[i+1] - x[i];
            // lsum += mdata[n-i-1];
            lsum += mdata[i+1];
            lsum %= DIV;
            ans += ((lsum * di) % DIV);
            // ans += ((lsum * di) % DIV) * (long)(n-i-1);
            ans %= DIV;
        }

        System.out.println(ans);
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
            if (hasNextByte())
                return buffer[ptr++];
            else
                return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr]))
                ptr++;
            return hasNextByte();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext())
                throw new NoSuchElementException();
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
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
                throw new NumberFormatException();
            return (int) nl;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

}
