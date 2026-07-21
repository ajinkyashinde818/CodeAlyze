import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringJoiner;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;

class Main {
    static In in = new In();
    static Out out = new Out();
    static long mod = 1000000007;
    static long inf = 0xfffffffffffffffL;

    void solve() {
        int n = in.nextInt();
        long[] x = new long[n - 1];
        x[0] = -in.nextLong();
        for (int i = 1; i < n; i++) {
            long a = in.nextLong();
            x[i - 1] += a;
            if (i < n - 1) {
                x[i] -= a;
            }
        }
        long[] fac = new long[n + 1];
        long[] inv = new long[n + 1];
        fac[0] = inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = powAndMod(fac[i], mod - 2);
        }
        long temp = 0;
        long temp2 = 0;
        for (int i = 1; i < n; i++) {
            temp2 = (temp2 * i % mod + fac[i - 1]) % mod;
            temp = (temp + temp2 * x[i - 1] % mod * fac[n - 1] % mod * inv[i] % mod) % mod;
        }
        out.println(temp);
    }

    static long powAndMod(long a, long b) {
        long x = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                x = x * a % mod;
                b--;
            } else {
                a = a * a % mod;
                b /= 2;
            }
        }
        return x;
    }

    public static void main(String[]$) {
        new Main().solve();
        out.flush();
    }
}

class In {
    private BufferedInputStream reader = new BufferedInputStream(System.in);
    private byte[] buffer = new byte[0x10000];
    private int i = 0;
    private int length = 0;

    private int read() {
        if (i == length) {
            i = 0;
            try {
                length = reader.read(buffer);
            } catch (IOException ignored) {
            }
            if (length == -1) {
                return -1;
            }
        }
        return buffer[i++];
    }

    String next() {
        StringBuilder builder = new StringBuilder();
        int b = read();
        while (b < '!' || '~' < b) {
            b = read();
        }
        while ('!' <= b && b <= '~') {
            builder.appendCodePoint(b);
            b = read();
        }
        return builder.toString();
    }

    int nextInt() {
        return (int)nextLong();
    }

    long nextLong() {
        int b = read();
        while (b < '!' || '~' < b) {
            b = read();
        }
        int i = 0;
        if (b == '-') {
            i = 1;
            b = read();
        }
        long n = 0;
        while ('0' <= b && b <= '9') {
            n = n * 10 + b - '0';
            b = read();
        }
        return i == 0 ? n : -n;
    }

    char[][] nextCharArray(int n, int m) {
        char[][] a = new char[n][m];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        return a;
    }

    int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    int[] nextIntArray(int n, IntUnaryOperator op) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = op.applyAsInt(nextInt());
        }
        return a;
    }

    long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        return a;
    }

    long[] nextLongArray(int n, LongUnaryOperator op) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = op.applyAsLong(nextLong());
        }
        return a;
    }
}

class Out {
    private static PrintWriter out = new PrintWriter(System.out);

    void println(Object... a) {
        StringJoiner joiner = new StringJoiner(" ");
        for (Object obj : a) {
            joiner.add(String.valueOf(obj));
        }
        out.println(joiner);
    }

    void flush() {
        out.flush();
    }
}
