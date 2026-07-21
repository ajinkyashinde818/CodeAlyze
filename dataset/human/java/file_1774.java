import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.util.Arrays;

@SuppressWarnings("unchecked")
public class Main {
    static int D;
    static int G;

    static boolean flg;
    static int ptn;
    static int[] p;
    static int[] c;

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();

        D = fs.nextInt();
        G = fs.nextInt();

        p = new int[D];
        c = new int[D];

        for (int i = 0; i < D; i++) {
            p[i] = fs.nextInt();
            c[i] = fs.nextInt();
        }

        int mxptn = (int)Math.pow(2, D) - 1;

        int mnnum = Integer.MAX_VALUE;

        for (int i = 0; i <= mxptn; i++) {
            int num = 0;
            int pnt = 0;

            ptn = i;

            for (int j = 0; j < D; j++) {
                if ((ptn >> j & 1) == 1) {
                    num += p[j];
                    // コンプリートする
                    pnt += c[j] + 100 * (j + 1) * p[j];
                }
            }

            flg = true;

            // 他はコンプリートしない
            if (pnt < G) num += fillpoint(pnt);

            if (flg) mnnum = Math.min(mnnum, num);
        }

        System.out.println(mnnum);
    }

    static int fillpoint(int pt) {
        int pnt = pt;
        int num = 0;

        // 大きなものから
        for (int i = D - 1; 0 <= i; i--) {

            // コンプリートしない予定のものだけ
            if ((ptn >> i & 1) == 0) {

                boolean breakflg = false;

                for (int j = 0; j < p[i]; j++) {

                    pnt += 100 * (i + 1);
                    num++;

                    if (j != p[i] - 1 && G <= pnt) {
                        breakflg = true;
                        // コンプリートしなかった
                        // 有効
                        break;
                    } else if (j == p[i] - 1) {
                        breakflg = true;
                        // コンプリートした
                        // 無効
                        flg = false;
                        break;
                    }
                }

                if (breakflg) break;
            }
        }

        return num;
    }
}

class FastScanner {
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
        while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
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
        while(true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if(b == -1 || !isPrintableChar(b)) {
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
