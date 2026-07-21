import java.io.*;
import java.math.*;
import java.util.*;

class MyScanner {
    private final InputStream in = System.in;
    private final byte[] buf = new byte[1024];
    private int p = 0;
    private int len = 0;
    private boolean hasNextByte() {
        if (p >= len) {
            p = 0;
            try {
                len = in.read(buf);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return len >= 1;
    }
    private boolean isPrintableChar(int c) { return 33 <= c && c <= 126; }
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buf[p])) p++;
        return hasNextByte();
    }
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        while (hasNextByte() && isPrintableChar(buf[p])) sb.appendCodePoint(buf[p++]);
        return sb.toString();
    }
    public BigDecimal nextBigDecimal() { return new BigDecimal(next()); }
    public BigInteger nextBigInteger() { return new BigInteger(next()); }
    public BigInteger nextBigInteger(int radix) { return new BigInteger(next(), radix); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public int nextInt() { return Integer.parseInt(next()); }
    public int nextInt(int radix) { return Integer.parseInt(next(), radix); }
    public long nextLong() { return Long.parseLong(next()); }
    public long nextLong(int radix) { return Long.parseLong(next(), radix); }
}

public class Main {
    public static void main(String[] args){
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = sc.nextInt();
        long k = sc.nextLong();
        Integer[][] a = new Integer[62][n + 1];
        int t = 1;
        for (int i = 1; i <= n; i++) a[0][i] = sc.nextInt();
        for (int i = 0; i < 61; i++) {
            for (int j = 1; j <= n; j++) {
                a[i + 1][j] = a[i][a[i][j]];
            }
            if ((k >> i & 1) == 1) t = a[i][t];
        }
        out.println(t);
        out.flush();
    }
}
