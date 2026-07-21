import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author EndUser
 * 
 */
public class Main {
        
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out), true);

        int n = in.nextInt();
        int m = in.nextInt();
        int[] bs = new int[m];
        for (int i = 0; i < m; i++) {
            bs[i] = in.nextInt();
        }
        
        int[] f = new int[n + 1];
        f[0] = 1;
        int bsi = 0;
        if (m > 0 && bs[0] == 1) {
            bsi++;
            f[1] = 0;
        } else {
            f[1] = 1;
        }
        
        boolean impossible = false;
        for (int i = 2; i <= n; i++) {
            if (bsi < m && bs[bsi] == i) {
                f[i] = 0;
                bsi++;
            } else {
                f[i] = (f[i-1] + f[i-2]) % 1000000007;
                if (f[i] == 0) {
                    impossible = true;
                    break;
                }
            }
        }
        
        if (impossible) {
            pw.println(0);
        } else {
            pw.println(f[n]);
        }
        
        pw.close();
    }
    
    private static int findLocation(String[] p, int begin, int end, int position, char c) {
        int result = -1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            char x = p[mid].charAt(position);
            if (x >= c) {
                if (x == c) {
                    result = mid;
                }
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        
        return result;
    }
    
    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public String readString() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public interface SpaceCharFilter {

            public boolean isSpaceChar(int ch);
        }
    }

}
