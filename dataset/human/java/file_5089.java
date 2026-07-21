import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        final long DIV = 1000000007;
        FastScanner sc = new FastScanner();
        String s = sc.next();
        int q = sc.nextInt();
        boolean order = true;
        StringBuilder sb = new StringBuilder(s);
        StringBuilder sb2 = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if( t ==1){
                order = !order;
            }else{
                int f = sc.nextInt();
                String cs = sc.next();
                char c = cs.charAt(0);
                boolean bf = f == 1;
                if(order == bf){
                    // sb.insert(0, c);
                    sb2.append(c);
                }else{
                    sb.append(c);
                }
            }
        }

        if(order){
            System.out.println(sb2.reverse().toString() + sb.toString());
        }else{
            System.out.println(sb.reverse().toString() + sb2.toString());
        }

    }

    static long modinv(long a, long m){
        long b = m, u = 1, v = 0;
        while(b > 0){
            long t = a / b;
            a -= t * b;
            long tmp = a;
            a = b;
            b = tmp;
            u -= t * v;
            tmp = u;
            u = v;
            v = tmp;
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }

    private static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            }else{
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
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
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
            while(true){
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                }else if(b == -1 || !isPrintableChar(b)){
                    return minus ? -n : n;
                }else{
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
        public double nextDouble() { return Double.parseDouble(next());}
    }
}
