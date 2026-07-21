import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main implements Runnable{

    private void solve(FastIO io, String[] args) {
        ModUtility modUtil = new ModUtility(MOD, (int)1e5);
        int N = io.nextInt();
        int[] x = new int[N];
        for (int i = 0; i < N; ++i) x[i] = io.nextInt();
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < N - 1; ++i) {
            cur += modUtil.divide(modUtil.fact[N - 1] ,i + 1);
            cur %= MOD;
            ans += modUtil.multiply(cur, (x[i + 1] - x[i]));
            ans %= MOD;
        }
        io.println(ans);
    }

    /** debug */
    private static boolean DEBUG = false;
    /** the size of memroy (unit: MB)*/
    private static final long MEMORY = 64;
    private final FastIO io;
    private final String[] args;

    public static void main(String[] args) {
        Thread.setDefaultUncaughtExceptionHandler((t, e) -> e.printStackTrace());
        new Thread(null, new Main(args), "", MEMORY * 1048576).start();
    }

    public Main(String[] args) {
        this(new FastIO(), args);
    }

    public Main(FastIO io, String... args) {
        this.io = io;
        this.args = args;
        if (DEBUG) io.setAutoFlush(true);
    }

    @Override
    public void run() {
        try {
            solve(io, args);
        } catch (Throwable e) {
            throw e;
        } finally {
            io.flush();
        }
    }


    /**
     * 高速な入出力を提供します。
     * @author 31536000
     *
     */
    public static class FastIO {
        private InputStream in;
        private final byte[] buffer = new byte[1024];
        private int read = 0;
        private int length = 0;
        private PrintWriter out;
        private PrintWriter err;
        private boolean autoFlush = false;

        public FastIO() {
            this(System.in, System.out, System.err);
        }

        public FastIO(InputStream in, PrintStream out, PrintStream err) {
            this.in = in;
            this.out = new PrintWriter(out, false);
            this.err = new PrintWriter(err, false);
        }

        public final void setInputStream(InputStream in) {
            this.in = in;
        }

        public final void setInputStream(File in) {
            try {
                this.in = new FileInputStream(in);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public final void setOutputStream(PrintStream out) {
            this.out = new PrintWriter(out, false);
        }

        public final void setOutputStream(File out) {
            try {
                this.out = new PrintWriter(new FileOutputStream(out), false);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public final void setErrorStream(PrintStream err) {
            this.err = new PrintWriter(err, false);
        }

        public final void setErrorStream(File err) {
            try {
                this.err = new PrintWriter(new FileOutputStream(err), false);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public final void setAutoFlush(boolean flush) {
            autoFlush = flush;
        }

        private boolean hasNextByte() {
            if (read < length) return true;
            read = 0;
            try {
                length = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return length > 0;
        }

        private int readByte() {
            return hasNextByte() ? buffer[read++] : -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        private static boolean isNumber(int c) {
            return '0' <= c && c <= '9';
        }

        public final boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[read])) read++;
            return hasNextByte();
        }

        public final char nextChar() {
            if (!hasNextByte())  throw new NoSuchElementException();
            return (char)readByte();
        }

        public final char[][] nextChar(int height) {
            char[][] ret = new char[height][];
            for (int i = 0;i < ret.length;++ i) ret[i] = next().toCharArray();
            return ret;
        }

        public final String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b;
            while (isPrintableChar(b = readByte())) sb.appendCodePoint(b);
            return sb.toString();
        }

        public final String nextLine() {
            StringBuilder sb = new StringBuilder();
            int b;
            while(!isPrintableChar(b = readByte()));
            do sb.appendCodePoint(b); while(isPrintableChar(b = readByte()) || b == ' ');
            return sb.toString();
        }

        public final long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (!isNumber(b)) throw new NumberFormatException();
            while (true) {
                if (isNumber(b)) {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) return minus ? -n : n;
                else throw new NumberFormatException();
                b = readByte();
            }
        }

        public final int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        public final double nextDouble() {
            return Double.parseDouble(next());
        }

        public final int[] nextInt(int width) {
            int[] ret = new int[width];
            for (int i = 0;i < width;++ i) ret[i] = nextInt();
            return ret;
        }

        public final int[] nextInts() {
            return nextInts(" ");
        }

        public final int[] nextInts(String parse) {
            String[] get = nextLine().split(parse);
            int[] ret = new int[get.length];
            for (int i = 0;i < ret.length;++ i) ret[i] = Integer.valueOf(get[i]);
            return ret;
        }

        public final long[] nextLong(int width) {
            long[] ret = new long[width];
            for (int i = 0;i < width;++ i) ret[i] = nextLong();
            return ret;
        }

        public final long[] nextLongs() {
            return nextLongs(" ");
        }

        public final long[] nextLongs(String parse) {
            String[] get = nextLine().split(parse);
            long[] ret = new long[get.length];
            for (int i = 0;i < ret.length;++ i) ret[i] = Long.valueOf(get[i]);
            return ret;
        }

        public final int[][] nextInt(int width, int height) {
            int[][] ret = new int[height][width];
            for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[i][j] = nextInt();
            return ret;
        }

        public final long[][] nextLong(int width, int height) {
            long[][] ret = new long[height][width];
            for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[j][i] = nextLong();
            return ret;
        }

        public final boolean[] nextBoolean(char T) {
            char[] s = next().toCharArray();
            boolean[] ret = new boolean[s.length];
            for (int i = 0;i < ret.length;++ i) ret[i] = s[i] == T;
            return ret;
        }

        public final boolean[][] nextBoolean(char T, int height) {
            boolean[][] ret = new boolean[height][];
            for (int i = 0;i < ret.length;++ i) {
                char[] s = next().toCharArray();
                ret[i] = new boolean[s.length];
                for (int j = 0;j < ret[i].length;++ j) ret[i][j] = s[j] == T;
            }
            return ret;
        }

        public final Point nextPoint() {
            return new Point(nextInt(), nextInt());
        }

        public final Point[] nextPoint(int width) {
            Point[] ret = new Point[width];
            for (int i = 0;i < width;++ i) ret[i] = nextPoint();
            return ret;
        }

        @Override
        protected void finalize() throws Throwable {
            try {
                super.finalize();
            } finally {
                in.close();
                out.close();
                err.close();
            }
        }

        public final boolean print(boolean b) {
            out.print(b);
            if (autoFlush) flush();
            return b;
        }

        public final Object print(boolean b, Object t, Object f) {
            return b ? print(t) : print(f);
        }

        public final char print(char c) {
            out.print(c);
            if (autoFlush) flush();
            return c;
        }

        public final char[] print(char[] s) {
            out.print(s);
            return s;
        }

        public final double print(double d) {
            out.print(d);
            if (autoFlush) flush();
            return d;
        }

        public final double print(double d, int length) {
            if (d < 0) {
                out.print('-');
                d = -d;
            }
            d += Math.pow(10, -length) / 2;
            out.print((long)d);
            out.print('.');
            d -= (long)d;
            for (int i = 0;i < length;++ i) {
                d *= 10;
                out.print((int)d);
                d -= (int)d;
            }
            if (autoFlush) flush();
            return d;
        }

        public final float print(float f) {
            out.print(f);
            if (autoFlush) flush();
            return f;
        }

        public final int print(int i) {
            out.print(i);
            if (autoFlush) flush();
            return i;
        }

        public final long print(long l) {
            out.print(l);
            if (autoFlush) flush();
            return l;
        }

        public final Object print(Object obj) {
            if (obj != null && obj.getClass().isArray()) {
                if (obj instanceof boolean[][]) print(obj, "\n", " ");
                else if (obj instanceof byte[][]) print(obj, "\n", " ");
                else if (obj instanceof short[][]) print(obj, "\n", " ");
                else if (obj instanceof int[][]) print(obj, "\n", " ");
                else if (obj instanceof long[][]) print(obj, "\n", " ");
                else if (obj instanceof float[][]) print(obj, "\n", " ");
                else if (obj instanceof double[][]) print(obj, "\n", " ");
                else if (obj instanceof char[][]) print(obj, "\n", " ");
                else if (obj instanceof Object[][]) print(obj, "\n", " ");
                else print(obj, " ");
            } else {
                out.print(obj);
                if (autoFlush) flush();
            }
            return obj;
        }

        public final String print(String s) {
            out.print(s);
            if (autoFlush) flush();
            return s;
        }

        public final Object print(Object array, String... parse) {
            print(array, 0, parse);
            if (autoFlush) flush();
            return array;
        }

        private final Object print(Object array, int check, String... parse) {
            if (check >= parse.length) {
                if (array != null && array.getClass().isArray()) throw new IllegalArgumentException("not equal dimension");
                print(array);
                return array;
            }
            String str = parse[check];
            if (array instanceof Object[]) {
                Object[] obj = (Object[]) array;
                if (obj.length == 0) return array;
                print(obj[0], check + 1, parse);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i], check + 1, parse);
                }
                return array;
            }
            if (array instanceof Collection) {
                Iterator<?> iter = ((Collection<?>)array).iterator();
                if (!iter.hasNext()) return array;
                print(iter.next(), check + 1, parse);
                while(iter.hasNext()) {
                    print(str);
                    print(iter.next(), check + 1, parse);
                }
                return array;
            }
            if (!array.getClass().isArray()) throw new IllegalArgumentException("not equal dimension");
            if (check != parse.length - 1) throw new IllegalArgumentException("not equal dimension");
            if (array instanceof boolean[]) {
                boolean[] obj = (boolean[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
            } else if (array instanceof byte[]) {
                byte[] obj = (byte[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
                return array;
            } else if (array instanceof short[]) {
                short[] obj = (short[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
            } else if (array instanceof int[]) {
                int[] obj = (int[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
            } else if (array instanceof long[]) {
                long[] obj = (long[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
            } else if (array instanceof float[]) {
                float[] obj = (float[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
            } else if (array instanceof double[]) {
                double[] obj = (double[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
            } else if (array instanceof char[]) {
                char[] obj = (char[]) array;
                if (obj.length == 0) return array;
                print(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    print(str);
                    print(obj[i]);
                }
            } else throw new AssertionError();
            return array;
        }

        public final Object[] print(String parse, Object... args) {
            print(args[0]);
            for (int i = 1;i < args.length;++ i) {
                print(parse);
                print(args[i]);
            }
            return args;
        }

        public final Object[] printf(String format, Object... args) {
            out.printf(format, args);
            if (autoFlush) flush();
            return args;
        }

        public final Object printf(Locale l, String format, Object... args) {
            out.printf(l, format, args);
            if (autoFlush) flush();
            return args;
        }

        public final void println() {
            out.println();
            if (autoFlush) flush();
        }

        public final boolean println(boolean b) {
            out.println(b);
            if (autoFlush) flush();
            return b;
        }

        public final Object println(boolean b, Object t, Object f) {
            return b ? println(t) : println(f);
        }

        public final char println(char c) {
            out.println(c);
            if (autoFlush) flush();
            return c;
        }

        public final char[] println(char[] s) {
            out.println(s);
            if (autoFlush) flush();
            return s;
        }

        public final double println(double d) {
            out.println(d);
            if (autoFlush) flush();
            return d;
        }

        public final double println(double d, int length) {
            print(d, length);
            println();
            return d;
        }

        public final float println(float f) {
            out.println(f);
            if (autoFlush) flush();
            return f;
        }

        public final int println(int i) {
            out.println(i);
            if (autoFlush) flush();
            return i;
        }

        public final long println(long l) {
            out.println(l);
            if (autoFlush) flush();
            return l;
        }

        public final Object println(Object obj) {
            print(obj);
            println();
            return obj;
        }

        public final String println(String s) {
            out.println(s);
            if (autoFlush) flush();
            return s;
        }

        public final Object println(Object array, String... parse) {
            print(array, parse);
            println();
            return array;
        }

        public final boolean debug(boolean b) {
            err.print(b);
            if (autoFlush) flush();
            return b;
        }

        public final Object debug(boolean b, Object t, Object f) {
            return b ? debug(t) : debug(f);
        }

        public final char debug(char c) {
            err.print(c);
            if (autoFlush) flush();
            return c;
        }

        public final char[] debug(char[] s) {
            err.print(s);
            return s;
        }

        public final double debug(double d) {
            err.print(d);
            if (autoFlush) flush();
            return d;
        }

        public final double debug(double d, int length) {
            if (d < 0) {
                err.print('-');
                d = -d;
            }
            d += Math.pow(10, -length) / 2;
            err.print((long)d);
            err.print('.');
            d -= (long)d;
            for (int i = 0;i < length;++ i) {
                d *= 10;
                err.print((int)d);
                d -= (int)d;
            }
            if (autoFlush) flush();
            return d;
        }

        public final float debug(float f) {
            err.print(f);
            if (autoFlush) flush();
            return f;
        }

        public final int debug(int i) {
            err.print(i);
            if (autoFlush) flush();
            return i;
        }

        public final long debug(long l) {
            err.print(l);
            if (autoFlush) flush();
            return l;
        }

        public final Object debug(Object obj) {
            if (obj != null && obj.getClass().isArray()) {
                if (obj instanceof boolean[][]) debug(obj, "\n", " ");
                else if (obj instanceof byte[][]) debug(obj, "\n", " ");
                else if (obj instanceof short[][]) debug(obj, "\n", " ");
                else if (obj instanceof int[][]) debug(obj, "\n", " ");
                else if (obj instanceof long[][]) debug(obj, "\n", " ");
                else if (obj instanceof float[][]) debug(obj, "\n", " ");
                else if (obj instanceof double[][]) debug(obj, "\n", " ");
                else if (obj instanceof char[][]) debug(obj, "\n", " ");
                else if (obj instanceof Object[][]) debug(obj, "\n", " ");
                else debug(obj, " ");
            } else {
                err.print(obj);
                if (autoFlush) flush();
            }
            return obj;
        }

        public final String debug(String s) {
            err.print(s);
            if (autoFlush) flush();
            return s;
        }

        public final Object debug(Object array, String... parse) {
            debug(array, 0, parse);
            if (autoFlush) flush();
            return array;
        }

        private final Object debug(Object array, int check, String... parse) {
            if (check >= parse.length) {
                if (array != null && array.getClass().isArray()) throw new IllegalArgumentException("not equal dimension");
                debug(array);
                return array;
            }
            String str = parse[check];
            if (array instanceof Object[]) {
                Object[] obj = (Object[]) array;
                if (obj.length == 0) return array;
                debug(obj[0], check + 1, parse);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i], check + 1, parse);
                }
                return array;
            }
            if (array instanceof Collection) {
                Iterator<?> iter = ((Collection<?>)array).iterator();
                if (!iter.hasNext()) return array;
                debug(iter.next(), check + 1, parse);
                while(iter.hasNext()) {
                    debug(str);
                    debug(iter.next(), check + 1, parse);
                }
                return array;
            }
            if (!array.getClass().isArray()) throw new IllegalArgumentException("not equal dimension");
            if (check != parse.length - 1) throw new IllegalArgumentException("not equal dimension");
            if (array instanceof boolean[]) {
                boolean[] obj = (boolean[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
            } else if (array instanceof byte[]) {
                byte[] obj = (byte[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
                return array;
            } else if (array instanceof short[]) {
                short[] obj = (short[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
            } else if (array instanceof int[]) {
                int[] obj = (int[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
            } else if (array instanceof long[]) {
                long[] obj = (long[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
            } else if (array instanceof float[]) {
                float[] obj = (float[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
            } else if (array instanceof double[]) {
                double[] obj = (double[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
            } else if (array instanceof char[]) {
                char[] obj = (char[]) array;
                if (obj.length == 0) return array;
                debug(obj[0]);
                for (int i = 1;i < obj.length;++ i) {
                    debug(str);
                    debug(obj[i]);
                }
            } else throw new AssertionError();
            return array;
        }

        public final Object[] debug(String parse, Object... args) {
            debug(args[0]);
            for (int i = 1;i < args.length;++ i) {
                debug(parse);
                debug(args[i]);
            }
            return args;
        }

        public final Object[] debugf(String format, Object... args) {
            err.printf(format, args);
            if (autoFlush) flush();
            return args;
        }

        public final Object debugf(Locale l, String format, Object... args) {
            err.printf(l, format, args);
            if (autoFlush) flush();
            return args;
        }

        public final void debugln() {
            err.println();
            if (autoFlush) flush();
        }

        public final boolean debugln(boolean b) {
            err.println(b);
            if (autoFlush) flush();
            return b;
        }

        public final Object debugln(boolean b, Object t, Object f) {
            return b ? debugln(t) : debugln(f);
        }

        public final char debugln(char c) {
            err.println(c);
            if (autoFlush) flush();
            return c;
        }

        public final char[] debugln(char[] s) {
            err.println(s);
            if (autoFlush) flush();
            return s;
        }

        public final double debugln(double d) {
            err.println(d);
            if (autoFlush) flush();
            return d;
        }

        public final double debugln(double d, int length) {
            debug(d, length);
            debugln();
            return d;
        }

        public final float debugln(float f) {
            err.println(f);
            if (autoFlush) flush();
            return f;
        }

        public final int debugln(int i) {
            err.println(i);
            if (autoFlush) flush();
            return i;
        }

        public final long debugln(long l) {
            err.println(l);
            if (autoFlush) flush();
            return l;
        }

        public final Object debugln(Object obj) {
            debug(obj);
            debugln();
            return obj;
        }

        public final String debugln(String s) {
            err.println(s);
            if (autoFlush) flush();
            return s;
        }

        public final Object debugln(Object array, String... parse) {
            debug(array, parse);
            debugln();
            return array;
        }

        public final void flush() {
            out.flush();
            err.flush();
        }
    }

    public static int MOD = (int)1e9+7;

    public static class ModInteger extends Number {

        private static final long serialVersionUID = -8595710127161317579L;
        private final int mod;
        private int num;

        private final Addition add;
        private final Multiplication mul;

        private class Addition {

            public ModInteger identity() {
                return new ModInteger(mod, 0);
            }

            public ModInteger inverse(ModInteger element) {
                return new ModInteger(element, element.mod - element.num);
            }

            public ModInteger apply(ModInteger left, ModInteger right) {
                return new ModInteger(left).addEqual(right);
            }
        }

        private class Multiplication {

            public ModInteger identity() {
                return new ModInteger(mod, 1);
            }

            public ModInteger apply(ModInteger left, ModInteger right) {
                return new ModInteger(left).multiplyEqual(right);
            }

            public ModInteger inverse(ModInteger element) {
                return new ModInteger(element, element.inverse(element.num));
            }

        }

        public int characteristic() {
            return mod;
        }

        public ModInteger(int mod) {
            this.mod = mod;
            num = 0;
            add = new Addition();
            mul = new Multiplication();
        }

        public ModInteger(int mod, int num) {
            this.mod = mod;
            this.num = validNum(num);
            add = new Addition();
            mul = new Multiplication();
        }

        public ModInteger(ModInteger n) {
            mod = n.mod;
            num = n.num;
            add = n.add;
            mul = n.mul;
        }

        private ModInteger(ModInteger n, int num) {
            mod = n.mod;
            this.num = num;
            add = n.add;
            mul = n.mul;
        }

        private int validNum(int n) {
            n %= mod;
            if (n < 0) n += mod;
            return n;
        }

        private int validNum(long n) {
            n %= mod;
            if (n < 0) n += mod;
            return (int)n;
        }

        protected int inverse(int n) {
            int m = mod, u = 0, v = 1, t;
            while(n != 0) {
                t = m / n;
                m -= t * n;
                u -= t * v;
                if (m != 0) {
                    t = n / m;
                    n -= t * m;
                    v -= t * u;
                } else {
                    v %= mod;
                    if (v < 0) v += mod;
                    return v;
                }
            }
            u %= mod;
            if (u < 0) u += mod;
            return u;
        }

        public boolean isPrime(int n) {
            if ((n & 1) == 0) return false; // 偶数
            for (int i = 3, j = 8, k = 9;k <= n;i += 2, k += j += 8) if (n % i == 0) return false;
            return true;
        }

        @Override
        public int intValue() {
            return num;
        }

        @Override
        public long longValue() {
            return num;
        }

        @Override
        public float floatValue() {
            return num;
        }

        @Override
        public double doubleValue() {
            return num;
        }

        protected ModInteger getNewInstance(ModInteger mod) {
            return new ModInteger(mod);
        }

        public ModInteger add(int n) {
            return getNewInstance(this).addEqual(n);
        }

        public ModInteger add(long n) {
            return getNewInstance(this).addEqual(n);
        }

        public ModInteger add(ModInteger n) {
            return getNewInstance(this).addEqual(n);
        }

        public ModInteger addEqual(int n) {
            num = validNum(num + n);
            return this;
        }

        public ModInteger addEqual(long n) {
            num = validNum(num + n);
            return this;
        }

        public ModInteger addEqual(ModInteger n) {
            if ((num += n.num) >= mod) num -= mod;
            return this;
        }

        public ModInteger subtract(int n) {
            return getNewInstance(this).subtractEqual(n);
        }

        public ModInteger subtract(long n) {
            return getNewInstance(this).subtractEqual(n);
        }

        public ModInteger subtract(ModInteger n) {
            return getNewInstance(this).subtractEqual(n);
        }

        public ModInteger subtractEqual(int n) {
            num = validNum(num - n);
            return this;
        }

        public ModInteger subtractEqual(long n) {
            num = validNum(num - n);
            return this;
        }

        public ModInteger subtractEqual(ModInteger n) {
            if ((num -= n.num) < 0) num += mod;
            return this;
        }

        public ModInteger multiply(int n) {
            return getNewInstance(this).multiplyEqual(n);
        }

        public ModInteger multiply(long n) {
            return getNewInstance(this).multiplyEqual(n);
        }

        public ModInteger multiply(ModInteger n) {
            return getNewInstance(this).multiplyEqual(n);
        }

        public ModInteger multiplyEqual(int n) {
            num = (int)((long)num * n % mod);
            if (num < 0) num += mod;
            return this;
        }

        public ModInteger multiplyEqual(long n) {
            return multiplyEqual((int) (n % mod));
        }

        public ModInteger multiplyEqual(ModInteger n) {
            num = (int)((long)num * n.num % mod);
            return this;
        }

        public ModInteger divide(int n) {
            return getNewInstance(this).divideEqual(n);
        }

        public ModInteger divide(long n) {
            return getNewInstance(this).divideEqual(n);
        }

        public ModInteger divide(ModInteger n) {
            return getNewInstance(this).divideEqual(n);
        }

        public ModInteger divideEqual(int n) {
            num = (int)((long)num * inverse(validNum(n)) % mod);
            return this;
        }

        public ModInteger divideEqual(long n) {
            return divideEqual((int)(n % mod));
        }

        public ModInteger divideEqual(ModInteger n) {
            num = (int)((long)num * n.inverse(n.num) % mod);
            return this;
        }

        public ModInteger pow(int n) {
            return getNewInstance(this).powEqual(n);
        }

        public ModInteger pow(long n) {
            return getNewInstance(this).powEqual(n);
        }

        public ModInteger pow(ModInteger n) {
            return getNewInstance(this).powEqual(n);
        }

        public ModInteger powEqual(int n) {
            long ans = 1, num = this.num;
            if (n < 0) {
                n = -n;
                while (n != 0) {
                    if ((n & 1) != 0) ans = ans * num % mod;
                    n >>>= 1;
                    num = num * num % mod;
                }
                this.num = inverse((int)ans);
                return this;
            }
            while (n != 0) {
                if ((n & 1) != 0) ans = ans * num % mod;
                n >>>= 1;
                num = num * num % mod;
            }
            this.num = (int)ans;
            return this;
        }
        public ModInteger powEqual(long n) {
            return powEqual((int)(n % (mod - 1)));
        }

        public ModInteger powEqual(ModInteger n) {
            long num = this.num;
            this.num = 1;
            int mul = n.num;
            while (mul != 0) {
                if ((mul & 1) != 0) this.num *= num;
                mul >>>= 1;
                num *= num;
                num %= mod;
            }
            return this;
        }

        public ModInteger equal(int n) {
            num = validNum(n);
            return this;
        }

        public ModInteger equal(long n) {
            num = validNum(n);
            return this;
        }

        public ModInteger equal(ModInteger n) {
            num = n.num;
            return this;
        }

        public int toInt() {
            return num;
        }

        public int getMod() {
            return mod;
        }

        @Override
        public boolean equals(Object x) {
            if (x instanceof ModInteger) return ((ModInteger)x).num == num && ((ModInteger)x).mod == mod;
            return false;
        }

        @Override
        public int hashCode() {
            return num ^ mod;
        }

        @Override
        public String toString() {
            return String.valueOf(num);
        }

        @Deprecated
        public String debug() {
            int min = num, ans = 1;
            for (int i = 2;i < min;++ i) {
                int tmp = multiply(i).num;
                if (min > tmp) {
                    min = tmp;
                    ans = i;
                }
            }
            return min + "/" + ans;
        }

        public Addition getAddition() {
            return add;
        }

        public Multiplication getMultiplication() {
            return mul;
        }
    }

    public static class ModUtility {
        private final int mod;
        private int[] fact, inv, invfact;

        /**
         * modを法として、演算を行います。
         * @param mod 法とする素数
         */
        public ModUtility(int mod) {
            this(mod, 2);
        }

        /**
         * modを法として、演算を行います。
         * @param mod 法とする素数
         * @param calc 予め前計算しておく大きさ
         */
        public ModUtility(int mod, int calc) {
            this.mod = mod;
            precalc(calc);
        }

        /**
         * calcの大きさだけ、前計算を行います。
         * @param calc 前計算をする大きさ
         */
        public void precalc(int calc) {
            ++ calc;
            if (calc < 2) calc = 2;
            fact = new int[calc];
            inv = new int[calc];
            invfact = new int[calc];
            fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
            for (int i = 2;i < calc;++ i) {
                fact[i] = (int)((long)fact[i - 1] * i % mod);
                inv[i] = (int)(mod - (long)inv[mod % i] * (mod / i) % mod);
                invfact[i] = (int)((long)invfact[i - 1] * inv[i] % mod);
            }
        }

        /**
         * modを法とする剰余環上で振舞う整数を返します。
         * @return modを法とする整数、初期値は0
         */
        public ModInteger create() {
            return new ModInt();
        }

        /**
         * modを法とする剰余環上で振舞う整数を返します。
         * @param n 初期値
         * @return modを法とする整数
         */
        public ModInteger create(int n) {
            return new ModInt(n);
        }

        private class ModInt extends ModInteger {

            private static final long serialVersionUID = -2435281861935422575L;

            public ModInt() {
                super(mod);
            }

            public ModInt(int n) {
                super(mod, n);
            }

            public ModInt(ModInteger mod) {
                super(mod);
            }

            @Override
            protected ModInteger getNewInstance(ModInteger mod) {
                return new ModInt(mod);
            }

            @Override
            protected int inverse(int n) {
                return ModUtility.this.inverse(n);
            }
        }

        /**
         * modを法として、nの逆元を返します。<br>
         * 計算量はO(log n)です。
         * @param n 逆元を求めたい値
         * @return 逆元
         */
        public int inverse(int n) {
            try {
                if (inv.length > n) return inv[n];
                int m = mod, u = 0, v = 1, t;
                while(n != 0) {
                    t = m / n;
                    m -= t * n;
                    u -= t * v;
                    if (m != 0) {
                        t = n / m;
                        n -= t * m;
                        v -= t * u;
                    } else {
                        v %= mod;
                        if (v < 0) v += mod;
                        return v;
                    }
                }
                u %= mod;
                if (u < 0) u += mod;
                return u;
            } catch (ArrayIndexOutOfBoundsException e) {
                throw new IllegalArgumentException();
            }
        }

        /**
         * n!を、modを法として求めた値を返します。<br>
         * 計算量はO(n)です。
         * @param n 階乗を求めたい値
         * @return nの階乗をmodで割った余り
         */
        public int factorial(int n) {
            try {
                if (fact.length > n) return fact[n];
                long ret = fact[fact.length - 1];
                for (int i = fact.length;i <= n;++ i) ret = ret * i % mod;
                return (int)ret;
            } catch (ArrayIndexOutOfBoundsException e) {
                throw new IllegalArgumentException();
            }
        }

        /**
         * nPkをmodで割った余りを求めます。<br>
         * 計算量はO(n-k)です。
         * @param n 左辺
         * @param k 右辺
         * @return nPkをmodで割った余り
         */
        public int permutation(int n, int k) {
            if (n < 0) throw new IllegalArgumentException();
            if (n < k) return 0;
            if (fact.length > n) return (int)((long)fact[n] * invfact[n - k] % mod);
            long ret = 1;
            for (int i = n - k + 1;i <= n;++ i) ret = ret * i % mod;
            return (int)ret;
        }

        /**
         * nCkをmodで割った余りを求めます。<br>
         * 計算量はO(n-k)です。
         * @param n 左辺
         * @param k 右辺
         * @return nCkをmodで割った余り
         */
        public int combination(int n, int k) {
            if (n < 0) throw new IllegalArgumentException();
            if (n < k) return 0;
            if (fact.length > n) return (int)((long)fact[n] * invfact[k] % mod * invfact[n - k] % mod);
            long ret = 1;
            if (n < 2 * k) k = n - k;
            if (invfact.length > k) ret = invfact[k];
            else ret = inverse(factorial(k));
            for (int i = n - k + 1;i <= n;++ i) ret = ret * i % mod;
            return (int)ret;
        }

        /**
         * 他項係数をmodで割った余りを求めます。<br>]
         * 計算量はO(n)です。
         * @param n 左辺
         * @param k 右辺、合計がn以下である必要がある
         * @return 他項係数
         */
        public int multinomial(int n, int... k) {
            int sum = 0;
            for (int i : k) sum += i;
            long ret = factorial(n);
            if (fact.length > n) {
                for (int i : k) {
                    if (i < 0) throw new IllegalArgumentException();
                    ret = ret * invfact[i] % mod;
                    sum += i;
                }
                if (sum > n) return 0;
                ret = ret * invfact[n - sum] % mod;
            } else {
                for (int i : k) {
                    if (i < 0) throw new IllegalArgumentException();
                    if (invfact.length > i) ret = ret * invfact[i] % mod;
                    else ret = ret * inverse(factorial(i)) % mod;
                    sum += i;
                }
                if (sum > n) return 0;
                if (invfact.length > n - sum) ret = ret * invfact[n - sum] % mod;
                else ret = ret * inverse(factorial(n - sum)) % mod;
            }
            return (int)ret;
        }

        /**
         * n個からk個を選ぶ重複組み合わせnHkをmodで割った余りを求めます。<br>
         * 計算量はO(min(n, k))です。
         * @param n 左辺
         * @param k 右辺
         * @return nHkをmodで割った余り
         */
        public int multichoose(int n, int k) {
            return combination(mod(n + k - 1), k);
        }

        /**
         * カタラン数C(n)をmodで割った余りを求めます。<br>
         * 計算量はO(n)です。
         * @param n 求めたいカタラン数の番号
         * @return カタラン数
         */
        public int catalan(int n) {
            return divide(combination(mod(2 * n), n), mod(n + 1));
        }

        /**
         * nのm乗をmodで割った余りを求めます。<br>
         * 計算量はO(log m)です。
         * @param n 床
         * @param m 冪指数
         * @return n^mをmodで割った余り
         */
        public int pow(int n, int m) {
            long ans = 1, num = n;
            if (m < 0) {
                m = -m;
                while (m != 0) {
                    if ((m & 1) != 0) ans = ans * num % mod;
                    m >>>= 1;
                    num = num * num % mod;
                }
                return inverse((int)ans);
            }
            while (m != 0) {
                if ((m & 1) != 0) ans = ans * num % mod;
                m >>>= 1;
                num = num * num % mod;
            }
            return (int)ans;
        }

        /**
         * nのm乗をmodで割った余りを求めます。<br>
         * 計算量はO(log m)です。
         * @param n 床
         * @param m 冪指数
         * @return n^mをmodで割った余り
         */
        public int pow(long n, long m) {
            return pow((int)(n % mod), (int)(n % (mod - 1)));
        }

        /**
         * 現在のmod値のトーシェント数を返します。<br>
         * なお、これはmod-1に等しいです。
         * @return トーシェント数
         */
        public int totient() {
            return mod - 1;
        }

        /**
         * nのトーシェント数を返します。<br>
         * 計算量はO(sqrt n)です。
         * @param n トーシェント数を求めたい値
         * @return nのトーシェント数
         */
        public static int totient(int n) {
            int totient = n;
            for (int i = 2;i * i <= n;++ i) {
                if (n % i == 0) {
                    totient = totient / i * (i - 1);
                    while ((n %= i) % i == 0);
                }
            }
            if (n != 1) totient = totient / n * (n - 1);
            return totient;
        }

        /**
         * nをmodで割った余りを返します。
         * @param n 演算する値
         * @return nをmodで割った余り
         */
        public int mod(int n) {
            return (n %= mod) < 0 ? n + mod : n;
        }

        /**
         * nをmodで割った余りを返します。
         * @param n 演算する値
         * @return nをmodで割った余り
         */
        public int mod(long n) {
            return (int)((n %= mod) < 0 ? n + mod : n);
        }


        /**
         * n+mをmodで割った余りを返します。
         * @param n 足される値
         * @param m 足す値
         * @return n+mをmodで割った余り
         */
        public int add(int n, int m) {
            return mod(n + m);
        }

        /**
         * n-mをmodで割った余りを返します。
         * @param n 引かれる値
         * @param m 引く値
         * @return n-mをmodで割った余り
         */
        public int subtract(int n, int m) {
            return mod(n - m);
        }

        /**
         * n*mをmodで割った余りを返します。
         * @param n 掛けられる値
         * @param m 掛ける値
         * @return n*mをmodで割った余り
         */
        public int multiply(int n, int m) {
            int ans = (int)((long)n * m % mod);
            return ans < 0 ? ans + mod : ans;
        }

        /**
         * n/mをmodで割った余りを返します。
         * @param n 割られる値
         * @param m 割る値
         * @return n/mをmodで割った余り
         */
        public int divide(int n, int m) {
            return multiply(n, inverse(m));
        }

        /**
         * fを通ることが分かっているfの要素数-1次の関数について、xの位置における値をmodで割った余りを返します。<br>
         * 計算量はO(f)です。
         * @param f 関数の形
         * @param x 求める位置
         * @return 求めたい値をmodで割った余り
         */
        public ModInteger lagrangePolynomial(ModInteger[] f, int x) {
            if (f.length > x) return f[x];
            if (x > fact.length) precalc(x);
            ModInteger ret = create(0);
            ModInteger[] dp = new ModInteger[f.length], dp2 = new ModInteger[f.length];
            dp[0] = create(1);
            dp2[f.length - 1] = create(1);
            for (int i = 1;i < f.length;++ i) {
                dp[i] = dp[i - 1].multiply(x - i - 1);
                dp2[f.length - i - 1] = dp2[f.length - i].multiply(x - f.length + i);
            }
            for (int i = 0;i < f.length;++ i) {
                ModInteger tmp = f[i].multiply(dp[i]).multiplyEqual(dp2[i]).multiplyEqual(inv[i]).multiplyEqual(inv[f.length - 1 - i]);
                if ((f.length - i & 1) == 0) ret.addEqual(tmp);
                else ret.subtractEqual(tmp);
            }
            return ret;
        }
    }

}
