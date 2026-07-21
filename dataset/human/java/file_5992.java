import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    
    private static final class FastScanner {
        private final InputStream is = System.in;
        private final byte[] buf = new byte[8192];
        private int curChar;
        private int numChars;
 
        public FastScanner() {
        }
 
        public int read() {
                if (this.numChars == -1) {
                        throw new InputMismatchException();
                }
                if (this.curChar >= this.numChars) {
                        this.curChar = 0;
                        try {
                                this.numChars = this.is.read(this.buf);
                        } catch (final IOException e) {
                                throw new InputMismatchException();
                        }
                        if (this.numChars <= 0) {
                                return -1;
                        }
                }
                return this.buf[this.curChar++];
        }
 
        public String nextLine() {
                int c;
                while (isSpaceChar(c = read())) {
                }
                final StringBuilder res = new StringBuilder();
                do {
                        res.appendCodePoint(c);
                } while (!isEndOfLine(c = read()));
                return res.toString();
        }
 
        public String nextString() {
                int c;
                while (isSpaceChar(c = read())) {
                }
                final StringBuilder res = new StringBuilder();
                do {
                        res.appendCodePoint(c);
                } while (!isSpaceChar(c = read()));
                return res.toString();
        }
 
        public long nextLong() {
                int c;
                while (isSpaceChar(c = read())) {
                }
                boolean f = true;
                if (c == '-') {
                        f = false;
                        c = read();
                }
                long res = 0;
                do {
                        /*if (c < '0' || c > '9') {
                                throw new InputMismatchException();
                        }*/
                        res = res * 10 + c - '0';
                } while ((c = read()) >= '0' && c <= '9');
                return f ? res : -res;
        }
 
        public int nextInt() {
                int c;
                while (isSpaceChar(c = read())) {
                }
                boolean f = true;
                if (c == '-') {
                        f = false;
                        c = read();
                }
                int res = 0;
                do {
                        /*if (c < '0' || c > '9') {
                                throw new InputMismatchException();
                        }*/
                        res = res * 10 + c - '0';
                } while ((c = read()) >= '0' && c <= '9');
                return f ? res : -res;
        }
 
        public double nextDouble() {
                return Double.parseDouble(nextString());
                // return FloatingDecimal.parseDouble(nextString());
        }
 
        public BigInteger nextBigInteger() {
                return new BigInteger(nextString(), 10);
        }
 
        public BigDecimal nextBigDecimal() {
                return new BigDecimal(nextString());
        }
 
        public int[] nextArray(final int n) {
                final int[] a = new int[n];
                for (int i = 0; i < n; i++) {
                        a[i] = nextInt();
                }
                return a;
        }
 
        public long[] nextLongArray(final int n) {
                final long[] a = new long[n];
                for (int i = 0; i < n; i++) {
                        a[i] = nextLong();
                }
                return a;
        }
 
        public char[] nextCharArray(final int n) {
                final char[] bf = new char[n];
                int b, p = 0;
                while (isSpaceChar(b = read())) {
                }
                while (p < n && !isSpaceChar(b)) {
                        bf[p++] = (char) b;
                        b = read();
                }
                return n == p ? bf : Arrays.copyOf(bf, p);
        }
 
        public char[][] nextMatrix(final int n, final int m) {
                final char[][] map = new char[n][];
                for (int i = 0; i < n; i++) {
                        map[i] = nextCharArray(m);
                }
                return map;
        }
 
        public int[][] nextIntMatrix(final int n, final int m) {
                final int[][] map = new int[n][];
                for (int i = 0; i < n; i++) {
                        map[i] = nextArray(m);
                }
                return map;
        }
 
        public long[][] nextLongMatrix(final int n, final int m) {
                final long[][] map = new long[n][];
                for (int i = 0; i < n; i++) {
                        map[i] = nextLongArray(m);
                }
                return map;
        }
 
        public boolean isSpaceChar(final int c) {
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public boolean isEndOfLine(final int c) {
                return c == '\n' || c == '\r' || c == -1;
        }
    }
            
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        // BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        // StringTokenizer v;
        PrintWriter out = new PrintWriter(System.out);
        StringBuilder r = new StringBuilder();
        
        boolean a = false;
        boolean b = false;
        boolean c = false;
        
        String s = in.nextString();
        if(s.charAt(0) == 'a')
            a = true;
        else if(s.charAt(0) == 'b')
            b = true;
        else 
            c = true;
        
        if(s.charAt(1) == 'a')
            a = true;
        else if(s.charAt(1) == 'b')
            b = true;
        else 
            c = true;
        
        if(s.charAt(2) == 'a')
            a = true;
        else if(s.charAt(2) == 'b')
            b = true;
        else 
            c = true;
         
        if(a && b && c) 
            r.append("Yes\n");
        else
            r.append("No\n");
        
        out.print(r);
        out.flush();
        out.close();
    }
  
}
