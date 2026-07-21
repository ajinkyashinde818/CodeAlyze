import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.function.DoubleUnaryOperator;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;

public class Main {
    public static void main(String[] args) {
        Out out = new Out();
        solve(out);
        out.outln();
        out.flush();
        out.close();
    }

    public static void solve(Out out) {
        int k = In.ni();
        int n = In.ni();
        int[] a = In.ni(n);
        int maxd = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                maxd = Math.max(maxd, a[i + 1] - a[i]);
            } else {
                maxd = Math.max(maxd, a[0] + k - a[i]);
            }
        }
        out.append(k - maxd);
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
        if (hasNextByte()) {
            return buffer[ptr++];
        } else {
            return -1;
        }
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
            ptr++;
        }
        return hasNextByte();
    }

    public String next() {
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

    public long nextLong() {
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


class Out {
    private StringBuilder sb = new StringBuilder();
    private PrintWriter w = new PrintWriter(System.out);

    public Out() {
    }

    public void append(int v) {
        sb.append(v);
    }

    public void append(long v) {
        sb.append(v);
    }

    public void append(char c) {
        sb.append(c);
    }

    public void append(double v) {
        sb.append(v);
    }

    public void append(char[] c) {
        sb.append(c);
    }

    public void append(String s) {
        sb.append(s);
    }

    public void append(Object e) {
        sb.append(e);
    }

    public void append(int[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(long[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(char[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(double[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(char[][] c, String sep) {
        for (int i = 0; i < c.length; i++) {
            append(c[i]);
            if (i < c.length - 1) {
                append(sep);
            }
        }
    }

    public void append(String[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(Object[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void out() {
        w.print(sb);
        clearBuilder();
    }

    public void outln() {
        w.println(sb);
        clearBuilder();
    }

    public void print(int v) {
        w.print(v);
    }

    public void print(long v) {
        w.print(v);
    }

    public void print(char c) {
        w.print(c);
    }

    public void print(double v) {
        w.print(v);
    }

    public void print(String s) {
        w.print(s);
    }

    public void print(Object e) {
        w.print(e);
    }

    public void print(String sep, int... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, long... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, char... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, double... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, String... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, Object... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void println() {
        w.println();
    }

    public void println(int v) {
        w.println(v);
    }

    public void println(long v) {
        w.println(v);
    }

    public void println(double v) {
        w.println(v);
    }

    public void println(char c) {
        w.println(c);
    }

    public void println(String s) {
        w.println(s);
    }

    public void println(Object e) {
        w.println(e);
    }

    public void println(String sep, int... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, long... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, double... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, char... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, String... a) {
        print(sep, a);
        println();
    }

    // public void println(String sep, Object... a) {
    //     print(sep, a);
    //     println();
    // }

    public void flush() {
        w.flush();
    }

    public void close() {
        w.close();
    }

    public void clearBuilder() {
        sb = new StringBuilder();
    }

    public void reverse() {
        sb.reverse();
    }

    public void delete(int start, int end) {
        sb.delete(start, end);
    }

    public void delete(int length) {
        sb.delete(sb.length() - length, sb.length());
    }

    public int length() {
        return sb.length();
    }
}


class In {
    public static final FastScanner fsc = new FastScanner();

    public static int ni() {
        return fsc.nextInt();
    }

    public static int ni(IntUnaryOperator f) {
        return f.applyAsInt(fsc.nextInt());
    }

    public static int[] ni(int n) {
        int[] a = new int[n];
        Arrays.setAll(a, i -> fsc.nextInt());
        return a;
    }

    public static int[] ni (int n, IntUnaryOperator f) {
        int[] a = new int[n];
        Arrays.setAll(a, i -> ni(f));
        return a;
    }

    public static int[][] ni(int n, int m) {
        int[][] a = new int[n][m];
        Arrays.setAll(a, i -> ni(m));
        return a;
    }

    public static int[][] ni(int n, int m, IntUnaryOperator f) {
        int[][] a = new int[n][m];
        Arrays.setAll(a, i -> ni(m, f));
        return a;
    }

    public static long nl() {
        return fsc.nextLong();
    }

    public static long nl(LongUnaryOperator f) {
        return f.applyAsLong(fsc.nextLong());
    }

    public static long[] nl(int n) {
        long[] a = new long[n];
        Arrays.setAll(a, i -> fsc.nextLong());
        return a;
    }

    public static long[] nl(int n, LongUnaryOperator f) {
        long[] a = new long[n];
        Arrays.setAll(a, i -> nl(f));
        return a;
    }

    public static long[][] nl(int n, int m) {
        long[][] a = new long[n][m];
        Arrays.setAll(a, i -> nl(m));
        return a;
    }

    public static long[][] nl(int n, int m, LongUnaryOperator f) {
        long[][] a = new long[n][m];
        Arrays.setAll(a, i -> nl(m, f));
        return a;
    }

    public static char[] nc() {
        return fsc.next().toCharArray();
    }

    public static char[][] nc(int n, int m) {
        char[][] c = new char[n][m];
        Arrays.setAll(c, i -> nc());
        return c;
    }

    public static double nd() {
        return fsc.nextDouble();
    }

    public static double nd(DoubleUnaryOperator f) {
        return f.applyAsDouble(fsc.nextDouble());
    }

    public static double[] nd(int n) {
        double[] a = new double[n];
        Arrays.setAll(a, i -> fsc.nextDouble());
        return a;
    }

    public static double[] nd(int n, DoubleUnaryOperator f) {
        double[] a = new double[n];
        Arrays.setAll(a, i -> nd(f));
        return a;
    }

    public static double[][] nd(int n, int m) {
        double[][] a = new double[n][m];
        Arrays.setAll(a, i -> nd(m));
        return a;
    }

    public static double[][] nd(int n, int m, DoubleUnaryOperator f) {
        double[][] a = new double[n][m];
        Arrays.setAll(a, i -> nd(m, f));
        return a;
    }

    public static String ns() {
        return fsc.next();
    }

    public static String[] ns(int n) {
        String[] s = new String[n];
        Arrays.setAll(s, i -> ns());
        return s;
    }

    public static boolean[][] grid(int h, int w, char trueCharacter) {
        boolean[][] grid = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            char[] s = fsc.next().toCharArray();
            for (int j = 0; j < w; j++) {
                grid[i][j] = s[j] == trueCharacter;
            }
        }
        return grid;
    }
}
