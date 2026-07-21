import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        int x = fs.nextInt();

        int[] cs = new int[n];
        int[][] as = new int[n][m];

        int[] check = new int[m];

        for( int i = 0 ; i < n ; i++ ){
            cs[i] = fs.nextInt();
            for( int j = 0 ; j < m ; j++ ){
                as[i][j] = fs.nextInt();
                check[j] += as[i][j];
            }
        }
        for( int i = 0 ; i < m ; i++ ){
            if( check[i] < x ){
                System.out.println( "-1" );
                return;
            }
        }
        int min = Integer.MAX_VALUE;
        for( int i = 0 ; i < n ; i++ ){
            int result = calc( i , new int[m] , m , cs , as , n ,  x , min , 0 );
            min = Math.min( min , result );
        }
        System.out.println( min );
    }

    private static int calc( int pos , int[] xTotal , int m , int[] cs , int[][] as , int n , int x , int min , int total ){
        total += cs[pos];
        int[] xTotalTemp = new int[m];
        for( int i = 0 ; i < m ; i++ ){
            xTotalTemp[i] = xTotal[i] + as[pos][i];
        }
        boolean xOk = true;
        for( int i = 0 ; i < m ; i++ ){
            if( xTotalTemp[i] < x ){
                xOk = false;
            }
        }
        if( xOk ){
            return total;
        }
        else {
            int result =  Integer.MAX_VALUE;
            for( int i = pos + 1 ; i < n ; i++ ){
                result = Math.min( result , calc( i , xTotalTemp , m , cs , as , n , x , min , total ) );
            }
            return result;
        }
    }










    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int bufferLength = 0;

        private boolean hasNextByte() {
            if (ptr < bufferLength) {
                return true;
            } else {
                ptr = 0;
                try {
                    bufferLength = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return bufferLength > 0;
            }
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

        boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
                ptr++;
            }
            return hasNextByte();
        }

        String next() {
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

        long nextLong() {
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

    private static int gcd( int a , int b ){
        int x;
        int y;
        if (a > b) {
            x = a;
            y = b;
        } else {
            x = b;
            y = a;
        }
        int tmp;
        while ((tmp = x % y) != 0) {
            x = y;
            y = tmp;
        }
        return y;
    }

}
