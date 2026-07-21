import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.NoSuchElementException;

public class Main {
    static int[] si;
    static long ans;
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        String s = sc.next();
        int len = s.length();
        ans = 0;
        si = new int[len];

        for (int i = 0; i < len; i++) {
            si[i] = s.charAt(i) - '0';
        }

        long[][] dp = new long[len+1][2];
        dp[len][1] = 10;

        for (int i = len-1; i >= 0; i--) {
            dp[i][0] = Math.min(
                            dp[i+1][0] + si[i],
                            dp[i+1][1] + si[i] + 1);
            dp[i][1] = Math.min(
                            dp[i+1][0] + 10 - si[i],
                            dp[i+1][1] + 9 - si[i]);        
        }

        ans = Math.min(dp[0][0], dp[0][1] + 1);

        // for (int i = 0; i < len-1; i++) {
        //     int pos = len - i - 1;
        //     if(si[pos] <= 5){
        //         ans += si[pos];
        //     }else{
        //         ans += 10 - si[pos];
        //         kuri(pos - 1);
        //     }
        // }

        // if(si[0] <= 5){
        //     ans += si[0];
        // }else{
        //     ans += 10 - si[0] + 1;
        // }

        System.out.println(ans);

    }

    static void kuri(int i){
        if(si[i] < 9){
            si[i]++;
        }else{
            si[i] = 0;
            if(i != 0){
                kuri(i-1);
            }else{
                ans++;
            }
        }
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
