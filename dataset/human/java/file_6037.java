import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.reflect.Field;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.function.IntBinaryOperator;
import java.util.function.IntFunction;
import java.util.function.IntPredicate;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;


public class Main {
    public static void main(String[] args) throws Exception {
        Field f = System.out.getClass().getDeclaredField("autoFlush");
        f.setAccessible(true);
        f.set(System.out, false);
        execute(System.in, System.out);
    }

    public static void execute(InputStream in, OutputStream out) {
        ExtendedScanner s = new ExtendedScanner(in);
        Out o = new Out(out);
        solve(s, o);
        o.flush();
        o.close();
    }

    public static void solve(ExtendedScanner sc, Out out) {
        int n = sc.nextInt();
        int[] a = sc.ints(n);
        int[] b = sc.ints(n);
        int[] c = new int[n];
        int[] d = new int[n];
        int ans = 0;
        for (int k = 0; k < 29; k++) {
            int mask = (1 << (k + 1)) - 1;
            for (int i = 0; i < n; i++) {
                c[i] = a[i] & mask;
                d[i] = b[i] & mask;
            }
            Arrays.sort(d);
            int ck = 0;
            for (int i = 0; i < n; i++) {
                int l1 = 1 * (1 << k) - c[i];
                int r1 = 2 * (1 << k) - c[i];
                int l2 = 3 * (1 << k) - c[i];
                int r2 = 4 * (1 << k) - c[i];
                int c1 = IntArrays.countRange(d, l1, r1);
                int c2 = IntArrays.countRange(d, l2, r2);
                ck ^= (c1 ^ c2) & 1;
            }
            ans |= ck << k;
        }
        out.writeln(ans);
    }
}


/**
 * @author https://atcoder.jp/users/suisen
 */
class BasicScanner {
    private final InputStream in;
    private final byte[] buf = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    public BasicScanner(InputStream in) {this.in = in;}
    private boolean hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        try {buflen = in.read(buf);}
        catch (final IOException e) {e.printStackTrace();}
        return buflen > 0;
    }
    private int readByte() {return hasNextByte() ? buf[ptr++] : -1;}
    public boolean hasNext() {
        while (hasNextByte() && !(33 <= buf[ptr] && buf[ptr] <= 126)) ptr++;
        return hasNextByte();
    }
    private StringBuilder nextSequence() {
        if (!hasNext()) throw new NoSuchElementException();
        final StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (33 <= b && b <= 126) {sb.appendCodePoint(b); b = readByte();}
        return sb;
    }
    public char nextChar() {
        return (char) readByte();
    }
    public String next() {
        return nextSequence().toString();
    }
    public String next(int len) {
        return new String(nextChars(len));
    }
    public char[] nextChars() {
        final StringBuilder sb = nextSequence();
        int l = sb.length();
        char[] dst = new char[l];
        sb.getChars(0, l, dst, 0);
        return dst;
    }
    public char[] nextChars(int len) {
        if (!hasNext()) throw new NoSuchElementException();
        char[] s = new char[len];
        int i = 0;
        int b = readByte();
        while (33 <= b && b <= 126 && i < len) {s[i++] = (char) b; b = readByte();}
        if (i != len) throw new NoSuchElementException(String.format("length %d is longer than the sequence.", len));
        return s;
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {minus = true; b = readByte();}
        if (b < '0' || '9' < b) throw new NumberFormatException();
        while (true) {
            if ('0' <= b && b <= '9') n = n * 10 + b - '0';
            else if (b == -1 || !(33 <= b && b <= 126)) return minus ? -n : n;
            else throw new NumberFormatException();
            b = readByte();
        }
    }
    public int nextInt() {return Math.toIntExact(nextLong());}
    public double nextDouble() {return Double.parseDouble(next());}
}


/**
 * @author https://atcoder.jp/users/suisen
 */
class Out {
    private final OutputStream out;
    private byte[] buf = new byte[1024];
    private int ptr = 0;
    private static final int AUTO_FLUSH_THRETHOLD = 1 << 17;

    public Out(OutputStream out) {
        this.out = out;
    }

    public void flush() {
        try {
            out.write(buf, 0, ptr);
            out.flush();
            ptr = 0;
        } catch (IOException e) {e.printStackTrace();}
    }

    public void close() {
        try {out.close();} catch (IOException e) {e.printStackTrace();}
    }

    public Out writeln() {return write('\n');}
    public Out writeln(Object o) {return write(o).write('\n');}
    public Out writeln(String s) {return write(s).write('\n');}
    public Out writeln(char[] c) {return write(c).write('\n');}
    public Out writeln(char   c) {return write(c).write('\n');}
    public Out writeln(byte   b) {return write(b).write('\n');}
    public Out writeln(int    x) {return write(x).write('\n');}
    public Out writeln(long   x) {return write(x).write('\n');}
    public Out writeln(double d) {return write(d).write('\n');}

    public Out writeSpace() {return write(' ');}
    
    public Out write(Object o) {
        return write(o.toString());
    }

    public Out write(String s) {
        try {
            Field strValueField = s.getClass().getDeclaredField("value");
            strValueField.setAccessible(true);
            byte[] b = (byte[]) strValueField.get(s);
            int l = s.length();
            if (l > AUTO_FLUSH_THRETHOLD) {
                flush();
                int i = 0;
                while (i + AUTO_FLUSH_THRETHOLD < l) {
                    out.write(b, i, AUTO_FLUSH_THRETHOLD);
                    out.flush();
                    i += AUTO_FLUSH_THRETHOLD;
                }
                ensureCapacity(l - i);
                System.arraycopy(b, i, buf, 0, l - i);
                ptr = l - i;
            } else {
                ensureCapacity(ptr + l);
                System.arraycopy(b, 0, buf, ptr, l);
                ptr += l;
            }
        } catch (Exception e) {e.printStackTrace();}
        return this;
    }

    public Out write(char[] c) {
        int l = c.length;
        if (l > AUTO_FLUSH_THRETHOLD) {
            flush();
            ensureCapacity(AUTO_FLUSH_THRETHOLD);
            int i = 0;
            while (i + AUTO_FLUSH_THRETHOLD < l) {
                for (int j = 0; j < AUTO_FLUSH_THRETHOLD; j++) {
                    buf[ptr++] = (byte) c[i + j];
                }
                flush();
                i += AUTO_FLUSH_THRETHOLD;
            }
            for (; i < l; i++) {
                buf[ptr++] = (byte) c[i];
            }
        } else {
            ensureCapacity(ptr + l);
            for (char ch : c) buf[ptr++] = (byte) ch;
        }
        return this;
    }

    public Out write(char c) {
        ensureCapacity(ptr + 1);
        buf[ptr++] = (byte) c;
        return this;
    }

    public Out write(byte b) {
        ensureCapacity(ptr + 1);
        buf[ptr++] = b;
        return this;
    }

    public Out write(int x) {
        if (x == 0) {
            ensureCapacity(ptr + 1);
            buf[ptr++] = '0';
            return this;
        }
        int d = stringSize(x);
        ensureCapacity(ptr + d);
        if (x < 0) {
            buf[ptr++] = '-';
            x = -x;
            d--;
        }
        int j = ptr + d; 
        while (x > 0) {
            buf[--j] = (byte) ('0' + (x % 10));
            x /= 10;
        }
        ptr += d;
        return this;
    }

    public Out write(long x) {
        if (x == 0) {
            ensureCapacity(ptr + 1);
            buf[ptr++] = '0';
            return this;
        }
        int d = stringSize(x);
        ensureCapacity(ptr + d);
        if (x < 0) {
            buf[ptr++] = '-';
            x = -x;
            d--;
        }
        int j = ptr + d; 
        while (x > 0) {
            buf[--j] = (byte) ('0' + (x % 10));
            x /= 10;
        }
        ptr += d;
        return this;
    }

    public Out write(double d) {
        return write(Double.toString(d));
    }

    private void ensureCapacity(int cap) {
        if (cap > AUTO_FLUSH_THRETHOLD) {
            flush();
        }
        if (cap >= buf.length) {
            int newLength = buf.length;
            while (newLength < cap) newLength <<= 1;
            byte[] newBuf = new byte[newLength];
            System.arraycopy(buf, 0, newBuf, 0, buf.length);
            buf = newBuf;
        }
    }
    private static int stringSize(long x) {
        int d = 1;
        if (x >= 0) {d = 0; x = -x;}
        long p = -10;
        for (int i = 1; i < 19; i++, p *= 10) if (x > p) return i + d;
        return 19 + d;
    }
    private static int stringSize(int x) {
        int d = 1;
        if (x >= 0) {d = 0; x = -x;}
        int p = -10;
        for (int i = 1; i < 10; i++, p *= 10) if (x > p) return i + d;
        return 10 + d;
    }
}


/**
 * @author https://atcoder.jp/users/suisen
 */
final class IntPair {
    public int fst, snd;
    public IntPair(final int fst, final int snd) {this.fst = fst; this.snd = snd;}
    @Override @SuppressWarnings("all")
    public boolean equals(final Object o) {
        if (this == o) return true;
        if (!(o instanceof IntPair)) return false;
        final IntPair p = (IntPair) o;
        return this.fst == p.fst && this.snd == p.snd;
    }
    @Override
    public int hashCode() {return Objects.hash(this.fst, this.snd);}
    @Override
    public String toString() {return "(" + this.fst + ", " + this.snd + ")";}
}


/**
 * @author https://atcoder.jp/users/suisen
 */
final class ExtendedScanner extends BasicScanner {
    public ExtendedScanner(InputStream in) {super(in);}
    public int[] ints(final int n) {
        final int[] a = new int[n];
        Arrays.setAll(a, $ -> nextInt());
        return a;
    }
    public int[] ints(final int n, final IntUnaryOperator f) {
        final int[] a = new int[n];
        Arrays.setAll(a, $ -> f.applyAsInt(nextInt()));
        return a;
    }
    public int[][] ints(final int n, final int m) {
        final int[][] a = new int[n][];
        Arrays.setAll(a, $ -> ints(m));
        return a;
    }
    public int[][] ints(final int n, final int m, final IntUnaryOperator f) {
        final int[][] a = new int[n][];
        Arrays.setAll(a, $ -> ints(m, f));
        return a;
    }
    public long[] longs(final int n) {
        final long[] a = new long[n];
        Arrays.setAll(a, $ -> nextLong());
        return a;
    }
    public long[] longs(final int n, final LongUnaryOperator f) {
        final long[] a = new long[n];
        Arrays.setAll(a, $ -> f.applyAsLong(nextLong()));
        return a;
    }
    public long[][] longs(final int n, final int m) {
        final long[][] a = new long[n][];
        Arrays.setAll(a, $ -> longs(m));
        return a;
    }
    public long[][] longs(final int n, final int m, final LongUnaryOperator f) {
        final long[][] a = new long[n][];
        Arrays.setAll(a, $ -> longs(m, f));
        return a;
    }
    public char[][] charArrays(final int n) {
        final char[][] c = new char[n][];
        Arrays.setAll(c, $ -> nextChars());
        return c;
    }
    public char[][] charArrays(final int n, final int m) {
        final char[][] c = new char[n][];
        Arrays.setAll(c, $ -> nextChars(m));
        return c;
    }
    public double[] doubles(final int n) {
        final double[] a = new double[n];
        Arrays.setAll(a, $ -> nextDouble());
        return a;
    }
    public double[][] doubles(final int n, final int m) {
        final double[][] a = new double[n][];
        Arrays.setAll(a, $ -> doubles(m));
        return a;
    }
    public String[] strings(final int n) {
        final String[] s = new String[n];
        Arrays.setAll(s, $ -> next());
        return s;
    }
    public String[] strings(final int n, final int m) {
        final String[] s = new String[n];
        Arrays.setAll(s, $ -> next(m));
        return s;
    }
}



/**
 * @author https://atcoder.jp/users/suisen
 * 
 * 1. DESTRUCTIVE methods for int arrays.
 * 2. methods that receives arrays and return some results (except for int arrays).
 */
final class IntArrays {
    private IntArrays(){}
    public static void swap(final int[] a, final int u, final int v) {
        final int tmp = a[u]; a[u] = a[v]; a[v] = tmp;
    }
    public static void reverse(final int[] a, int begin, int end) {
        while (end - begin > 1) swap(a, begin++, --end);
    }
    public static void reverse(final int[] a) {reverse(a, 0, a.length);}
    public static void sortDescending(final int[] a) {Arrays.sort(a); reverse(a);}
    public static int fold(final int[] a, final IntBinaryOperator op) {
        int ret = a[0]; for (int i = 1; i < a.length; i++) ret = op.applyAsInt(ret, a[i]);
        return ret;
    }
    public static int sum(final int[] a) {return fold(a, Integer::sum);}
    public static int max(final int[] a) {return fold(a, Integer::max);}
    public static int min(final int[] a) {return fold(a, Integer::min);}
    public static IntPair maxWithIndex(final int[] a) {
        int max = max(a); return new IntPair(find(a, max), max);
    }
    public static IntPair minWithIndex(final int[] a) {
        int min = min(a); return new IntPair(find(a, min), min);
    }
    public static int find(final int[] a, final int v) {
        for (int i = 0; i < a.length; i++) if (a[i] == v) return i;
        return -1;
    }
    public static void map(final int[] a, final IntUnaryOperator op) {Arrays.setAll(a, i -> op.applyAsInt(a[i]));}
    public static int filter(final int[] src, final int[] dst, final IntPredicate p) {
        int idx = 0;
        for (final int e : src) if (p.test(e)) dst[idx++] = e;
        return idx;
    }
    public static int filterIndex(final int[] dst, final int beginIndex, final int endIndex, final IntPredicate p) {
        int idx = 0;
        for (int i = beginIndex; i < endIndex; i++) if (p.test(i)) dst[idx++] = i;
        return idx;
    }
    public static int filterIndex(final int dst[], final int endIndex, final IntPredicate p) {
        return filterIndex(dst, 0, endIndex, p);
    }
    public static void accumulate(final int[] a, final IntBinaryOperator op) {
        for (int i = 1; i < a.length; i++) a[i] = op.applyAsInt(a[i - 1], a[i]);
    }
    public static void accumulate(final int[] a) {
        for (int i = 1; i < a.length; i++) a[i] += a[i - 1];
    }
    public static void permute(int[] p, int[] a) {
        int n = p.length;
        boolean[] settled = new boolean[n];
        for (int i = 0; i < n; i++) {
            for (int j = i; !settled[j]; j = p[j]) {
                if (p[j] == i) {
                    settled[j] = true;
                    break;
                }
                int tmp = a[j]; a[j] = a[p[j]]; a[p[j]] = tmp;
                settled[j] = true;
            }
        }
    }
    public static void permute2(int[] p, int[] a, int[] b) {
        int n = p.length;
        boolean[] settled = new boolean[n];
        for (int i = 0; i < n; i++) {
            for (int j = i; !settled[j]; j = p[j]) {
                if (p[j] == i) {
                    settled[j] = true;
                    break;
                }
                int tmp;
                tmp = a[j]; a[j] = a[p[j]]; a[p[j]] = tmp;
                tmp = b[j]; b[j] = b[p[j]]; b[p[j]] = tmp;
                settled[j] = true;
            }
        }
    }
    public static void permute3(int[] p, int[] a, int[] b, int[] c) {
        int n = p.length;
        boolean[] settled = new boolean[n];
        for (int i = 0; i < n; i++) {
            for (int j = i; !settled[j]; j = p[j]) {
                if (p[j] == i) {
                    settled[j] = true;
                    break;
                }
                int tmp;
                tmp = a[j]; a[j] = a[p[j]]; a[p[j]] = tmp;
                tmp = b[j]; b[j] = b[p[j]]; b[p[j]] = tmp;
                tmp = c[j]; c[j] = c[p[j]]; c[p[j]] = tmp;
                settled[j] = true;
            }
        }
    }
    public static void permuteN(int[] p, int[]... as) {
        for (int[] a : as) permute(p, a);
    }
    public static int lowerBound(int[] sorted, int key) {
        int n = sorted.length;
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (sorted[m] < key) l = m;
            else r = m;
        }
        return r;
    }
    public static int upperBound(int[] sorted, int key) {
        int n = sorted.length;
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (sorted[m] <= key) l = m;
            else r = m;
        }
        return r;
    }
    public static int countRange(int[] sorted, int fromKey, int toKey) {
        return lowerBound(sorted, toKey) - lowerBound(sorted, fromKey);
    }
    public static int compare(final int[] a, final int[] b) {
        for (int i = 0; i < a.length; i++) {
            if (i >= b.length) return -1;
            if (a[i] > b[i]) return 1;
            if (a[i] < b[i]) return -1;
        }
        return a.length < b.length ? 1 : 0;
    }
    public static boolean equals(final int[] a, final int[] b) {return compare(a, b) == 0;}
    public static String join(final int[] a, final String sep) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            sb.append(a[i]);
            if (i < a.length - 1) sb.append(sep);
        }
        return sb.toString();
    }
    public static String joinWithPrefixAndSuffix(final int[] a, final IntFunction<String> idxToPre, final IntFunction<String> idxToSuf, final String sep) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            sb.append(idxToPre.apply(i)).append(a[i]).append(idxToSuf.apply(i));
            if (i < a.length - 1) sb.append(sep);
        }
        return sb.toString();
    }
}

/**
 * @author https://atcoder.jp/users/suisen
 */
final class BitUtil {
    private static final int[] INT_MASK = {
        0x0000_0000,
        0x0000_0001, 0x0000_0003, 0x0000_0007, 0x0000_000f,
        0x0000_001f, 0x0000_003f, 0x0000_007f, 0x0000_00ff,
        0x0000_01ff, 0x0000_03ff, 0x0000_07ff, 0x0000_0fff,
        0x0000_1fff, 0x0000_3fff, 0x0000_7fff, 0x0000_ffff,
        0x0001_ffff, 0x0003_ffff, 0x0007_ffff, 0x000f_ffff,
        0x001f_ffff, 0x003f_ffff, 0x007f_ffff, 0x00ff_ffff,
        0x01ff_ffff, 0x03ff_ffff, 0x07ff_ffff, 0x0fff_ffff,
        0x1fff_ffff, 0x3fff_ffff, 0x7fff_ffff, 0xffff_ffff
    };
    private static final long[] LONG_MASK = {
        0x0000_0000_0000_0000l,
        0x0000_0000_0000_0001l, 0x0000_0000_0000_0003l, 0x0000_0000_0000_0007l, 0x0000_0000_0000_000fl, 
        0x0000_0000_0000_001fl, 0x0000_0000_0000_003fl, 0x0000_0000_0000_007fl, 0x0000_0000_0000_00ffl, 
        0x0000_0000_0000_01ffl, 0x0000_0000_0000_03ffl, 0x0000_0000_0000_07ffl, 0x0000_0000_0000_0fffl,
        0x0000_0000_0000_1fffl, 0x0000_0000_0000_3fffl, 0x0000_0000_0000_7fffl, 0x0000_0000_0000_ffffl, 
        0x0000_0000_0001_ffffl, 0x0000_0000_0003_ffffl, 0x0000_0000_0007_ffffl, 0x0000_0000_000f_ffffl, 
        0x0000_0000_001f_ffffl, 0x0000_0000_003f_ffffl, 0x0000_0000_007f_ffffl, 0x0000_0000_00ff_ffffl, 
        0x0000_0000_01ff_ffffl, 0x0000_0000_03ff_ffffl, 0x0000_0000_07ff_ffffl, 0x0000_0000_0fff_ffffl, 
        0x0000_0000_1fff_ffffl, 0x0000_0000_3fff_ffffl, 0x0000_0000_7fff_ffffl, 0x0000_0000_ffff_ffffl,
        0x0000_0001_ffff_ffffl, 0x0000_0003_ffff_ffffl, 0x0000_0007_ffff_ffffl, 0x0000_000f_ffff_ffffl, 
        0x0000_001f_ffff_ffffl, 0x0000_003f_ffff_ffffl, 0x0000_007f_ffff_ffffl, 0x0000_00ff_ffff_ffffl, 
        0x0000_01ff_ffff_ffffl, 0x0000_03ff_ffff_ffffl, 0x0000_07ff_ffff_ffffl, 0x0000_0fff_ffff_ffffl,
        0x0000_1fff_ffff_ffffl, 0x0000_3fff_ffff_ffffl, 0x0000_7fff_ffff_ffffl, 0x0000_ffff_ffff_ffffl, 
        0x0001_ffff_ffff_ffffl, 0x0003_ffff_ffff_ffffl, 0x0007_ffff_ffff_ffffl, 0x000f_ffff_ffff_ffffl, 
        0x001f_ffff_ffff_ffffl, 0x003f_ffff_ffff_ffffl, 0x007f_ffff_ffff_ffffl, 0x00ff_ffff_ffff_ffffl, 
        0x01ff_ffff_ffff_ffffl, 0x03ff_ffff_ffff_ffffl, 0x07ff_ffff_ffff_ffffl, 0x0fff_ffff_ffff_ffffl, 
        0x1fff_ffff_ffff_ffffl, 0x3fff_ffff_ffff_ffffl, 0x7fff_ffff_ffff_ffffl, 0xffff_ffff_ffff_ffffl
    };
    private BitUtil(){}
    public static boolean test (final long n, final int bit) {return (n & (1l << bit)) != 0;}
    public static boolean test (final int  n, final int bit) {return (n & (1  << bit)) != 0;}

    public static int     get  (final long n, final int bit) {return (n & (1l << bit)) == 0 ? 1 : 0;}
    public static int     get  (final int  n, final int bit) {return (n & (1  << bit)) == 0 ? 1 : 0;}

    public static long    set  (final long n, final int bit)                   {return n | (1l << bit);}
    public static int     set  (final int  n, final int bit)                   {return n | (1  << bit);}
    public static long    set  (final long n, final int from, final int to)    {return n | (LONG_MASK[to - from] << from);}
    public static int     set  (final int  n, final int from, final int to)    {return n | (INT_MASK [to - from] << from);}
    public static long    set  (final long n, final int bit,  final boolean b) {return b ? n | (1l << bit) : n & ~(1l << bit);}
    public static int     set  (final int  n, final int bit,  final boolean b) {return b ? n | (1  << bit) : n & ~(1  << bit);}
    public static long    set  (final long n, final int from, final int to, final boolean b) {return b ? n | (LONG_MASK[to - from] << from) : n & ~(LONG_MASK[to - from] << from);}
    public static int     set  (final int  n, final int from, final int to, final boolean b) {return b ? n | (INT_MASK [to - from] << from) : n & ~(INT_MASK [to - from] << from);}

    public static long    clear(final long n, final int bit)                {return n & ~(1l << bit);}
    public static int     clear(final int  n, final int bit)                {return n & ~(1  << bit);}
    public static long    clear(final long n, final int from, final int to) {return n & ~(LONG_MASK[to - from] << from);}
    public static int     clear(final int  n, final int from, final int to) {return n & ~(INT_MASK [to - from] << from);}

    public static long    flip (final long n, final int bit)                {return n ^ (1l << bit);}
    public static int     flip (final int  n, final int bit)                {return n ^ (1  << bit);}
    public static long    flip (final long n, final int from, final int to) {return n ^ (LONG_MASK[to - from] << from);}
    public static int     flip (final int  n, final int from, final int to) {return n ^ (INT_MASK [to - from] << from);}

    public static long    mask (final long n, final int bit)                {return n & (1l << bit);}
    public static int     mask (final int  n, final int bit)                {return n & (1  << bit);}
    public static long    mask (final long n, final int from, final int to) {return n & (LONG_MASK[to - from] << from);}
    public static int     mask (final int  n, final int from, final int to) {return n & (INT_MASK [to - from] << from);}

    public static int     bsr  (final long n) {return 63 - Long   .numberOfLeadingZeros (n);}
    public static int     bsr  (final int  n) {return 31 - Integer.numberOfLeadingZeros (n);}
}
