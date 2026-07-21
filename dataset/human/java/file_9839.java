import java.io.*;
import java.util.InputMismatchException;

public class Main {

    public static void main(String[] args){
        InputStream inputStream = System.in;
        InputReader in = new InputReader(inputStream);
        int n = in.nextInt();
        int m = in.nextInt();
        int x = in.nextInt();
        int[] c = new int[n];
        int[][] a = new int[n][m];

        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
            }
        }

        long ans = Long.MAX_VALUE;

       for (int i = 0; i < Math.pow(2,n); i++) {
            boolean ok = true;
            long res = 0;
           for (int k = 0; k < m; k++) {
                long sum = 0;
                for (int j = 0; j < n; j++) {
                    if ((1&i >> j) == 1) {
                        res += c[j];
                        sum += a[j][k];
                    }
                    // System.out.println(sum);
                }
                if (sum < x) {
                    ok = false;
                    break;
                }
                // System.out.println();
            }
            // System.out.println(res/m);
            if (ok) {
                ans = Math.min(ans,res/m);
            }
        }

        if (ans == Long.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;
                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException ex) {
                        throw new InputMismatchException();
                    }
                    if (this.numChars <= 0) {
                        return -1;
                    }
                }
                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c = this.read();
            while(isSpaceChar(c))
                c = this.read();
            int sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }
            int res = 0;
            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }
            throw new InputMismatchException();
        }


        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }
    }
}
