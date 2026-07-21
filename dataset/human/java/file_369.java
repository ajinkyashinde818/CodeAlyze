import static java.lang.Math.max;
import static java.lang.Math.sqrt;

import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.NoSuchElementException;

public class Main {
    public static void main(String[] args) {
        FastScanner fsc = new FastScanner();
        long xs = fsc.nextLong();
        long ys = fsc.nextLong();
        long xt = fsc.nextLong();
        long yt = fsc.nextLong();
        int n = fsc.nextInt();
        long[][] xyr = new long[n + 2][3];
        xyr[0][0] = xs;
        xyr[0][1] = ys;
        xyr[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            long x = fsc.nextLong();
            long y = fsc.nextLong();
            long r = fsc.nextLong();
            xyr[i][0] = x;
            xyr[i][1] = y;
            xyr[i][2] = r;
        }
        xyr[n + 1][0] = xt;
        xyr[n + 1][1] = yt;
        xyr[n + 1][2] = 0;
        double[][] cost = new double[n + 2][n + 2];
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                long xsq = (xyr[i][0] - xyr[j][0]) * (xyr[i][0] - xyr[j][0]);
                long ysq = (xyr[i][1] - xyr[j][1]) * (xyr[i][1] - xyr[j][1]);
                double d = sqrt(xsq + ysq);
                cost[i][j] = max(d - xyr[i][2] - xyr[j][2], 0);
            }
        }
        double[] d = new double[n + 2];
        Arrays.fill(d, 1e100);
        d[0] = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i <= n + 1; i++) {
            set.add(i);
        }
        for (int q = 0; q < n + 1; q++) {
            double minD = 1e100;
            int minV = -1;
            for (int v : set) {
                if (d[v] < minD) {
                    minD = d[v];
                    minV = v;
                }
            }
            for (int to = 0; to <= n + 1; to++) {
                if (d[minV] + cost[minV][to] < d[to]) {
                    d[to] = d[minV] + cost[minV][to];
                }
            }
            set.remove(minV);
        }
        System.out.println(d[n + 1]);
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
