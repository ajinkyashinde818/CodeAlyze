import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.Map.Entry;
import java.util.NoSuchElementException;
import static java.lang.Math.E;
import static java.lang.Math.PI;
import static java.lang.Math.abs;
import static java.lang.Math.acos;
import static java.lang.Math.asin;
import static java.lang.Math.atan2;
import static java.lang.Math.atan;
import static java.lang.Math.cos;
import static java.lang.Math.exp;
import static java.lang.Math.hypot;
import static java.lang.Math.log;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.sin;
import static java.lang.Math.sqrt;
import static java.lang.Math.tan;
import static java.lang.String.format;
import static java.lang.System.currentTimeMillis;
import static java.math.BigInteger.ONE;
import static java.math.BigInteger.TEN;
import static java.math.BigInteger.ZERO;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;
import static java.util.Collections.sort;
import static java.util.Comparator.reverseOrder;
import static java.util.Objects.isNull;
import static java.util.Objects.nonNull;

public class Main {
    public static void main(String[] args) {
        FastScanner fsc = new FastScanner();
        char[] s = fsc.next().toCharArray();
        int q = fsc.nextInt();
        ArrayDeque<Character> ans = new ArrayDeque<>();
        for (char c : s) {
            ans.addLast(c);
        }
        boolean rev = false;
        while (q-- > 0) {
            int t = fsc.nextInt();
            if (t == 1) {
                rev = !rev;
            } else {
                int f = fsc.nextInt();
                char c = fsc.next().charAt(0);
                if (f == 1) {
                    if (rev) {
                        ans.addLast(c);
                    } else {
                        ans.addFirst(c);
                    }
                } else {
                    if (rev) {
                        ans.addFirst(c);
                    } else {
                        ans.addLast(c);
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        while (ans.size() > 0) {
            if (rev) {
                sb.append(ans.pollLast());
            } else {
                sb.append(ans.pollFirst());
            }
        }
        System.out.println(sb);
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
