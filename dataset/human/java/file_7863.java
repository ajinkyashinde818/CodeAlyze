import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.TreeSet;
import java.util.function.DoubleUnaryOperator;
import java.util.function.IntPredicate;
import java.util.function.IntUnaryOperator;
import java.util.function.LongBinaryOperator;
import java.util.function.LongPredicate;
import java.util.function.LongUnaryOperator;
import java.util.function.Predicate;


public class Main {
    public static void main(String[] args) {
        StringBuilder out = new StringBuilder();
        solve(out);
        PrintWriter pw = new PrintWriter(System.out);
        pw.println(out);
        pw.flush();
        pw.close();
    }

    public static void solve(StringBuilder out) {
        int n = In.ni();
        long k = In.nl();
        int[] a = In.ni(n, e -> e - 1);
        Doubling d = new Doubling(a, k);
        out.append(d.query(0, k) + 1);
    }
}


/**
 * @author https://atcoder.jp/users/suisen
 */
final class In {
    public static final FastScanner fsc = new FastScanner();

    public static int ni() {
        return fsc.nextInt();
    }

    public static int ni(final IntUnaryOperator f) {
        return f.applyAsInt(fsc.nextInt());
    }

    public static int[] ni(final int n) {
        final int[] a = new int[n];
        Arrays.setAll(a, i -> fsc.nextInt());
        return a;
    }

    public static int[] ni(final int n, final IntUnaryOperator f) {
        final int[] a = new int[n];
        Arrays.setAll(a, i -> ni(f));
        return a;
    }

    public static int[][] ni(final int n, final int m) {
        final int[][] a = new int[n][m];
        Arrays.setAll(a, i -> ni(m));
        return a;
    }

    public static int[][] ni(final int n, final int m, final IntUnaryOperator f) {
        final int[][] a = new int[n][m];
        Arrays.setAll(a, i -> ni(m, f));
        return a;
    }

    public static long nl() {
        return fsc.nextLong();
    }

    public static long nl(final LongUnaryOperator f) {
        return f.applyAsLong(fsc.nextLong());
    }

    public static long[] nl(final int n) {
        final long[] a = new long[n];
        Arrays.setAll(a, i -> fsc.nextLong());
        return a;
    }

    public static long[] nl(final int n, final LongUnaryOperator f) {
        final long[] a = new long[n];
        Arrays.setAll(a, i -> nl(f));
        return a;
    }

    public static long[][] nl(final int n, final int m) {
        final long[][] a = new long[n][m];
        Arrays.setAll(a, i -> nl(m));
        return a;
    }

    public static long[][] nl(final int n, final int m, final LongUnaryOperator f) {
        final long[][] a = new long[n][m];
        Arrays.setAll(a, i -> nl(m, f));
        return a;
    }

    public static char[] nc() {
        return fsc.next().toCharArray();
    }

    public static char[][] nc(final int n, final int m) {
        final char[][] c = new char[n][m];
        Arrays.setAll(c, i -> nc());
        return c;
    }

    public static double nd() {
        return fsc.nextDouble();
    }

    public static double nd(final DoubleUnaryOperator f) {
        return f.applyAsDouble(fsc.nextDouble());
    }

    public static double[] nd(final int n) {
        final double[] a = new double[n];
        Arrays.setAll(a, i -> fsc.nextDouble());
        return a;
    }

    public static double[] nd(final int n, final DoubleUnaryOperator f) {
        final double[] a = new double[n];
        Arrays.setAll(a, i -> nd(f));
        return a;
    }

    public static double[][] nd(final int n, final int m) {
        final double[][] a = new double[n][m];
        Arrays.setAll(a, i -> nd(m));
        return a;
    }

    public static double[][] nd(final int n, final int m, final DoubleUnaryOperator f) {
        final double[][] a = new double[n][m];
        Arrays.setAll(a, i -> nd(m, f));
        return a;
    }

    public static String ns() {
        return fsc.next();
    }

    public static String[] ns(final int n) {
        final String[] s = new String[n];
        Arrays.setAll(s, i -> ns());
        return s;
    }

    public static boolean[][] grid(final int h, final int w, final char trueCharacter) {
        final boolean[][] grid = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            final char[] s = fsc.next().toCharArray();
            for (int j = 0; j < w; j++) {
                grid[i][j] = s[j] == trueCharacter;
            }
        }
        return grid;
    }
}


final class FastScanner {
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
            } catch (final IOException e) {
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

    private static boolean isPrintableChar(final int c) {
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
        final StringBuilder sb = new StringBuilder();
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
        final long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
            throw new NumberFormatException();
        }
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}


/**
 * @author https://atcoder.jp/users/suisen
 */
final class MathUtil{
    private static final long UNDER32_MASK = 0xffff_ffffl;

    private MathUtil(){}
    
    /**
     * Enumarate primes equal to or less than n.
     * @param n
     * @return {@code ArrayList} that holds primes.
     */
    public static ArrayList<Integer> eratosthenes(final int n) {
        final int[] div = eratosthenesDivisors(n);
        final ArrayList<Integer> result = new ArrayList<>();
        for (int i = 2; i <= n; i++)
            if (div[i] == i)
                result.add(i);
        return result;
    }

    /**
     * execute eratosthenes's prime-enumerate algorithm. a[i] holds the greatest
     * divisor of i. if a[i] = i, i is a prime number. This arrary enables you to
     * prime-factorize in O(log n) time.
     * 
     * @param n
     * @return divisor array.
     */
    public static int[] eratosthenesDivisors(final int n) {
        final int[] divisors = new int[n + 1];
        if (n <= 0)
            return null;
        for (int i = 1; i <= n; i++) {
            if ((i & 1) != 0)
                divisors[i] = i;
            else
                divisors[i] = 2;
        }
        for (int i = 3; i <= n; i += 2) {
            if (divisors[i] == i) {
                for (long j = (long) i * i; j <= n; j += i << 1) {
                    divisors[(int) j] = i;
                }
            }
        }
        return divisors;
    }

    /**
     * Caluculate prime-factorization in O(sqrt(n)) time.
     * 
     * @param n
     * @return {@code HashMap} of {prime: index}
     */
    public static HashMap<Long, Integer> primeFactorization(long n) {
        final HashMap<Long, Integer> primes = new HashMap<>();
        for (long p = 2; p * p <= n; p++) {
            int q = 0;
            while (n % p == 0) {
                n /= p;
                q++;
            }
            if (q > 0)
                primes.put(p, q);
        }
        if (n > 1)
            primes.put(n, 1);
        return primes;
    }

    public static TreeSet<Long> divisors(final long n) {
        final TreeSet<Long> divisors = new TreeSet<>();
        for (long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.add(i);
                divisors.add(n / i);
            }
        }
        return divisors;
    }

    private static HashMap<Long, Integer> lcmMap(final HashMap<Long, Integer> amap, final HashMap<Long, Integer> bmap) {
        if (amap.size() < bmap.size())
            return lcmMap(bmap, amap);
        final HashMap<Long, Integer> lcm = amap;
        for (final Map.Entry<Long, Integer> e : bmap.entrySet()) {
            final long prime = e.getKey();
            if (lcm.containsKey(prime))
                lcm.put(prime, Math.max(lcm.get(prime), e.getValue()));
            else
                lcm.put(prime, e.getValue());
        }
        return lcm;
    }

    private static HashMap<Long, Integer> lcmMap(final HashMap<Long, Integer> amap, final long b) {
        final HashMap<Long, Integer> bmap = primeFactorization(b);
        return lcmMap(amap, bmap);
    }

    public static HashMap<Long, Integer> lcmMap(final long... a) {
        HashMap<Long, Integer> amap = new HashMap<>();
        for (final long c : a)
            amap = lcmMap(amap, c);
        return amap;
    }

    /**
     * calculate lcm(a, b) fast. (NOT considering overflow.)
     */
    public static long lcm(final long a, final long b) {
        return (a / gcd(a, b)) * b;
    }

    /**
     * Caluculate the GCD of (a, b)/
     * 
     * @param a first value
     * @param b second value
     * @return GCD(a, b)
     */
    public static long gcd(long a, long b) {
        if (a < b)
            return gcd(b, a);
        if (b == 0)
            return a;
        if (a == 0)
            return b;
        long r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }

    public static long gcd(final long... a) {
        long gcd = 0;
        for (final long c : a)
            gcd = gcd(gcd, c);
        return gcd;
    }

    /**
     * Return one of the solutions to {@code ax+by=gcd(a, b)}.
     * 
     * @return {@code x}, {@code y}, {@code gcd(a, b)}.
     * @param a a of ax+by=gcd(a, b).
     * @param b b of ax+by=gcd(a, b).
     */
    public static long[] extGCD(final long a, final long b) {
        final long[] ret = new long[3];
        final long[] xy = new long[2];
        ret[2] = extGCD(a, b, xy);
        ret[0] = xy[0];
        ret[1] = xy[1];
        return ret;
    }

    private static long extGCD(final long a, final long b, final long[] xy) {
        if (b == 0) {
            xy[0] = 1;
            xy[1] = 0;
            return a;
        }
        long tmp = xy[0]; xy[0] = xy[1]; xy[1] = tmp;
        final long d = extGCD(b, a % b, xy);
        tmp = xy[0]; xy[0] = xy[1]; xy[1] = tmp;
        xy[1] -= a / b * xy[0];
        return d;
    }

    /**
     * caluculate a ^ b NOT considering overflow. so if you want to calculate a ^ b
     * (mod p), use ModUtil.pow(a, b).
     * 
     * @param a base
     * @param b exponent
     * @return a ^ b
     */
    public static long pow(final int a, long b) {
        long ret = 1l;
        for (long c = 1, ac = a; b > 0; ac *= ac, c <<= 1) {
            if ((-b & b) == c) {
                ret *= ac;
                b &= ~(-b & b);
            }
        }
        return ret;
    }

    /**
     * Caluculate the combination nCr NOT considering overflow.
     * 
     * @param n left
     * @param r right
     * @return nCr
     */
    public static long comb(long n, long r) {
        if (n < r)
            return 0;
        r = Math.min(r, n - r);
        long res = 1;
        for (long d = 1; d <= r; d++) {
            res *= n--;
            res /= d;
        }
        return res;
    }

    public static long ceilSqrt(final long n) {
        long l = -1;
        long r = n;
        while (r - l > 1) {
            final long m = (r + l) >> 1;
            if (m * m >= n) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }

    public static long floorSqrt(final long n) {
        long l = 0;
        long r = n + 1;
        while (r - l > 1) {
            final long m = (r + l) >> 1;
            if (m * m > n) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    }

    public static long int2ToLong(final int upper, final int lower) {
        return ((long) upper << Integer.SIZE) | lower;
    }

    public static int upper32(final long l) {
        return (int) (l >>> Integer.SIZE);
    }

    public static int lower32(final long l) {
        return (int) (l & UNDER32_MASK);
    }
}


/**
 * @author https://atcoder.jp/users/suisen
 */
@FunctionalInterface
interface IntBiPredicate {
    static final int INT_BIT = 32;
    static final long MASK = 0xffff_ffffl;

    public boolean test(int x, int y);

    default public IntPredicate curry(final int x) {
        return y -> test(x, y);
    }

    default public LongPredicate toLongPredicate() {
        return l -> test((int) (l >>> INT_BIT), (int) (l & MASK));
    }

    default public IntBiPredicate negate() {
        return (x, y) -> !test(x, y);
    }

    default public IntBiPredicate and(final IntBiPredicate other) {
        return (x, y) -> test(x, y) && other.test(x, y);
    }

    default public IntBiPredicate or(final IntBiPredicate other) {
        return (x, y) -> test(x, y) || other.test(x, y);
    }

    default public IntBiPredicate xor(final IntBiPredicate other) {
        return (x, y) -> test(x, y) ^ other.test(x, y);
    }
}


/**
 * @author https://atcoder.jp/users/suisen
 */
final class Longs {
    private static final char[] hex = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    private Longs(){}

    public static long max(final long... a) {
        long ret = Long.MIN_VALUE;
        for (final long e : a) {
            ret = Math.max(ret, e);
        }
        return ret;
    }

    public static long min(final long... a) {
        long ret = Long.MAX_VALUE;
        for (final long e : a) {
            ret = Math.min(ret, e);
        }
        return ret;
    }

    public static long reduce(final LongBinaryOperator func, final long... a) {
        long ret = a[0];
        for (int i = 1; i < a.length; i++) {
            ret = func.applyAsLong(ret, a[i]);
        }
        return ret;
    }

    public static boolean isPowerOfTwo(final long n) {
        return n != 0 && (-n & n) == n;
    }

    public static int ceilExponent(final long n) {
        return 63 - Long.numberOfLeadingZeros(n) + (isPowerOfTwo(n) ? 0 : 1);
    }

    public static int floorExponent(final long n) {
        return 63 - Long.numberOfLeadingZeros(n) + (n == 0 ? 1 : 0);
    }

    public static int ceilExponent(final long n, final int base) {
        if (base == 2) {
            return ceilExponent(n);
        }
        int i = 0;
        long m = 1;
        while (m < n) {
            i++;
            final long r = m * base;
            if ((m | base) >> 31 != 0 && r / base != m) {
                break;
            }
            m = r;
        }
        return i;
    }

    /**
     * Caluculate the ceil of a/b. Returns the smallest integer greater than or
     * equal to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the smallest integer greater than or equal to a/b
     */
    public static long cld(final long a, final long b) {
        if (a > 0 && b > 0)
            return (a + b - 1) / b;
        else if (a < 0 && b < 0)
            return (a + b + 1) / b;
        else
            return a / b;
    }

    /**
     * Caluculate the floor of a/b. Returns the largest integer less than or equal
     * to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the largest integer less than or equal to a/b
     */
    public static long fld(final long a, final long b) {
        if (a <= 0 && b > 0)
            return (a - b + 1) / b;
        else if (a > 0 && b <= 0)
            return (a - b - 1) / b;
        else
            return a / b;
    }

    public static String join(final String sep, final long... a) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            sb.append(a[i]);
            if (i < a.length - 1) {
                sb.append(sep);
            }
        }
        return sb.toString();
    }

    public static String toBinaryString(long n) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Long.SIZE; i++, n >>= 1) {
            sb.append(n & 1);
            if ((i & 3) == 3) {
                sb.append('_');
            }
        }
        return sb.reverse().toString();
    }

    public static String toHexString(long n) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0, t = Long.SIZE >> 2; i < t; i++, n >>= 4) {
            sb.append(hex[(int) n & 0xf]);
            if ((i & 3) == 3) {
                sb.append('_');
            }
        }
        return sb.reverse().toString();
    }
}



/**
 * @author https://atcoder.jp/users/suisen
 */
final class Doubling {
    private final int[][] doubling;
    private final int height;
    private final int n;

    public Doubling(final int[] a, final long maxStep) {
        this.n = a.length;
        this.height = Longs.ceilExponent(maxStep) + 2;
        this.doubling = new int[height][n];
        build(a);
    }

    public int getHeight() {
        return height;
    }

    public int query(int i, long step) {
        int h = height - 1;
        while (step > 0) {
            if ((step & (1l << h)) != 0) {
                i = doubling[h][i];
                step ^= 1l << h;
            }
            h--;
        }
        return i;
    }

    public int step(final int i, final int exponent) {
        return doubling[exponent][i];
    }

    public int stepWhile(int i, final IntPredicate p) {
        int h = height - 1;
        while (h >= 0) {
            if (p.test(doubling[h][i])) {
                i = doubling[h][i];
            }
            h--;
        }
        return i;
    }

    public int stepUntil(final int i, final IntPredicate p) {
        return p.test(i) ? i : doubling[0][stepWhile(i, p.negate())];
    }

    public int[] biStep(final int u, final int v, final int exponent) {
        final int us = doubling[exponent][u];
        final int vs = doubling[exponent][v];
        return new int[]{us, vs};
    }

    private long biStep(final long uv, final int exponent) {
        final int u = MathUtil.upper32(uv);
        final int v = MathUtil.lower32(uv);
        return MathUtil.int2ToLong(doubling[exponent][u], doubling[exponent][v]);
    }

    public int[] biStepWhile(final int u, final int v, final IntBiPredicate p) {
        final long ret = biStepWhile(MathUtil.int2ToLong(u, v), p.toLongPredicate());
        return new int[]{MathUtil.upper32(ret), MathUtil.lower32(ret)};
    }

    private long biStepWhile(long uv, final LongPredicate p) {
        int h = height - 1;
        while (h >= 0) {
            final long step = biStep(uv, h);
            if (p.test(step)) {
                uv = step;
            }
            h--;
        }
        return uv;
    }

    public int[] biStepUntil(final int u, final int v, final IntBiPredicate p) {
        final long ret = biStepUntil(MathUtil.int2ToLong(u, v), p.toLongPredicate());
        return new int[]{MathUtil.upper32(ret), MathUtil.lower32(ret)};
    }

    private long biStepUntil(final long uv, final LongPredicate p) {
        return p.test(uv) ? uv : biStep(biStepWhile(uv, p.negate()), 0);
    }

    public int[] parallelStep(final int[] a, final int exponent) {
        final int[] ret = a.clone();
        for (int i = 0; i < a.length; i++) {
            ret[i] = doubling[exponent][a[i]];
        }
        return ret;
    }

    public int[] parallelStepWhile(final int[] a, final Predicate<int[]> p) {
        int[] ret = a.clone();
        int h = height - 1;
        while (h >= 0) {
            final int[] step = parallelStep(ret, h);
            if (p.test(step)) {
                ret = step;
            }
            h--;
        }
        return ret;
    }

    public int[] parallelStepUntil(final int[] a, final Predicate<int[]> p) {
        return p.test(a) ? a.clone() : parallelStep(parallelStepWhile(a, p.negate()), 0);
    }

    private void build(final int[] a) {
        doubling[0] = a.clone();
        for (int h = 1; h < height; h++) {
            for (int i = 0; i < n; i++) {
                doubling[h][i] = doubling[h - 1][doubling[h - 1][i]];
            }
        }
    }
}
