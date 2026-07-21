import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.NoSuchElementException;

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

public class Main {
    // static int MOD = 1000000007;

    // public static class Mas {
    // int x;
    // int y;
    // int step;

    // Mas(int x, int y, int step) {
    // this.x = x;
    // this.y = y;
    // this.step = step;
    // }
    // }

    static long pow(long l, long i) {
        if (i == 0)
            return 1;
        else {
            if (i % 2 == 0) {
                long val = pow(l, i / 2);
                return val * val % 2019;
            } else {
                return pow(l, i - 1) * l % 2019;
            }
        }
    }

    private static final int[] vX = { 1, 0, 0, -1 };
    private static final int[] vY = { 0, 1, -1, 0 };
    static int N;
    static int M;
    static int X;
    static int[] C;
    static int[][] A;
    static int min;

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int a = 0;
        BigInteger k = new BigInteger(fs.next());
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = fs.nextInt() - 1;
        }
        int current = a;
        int[] visited = new int[n];
        int i = 1;
        do {
            visited[current] = i++;
            current = b[current];
        } while (visited[current] == 0);
        if (k.compareTo(BigInteger.valueOf(visited[current])) >= 0) {
            k = k.add(BigInteger.valueOf(1 - visited[current])).remainder(BigInteger.valueOf(i - visited[current]))
                    .add(BigInteger.valueOf(visited[current]));
        } else {
            k = k.add(BigInteger.ONE);
        }
        for (int j = 0; j < n; j++) {
            if (k.longValue() == visited[j]) {
                System.out.println(j + 1);
                return;
            }
        }

    }
}
