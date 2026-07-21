import java.awt.Point;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.Serializable;
import java.util.AbstractList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Locale;
import java.util.NoSuchElementException;
import java.util.RandomAccess;
import java.util.function.BinaryOperator;
import java.util.function.UnaryOperator;

public class Main implements Runnable{

	private void solve(FastIO io) {
		/*
		 * author: 31536000
		 * ABC140 B問題
		 * 考察メモ
		 *
		 */
		int N = io.nextInt();
		int[] A = io.nextInt(N), B = io.nextInt(N), C = io.nextInt(N - 1);
		int ans = B[0];
		for (int i = 1;i < N;++ i) {
			ans += B[i];
			if (A[i - 1] + 1 == A[i]) ans += C[A[i - 1] - 1];
		}
		io.println(ans);
	}

	/** デバッグ用コードのお供に */
	private static boolean DEBUG = false;
	/** 確保するメモリの大きさ(単位: MB)*/
	private static final long MEMORY = 64;
	private final FastIO io;

	public static void main(String[] args) {
	        Thread.setDefaultUncaughtExceptionHandler((t, e) -> e.printStackTrace());
	        new Thread(null, new Main(), "", MEMORY * 1048576).start();
	}

	public Main() {
		io = new FastIO();
		assert (DEBUG = true) | true; // yukicoderだと-eaが付いてるので正しく動かないことに注意
		if (DEBUG) {
			io.setAutoFlush(true);
			io.println("debug mode");
		}
	}

	@Override
	public void run() {
		solve(io);
		io.flush();
	}

	// 以下、ライブラリ

	public static class FastIO {
		private final InputStream in;
		private final byte[] buffer = new byte[1024];
		private int read = 0;
		private int length = 0;
		public final PrintWriter out;
		public final PrintWriter err;
		private boolean autoFlush = false;

		public FastIO() {
			this(System.in, System.out, System.err);
		}

		public FastIO(InputStream in, PrintStream out, PrintStream err) {
			this.in = in;
			this.out = new PrintWriter(out, false);
			this.err = new PrintWriter(err, false);
		}

		public void setAutoFlush(boolean flush) {
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

		public boolean hasNext() {
			while (hasNextByte() && !isPrintableChar(buffer[read])) read++;
			return hasNextByte();
		}

		public char nextChar() {
			if (!hasNextByte())  throw new NoSuchElementException();
			return (char)readByte();
		}

		public char[][] nextChar(int height) {
			char[][] ret = new char[height][];
			for (int i = 0;i < ret.length;++ i) ret[i] = next().toCharArray();
			return ret;
		}

		public String next() {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b;
			while (isPrintableChar(b = readByte())) sb.appendCodePoint(b);
			return sb.toString();
		}

		public String nextLine() {
			StringBuilder sb = new StringBuilder();
			int b;
			while(!isPrintableChar(b = readByte()));
			do sb.appendCodePoint(b); while(isPrintableChar(b = readByte()) || b == ' ');
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

		public int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
			return (int) nl;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextInt(int width) {
			int[] ret = new int[width];
			for (int i = 0;i < width;++ i) ret[i] = nextInt();
			return ret;
		}

		public int[] nextInts() {
			return nextInts(" ");
		}

		public int[] nextInts(String parse) {
			String[] get = nextLine().split(parse);
			int[] ret = new int[get.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = Integer.valueOf(ret[i]);
			return ret;
		}

		public long[] nextLong(int width) {
			long[] ret = new long[width];
			for (int i = 0;i < width;++ i) ret[i] = nextLong();
			return ret;
		}

		public long[] nextLongs() {
			return nextLongs(" ");
		}

		public long[] nextLongs(String parse) {
			String[] get = nextLine().split(parse);
			long[] ret = new long[get.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = Long.valueOf(ret[i]);
			return ret;
		}

		public int[][] nextInt(int width, int height) {
			int[][] ret = new int[height][width];
			for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[i][j] = nextInt();
			return ret;
		}

		public long[][] nextLong(int width, int height) {
			long[][] ret = new long[height][width];
			for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[j][i] = nextLong();
			return ret;
		}

		public boolean[] nextBoolean(char T) {
			char[] s = next().toCharArray();
			boolean[] ret = new boolean[s.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = s[i] == T;
			return ret;
		}

		public boolean[][] nextBoolean(char T, int height) {
			boolean[][] ret = new boolean[height][];
			for (int i = 0;i < ret.length;++ i) {
				char[] s = next().toCharArray();
				ret[i] = new boolean[s.length];
				for (int j = 0;j < ret[i].length;++ j) ret[i][j] = s[j] == T;
			}
			return ret;
		}

		public Point nextPoint() {
			return new Point(nextInt(), nextInt());
		}

		public Point[] nextPoint(int width) {
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

		public boolean print(boolean b) {
			out.print(b);
			if (autoFlush) flush();
			return b;
		}

		public Object print(boolean b, Object t, Object f) {
			return b ? print(t) : print(f);
		}

		public char print(char c) {
			out.print(c);
			if (autoFlush) flush();
			return c;
		}

		public char[] print(char[] s) {
			out.print(s);
			return s;
		}

		public double print(double d) {
			out.print(d);
			if (autoFlush) flush();
			return d;
		}

		public double print(double d, int length) {
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

		public float print(float f) {
			out.print(f);
			if (autoFlush) flush();
			return f;
		}

		public int print(int i) {
			out.print(i);
			if (autoFlush) flush();
			return i;
		}

		public long print(long l) {
			out.print(l);
			if (autoFlush) flush();
			return l;
		}

		public Object print(Object obj) {
			if (obj.getClass().isArray()) {
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

		public String print(String s) {
			out.print(s);
			if (autoFlush) flush();
			return s;
		}

		public Object print(Object array, String... parse) {
			print(array, 0, parse);
			if (autoFlush) flush();
			return array;
		}

		private Object print(Object array, int check, String... parse) {
			if (check >= parse.length) {
				if (array.getClass().isArray()) throw new IllegalArgumentException("not equal dimension");
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

		public Object[] print(String parse, Object... args) {
			print(args[0]);
			for (int i = 1;i < args.length;++ i) {
				print(parse);
				print(args[i]);
			}
			return args;
		}

		public Object[] printf(String format, Object... args) {
			out.printf(format, args);
			if (autoFlush) flush();
			return args;
		}

		public Object printf(Locale l, String format, Object... args) {
			out.printf(l, format, args);
			if (autoFlush) flush();
			return args;
		}

		public void println() {
			out.println();
			if (autoFlush) flush();
		}

		public boolean println(boolean b) {
			out.println(b);
			if (autoFlush) flush();
			return b;
		}

		public Object println(boolean b, Object t, Object f) {
			return b ? println(t) : println(f);
		}

		public char println(char c) {
			out.println(c);
			if (autoFlush) flush();
			return c;
		}

		public char[] println(char[] s) {
			out.println(s);
			if (autoFlush) flush();
			return s;
		}

		public double println(double d) {
			out.println(d);
			if (autoFlush) flush();
			return d;
		}

		public double println(double d, int length) {
			print(d, length);
			println();
			return d;
		}

		public float println(float f) {
			out.println(f);
			if (autoFlush) flush();
			return f;
		}

		public int println(int i) {
			out.println(i);
			if (autoFlush) flush();
			return i;
		}

		public long println(long l) {
			out.println(l);
			if (autoFlush) flush();
			return l;
		}

		public Object println(Object obj) {
			print(obj);
			println();
			return obj;
		}

		public String println(String s) {
			out.println(s);
			if (autoFlush) flush();
			return s;
		}

		public Object println(Object array, String... parse) {
			print(array, parse);
			println();
			return array;
		}

		public void flush() {
			out.flush();
			err.flush();
		}
	}

	public enum BoundType {
		CLOSED, OPEN;
	}

	public static class Range<C> implements Serializable{

		private static final long serialVersionUID = -4702828934863023392L;
		protected C lower;
		protected C upper;
		protected BoundType lowerType;
		protected BoundType upperType;
		private Comparator<? super C> comparator;

		protected Range(C lower, BoundType lowerType, C upper, BoundType upperType) {
			this(lower, lowerType, upper, upperType, null);
		}

		protected Range(C lower, BoundType lowerType, C upper, BoundType upperType, Comparator<? super C> comparator) {
			this.lower = lower;
			this.upper = upper;
			this.lowerType = lowerType;
			this.upperType = upperType;
			this.comparator = comparator;
		}

		public static <C extends Comparable<? super C>> Range<C> range(C lower, BoundType lowerType, C upper, BoundType upperType) {
			if (lower != null && upper != null) {
				int comp = lower.compareTo(upper);
				if (comp > 0) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED);
				else if (comp == 0 && (lowerType == BoundType.OPEN || upperType == BoundType.OPEN))return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED);
			}
			return new Range<C>(lower, lowerType, upper, upperType);
		}

		public static <C> Range<C> range(C lower, BoundType lowerType, C upper, BoundType upperType, Comparator<? super C> comparator) {
			if (lower != null && upper != null) {
				int comp = comparator.compare(lower, upper);
				if (comp > 0) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, comparator);
				else if (comp == 0 && (lowerType == BoundType.OPEN || upperType == BoundType.OPEN)) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, comparator);
			}
			return new Range<C>(lower, lowerType, upper, upperType, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> all() {
			return range((C)null, BoundType.OPEN, null, BoundType.OPEN);
		}

		public static <C> Range<C> all(Comparator<? super C> comparator) {
			return range((C)null, BoundType.OPEN, null, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> atMost(C upper) {
			return range(null, BoundType.OPEN, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> atMost(C upper, Comparator<? super C> comparator) {
			return range(null, BoundType.OPEN, upper, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> lessThan(C upper) {
			return range(null, BoundType.OPEN, upper, BoundType.OPEN);
		}

		public static <C> Range<C> lessThan(C upper, Comparator<? super C> comparator) {
			return range(null, BoundType.OPEN, upper, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> downTo(C upper, BoundType boundType) {
			return range(null, BoundType.OPEN, upper, boundType);
		}

		public static <C> Range<C> downTo(C upper, BoundType boundType, Comparator<? super C> comparator) {
			return range(null, BoundType.OPEN, upper, boundType, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> atLeast(C lower) {
			return range(lower, BoundType.CLOSED, null, BoundType.OPEN);
		}

		public static <C> Range<C> atLeast(C lower, Comparator<? super C> comparator) {
			return range(lower, BoundType.CLOSED, null, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> greaterThan(C lower) {
			return range(lower, BoundType.OPEN, null, BoundType.OPEN);
		}

		public static <C> Range<C> greaterThan(C lower, Comparator<? super C> comparator) {
			return range(lower, BoundType.OPEN, null, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> upTo(C lower, BoundType boundType) {
			return range(lower, boundType, null, BoundType.OPEN);
		}

		public static <C> Range<C> upTo(C lower, BoundType boundType, Comparator<? super C> comparator) {
			return range(lower, boundType, null, BoundType.OPEN, comparator  );
		}

		public static <C extends Comparable<? super C>> Range<C> open(C lower, C upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN);
		}

		public static <C> Range<C> open(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> openClosed(C lower, C upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> openClosed(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> closedOpen(C lower, C upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN);
		}

		public static <C> Range<C> closedOpen(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> closed(C lower, C upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> closed(C lower, C upper, Comparator<? super C> comparator) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> singleton(C value) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED);
		}

		public static <C> Range<C> singleton(C value, Comparator<? super C> comparator) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> empty() {
			return range((C)null, BoundType.CLOSED, null, BoundType.CLOSED);
		}

		public static <C> Range<C> empty(Comparator<? super C> comparator) {
			return range((C)null, BoundType.CLOSED, null, BoundType.CLOSED, comparator);
		}

		public static <C extends Comparable<? super C>> Range<C> encloseAll(Iterable<C> values) {
			C lower = values.iterator().next();
			C upper = lower;
			for (C i : values) {
				if (lower.compareTo(i) > 0) lower = i;
				if (upper.compareTo(i) < 0) upper = i;
			}
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static <C> Range<C> encloseAll(Iterable<C> values, Comparator<? super C> comparator) {
			C lower = values.iterator().next();
			C upper = lower;
			for (C i : values) {
				if (comparator.compare(lower, i) > 0) lower = i;
				if (comparator.compare(upper, i) < 0) upper = i;
			}
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, comparator);
		}

		protected int compareLower(C value) {
			return compareLower(value, BoundType.CLOSED);
		}

		protected int compareLower(C value, BoundType boundType) {
			return compareLower(lower, lowerType, value, boundType);
		}

		protected int compareLower(C lower, BoundType lowerType, C value) {
			return compareLower(lower, lowerType, value, BoundType.CLOSED);
		}

		protected int compareLower(C lower, BoundType lowerType, C value, BoundType boundType) {
			if (lower == null) return value == null ? 0 : -1;
			else if (value == null) return 1;
			int compare;
			if (comparator == null) {
				@SuppressWarnings("unchecked")
				Comparable<C> comp = (Comparable<C>)lower;
				compare = comp.compareTo(value);
			} else compare = comparator.compare(lower, value);
			if (compare == 0) {
				if (lowerType == BoundType.CLOSED) -- compare;
				if (boundType == BoundType.CLOSED) ++ compare;
			}
			return compare;
		}

		protected int compareUpper(C value) {
			return compareUpper(value, BoundType.CLOSED);
		}

		protected int compareUpper(C value, BoundType boundType) {
			return compareUpper(upper, upperType, value, boundType);
		}

		protected int compareUpper(C upper, BoundType upperType, C value) {
			return compareUpper(upper, upperType, value, BoundType.CLOSED);
		}

		protected int compareUpper(C upper, BoundType upperType, C value, BoundType boundType) {
			if (upper == null) return value == null ? 0 : 1;
			if (value == null) return -1;
			int compare;
			if (comparator == null) {
				@SuppressWarnings("unchecked")
				Comparable<C> comp = (Comparable<C>)upper;
				compare = comp.compareTo(value);
			} else compare = comparator.compare(upper, value);
			if (compare == 0) {
				if (upperType == BoundType.CLOSED) ++ compare;
				if (boundType == BoundType.CLOSED) -- compare;
			}
			return compare;
		}

		public boolean hasLowerBound() {
			return lower != null;
		}

		public C lowerEndpoint() {
			if (hasLowerBound()) return lower;
			throw new IllegalStateException();
		}

		public BoundType lowerBoundType() {
			if (hasLowerBound()) return lowerType;
			throw new IllegalStateException();
		}

		public boolean hasUpperBound() {
			return upper != null;
		}

		public C upperEndpoint() {
			if (hasUpperBound()) return upper;
			throw new IllegalStateException();
		}

		public BoundType upperBoundType() {
			if (hasUpperBound()) return upperType;
			throw new IllegalStateException();
		}

		/**
		 * この区間が空集合か判定します。
		 * @return 空集合ならばtrue
		 */
		public boolean isEmpty() {
			return lower == null && upper == null && lowerType == BoundType.CLOSED;
		}

		/**
		 * 与えられた引数が区間の左側に位置するか判定します。<br>
		 * 接する場合は区間の左側ではないと判定します。
		 * @param value 調べる引数
		 * @return 区間の左側に位置するならtrue
		 */
		public boolean isLess(C value) {
			return isLess(value, BoundType.CLOSED);
		}

		protected boolean isLess(C value, BoundType boundType) {
			return compareLower(value, boundType) > 0;
		}

		/**
		 * 与えられた引数が区間の右側に位置するか判定します。<br>
		 * 接する場合は区間の右側ではないと判定します。
		 * @param value 調べる引数
		 * @return 区間の右側に位置するならtrue
		 */
		public boolean isGreater(C value) {
			return isGreater(value, BoundType.CLOSED);
		}

		private boolean isGreater(C value, BoundType boundType) {
			return compareUpper(value, boundType) < 0;
		}

		/**
		 * 与えられた引数が区間内に位置するか判定します。<br>
		 * 接する場合も区間内に位置すると判定します。
		 * @param value 調べる引数
		 * @return 区間内に位置するならtrue
		 */
		public boolean contains(C value) {
			return !isLess(value) && !isGreater(value) && !isEmpty();
		}

		/**
		 * 与えられた引数すべてが区間内に位置するか判定します。<br>
		 * 接する場合も区間内に位置すると判定します。
		 * @param value 調べる要素
		 * @return 全ての要素が区間内に位置するならtrue
		 */
		public boolean containsAll(Iterable<? extends C> values) {
			for (C i : values) if (!contains(i)) return false;
			return true;
		}

		/**
		 * 与えられた区間がこの区間に内包されるか判定します。<br>
		 *
		 * @param other
		 * @return 与えられた区間がこの区間に内包されるならtrue
		 */
		public boolean encloses(Range<C> other) {
			return !isLess(other.lower, other.lowerType) && !isGreater(other.upper, other.upperType);
		}

		/**
		 * 与えられた区間がこの区間と公差するか判定します。<br>
		 * 接する場合は公差するものとします。
		 * @param value 調べる引数
		 * @return 区間が交差するならtrue
		 */
		public boolean isConnected(Range<C> other) {
			if (this.isEmpty() || other.isEmpty()) return false;
			C lower, upper;
			BoundType lowerType, upperType;
			if (isLess(other.lower, other.lowerType)) {
				lower = other.lower;
				lowerType = other.lowerType;
			} else {
				lower = this.lower;
				lowerType = this.lowerType;
			}
			if (isGreater(other.upper, other.upperType)) {
				upper = other.upper;
				upperType = other.upperType;
			} else {
				upper = this.upper;
				upperType = this.upperType;
			}
			if (lower == null || upper == null) return true;
			int comp = compareLower(lower, lowerType, upper, upperType);
			return comp <= 0;
		}
		/**
		 * この区間との積集合を返します。
		 * @param connectedRange 積集合を求める区間
		 * @return 積集合
		 */
		public Range<C> intersection(Range<C> connectedRange) {
			if (this.isEmpty() || connectedRange.isEmpty()) {
				if (comparator == null) return new Range<C>(null, BoundType.CLOSED, null, BoundType.CLOSED);
				return empty(comparator);
			}
			C lower, upper;
			BoundType lowerType, upperType;
			if (isLess(connectedRange.lower, connectedRange.lowerType)) {
				lower = connectedRange.lower;
				lowerType = connectedRange.lowerType;
			} else {
				lower = this.lower;
				lowerType = this.lowerType;
			}
			if (isGreater(connectedRange.upper, connectedRange.upperType)) {
				upper = connectedRange.upper;
				upperType = connectedRange.upperType;
			} else {
				upper = this.upper;
				upperType = this.upperType;
			}
			if (comparator == null) {
				return new Range<C>(lower, lowerType, upper, upperType);
			}
			return range(lower, lowerType, upper, upperType, comparator);
		}

		/**
		 * この区間との和集合を返します。
		 * @param other 和集合を求める区間
		 * @return 和集合
		 */
		public Range<C> span(Range<C> other) {
			if (other.isEmpty()) return new Range<C>(lower, lowerType, upper, upperType);
			C lower, upper;
			BoundType lowerType, upperType;
			if (isLess(other.lower, other.lowerType)) {
				lower = this.lower;
				lowerType = this.lowerType;
			} else {
				lower = other.lower;
				lowerType = other.lowerType;
			}
			if (isGreater(other.upper, other.upperType)) {
				upper = this.upper;
				upperType = this.upperType;
			} else {
				upper = other.upper;
				upperType = other.upperType;
			}
			return new Range<C>(lower, lowerType, upper, upperType, comparator);
		}

		@Override
		public boolean equals(Object object) {
			if (this == object) return true;
			if (object instanceof Range) {
				@SuppressWarnings("unchecked")
				Range<C> comp = (Range<C>) object;
				return compareLower(comp.lower, comp.lowerType) == 0 && compareUpper(comp.upper, comp.upperType) == 0 && lowerType == comp.lowerType && upperType == comp.upperType;
			}
			return false;
		}

		@Override
		public int hashCode() {
			if (lower == null && upper == null) return 0;
			else if (lower == null) return upper.hashCode();
			else if (upper == null) return lower.hashCode();
			return lower.hashCode() ^ upper.hashCode();
		}

		@Override
		public String toString() {
			if (isEmpty()) return "()";
			return (lowerType == BoundType.OPEN ? "(" : "[") + (lower == null ? "" : lower.toString()) + ".." + (upper == null ? "" : upper.toString()) + (upperType == BoundType.OPEN ? ")" : "]");
		}
	}

	public static class IterableRange<C> extends Range<C> implements Iterable<C>{

		private static final long serialVersionUID = 9065915259748260688L;
		protected UnaryOperator<C> func;

		protected IterableRange(C lower, BoundType lowerType, C upper, BoundType upperType, UnaryOperator<C> func) {
			super(lower, lowerType, upper, upperType);
			this.func = func;
		}

		public static <C extends Comparable<? super C>> IterableRange<C> range(C lower, BoundType lowerType, C upper, BoundType upperType, UnaryOperator<C> func) {
			if (lower == null || upper == null) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			int comp = lower.compareTo(upper);
			if (comp > 0) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			else if (comp == 0 && (lowerType == BoundType.OPEN || upperType == BoundType.OPEN)) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			return new IterableRange<C>(lower, lowerType, upper, upperType, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> open(C lower, C upper, UnaryOperator<C> func) {
			if (lower == null) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			return range(func.apply(lower), BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> openClosed(C lower, C upper, UnaryOperator<C> func) {
			if (lower == null) return new IterableRange<C>(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			return range(func.apply(lower), BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> closedOpen(C lower, C upper, UnaryOperator<C> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> closed(C lower, C upper, UnaryOperator<C> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static <C extends Comparable<? super C>> IterableRange<C> singleton(C value, UnaryOperator<C> func) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED, func);
		}

		protected class Iter implements Iterator<C> {
			C now;
			Iter() {
				now = lower;
			}
			@Override
			public final boolean hasNext() {
				return !isGreater(now);
			}

			@Override
			public final C next() {
				C ret = now;
				now = func.apply(now);
				return ret;
			}

			@Override
			public final void remove() {
				throw new UnsupportedOperationException();
			}
		}

		protected class EmptyIter implements Iterator<C> {

			@Override
			public boolean hasNext() {
				return false;
			}

			@Override
			public C next() {
				return null;
			}

			@Override
			public final void remove() {
				throw new UnsupportedOperationException();
			}

		}

		@Override
		public Iterator<C> iterator() {
			return lower == null || upper == null ? new EmptyIter() : new Iter();
		}

		public int getDistance() {
			C check = upper;
			int ret = 0;
			while (lower != check) {
				check = func.apply(check);
				++ ret;
			}
			return ret;
		}
	}

	public static class IntRange extends IterableRange<Integer>{

		private static final long serialVersionUID = 5623995336491967216L;
		private final boolean useFastIter;

		private static class Next implements UnaryOperator<Integer> {

			@Override
			public Integer apply(Integer value) {
				return value + 1;
			}
		}

		protected IntRange() {
			super(null, BoundType.CLOSED, null, BoundType.CLOSED, new Next());
			useFastIter = true;
		}

		protected IntRange(UnaryOperator<Integer> func) {
			super(null, BoundType.CLOSED, null, BoundType.CLOSED, func);
			useFastIter = false;
		}

		protected IntRange(int lower, BoundType lowerType, int upper, BoundType upperType) {
			super(lower, lowerType, upper, upperType, new Next());
			useFastIter = true;
		}

		protected IntRange(int lower, BoundType lowerType, int upper, BoundType upperType, UnaryOperator<Integer> func) {
			super(lower, lowerType, upper, upperType, func);
			useFastIter = false;
		}

		public static IntRange range(int lower, BoundType lowerType, int upper, BoundType upperType) {
			if (lower > upper) return new IntRange();
			if (lowerType == BoundType.OPEN) ++ lower;
			if (upperType == BoundType.OPEN) -- upper;
			return new IntRange(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static IntRange range(int lower, BoundType lowerType, int upper, BoundType upperType, UnaryOperator<Integer> func) {
			if (lower > upper) return new IntRange(func);
			if (lowerType == BoundType.OPEN) ++ lower;
			if (upperType == BoundType.OPEN) -- upper;
			return new IntRange(lower, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static IntRange open(int lower, int upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN);
		}

		public static IntRange open(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.OPEN, upper, BoundType.OPEN, func);
		}

		public static IntRange open(int upper) {
			return range(0, BoundType.CLOSED, upper, BoundType.OPEN);
		}

		public static IntRange open(int upper, UnaryOperator<Integer> func) {
			return range(0, BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static IntRange openClosed(int lower, int upper) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED);
		}

		public static IntRange openClosed(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.OPEN, upper, BoundType.CLOSED, func);
		}

		public static IntRange closedOpen(int lower, int upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN);
		}

		public static IntRange closedOpen(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.OPEN, func);
		}

		public static IntRange closed(int lower, int upper) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static IntRange closed(int lower, int upper, UnaryOperator<Integer> func) {
			return range(lower, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static IntRange closed(int upper) {
			return range(0, BoundType.CLOSED, upper, BoundType.CLOSED);
		}

		public static IntRange closed(int upper, UnaryOperator<Integer> func) {
			return range(0, BoundType.CLOSED, upper, BoundType.CLOSED, func);
		}

		public static IntRange singleton(int value) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED);
		}

		public static IntRange singleton(int value, UnaryOperator<Integer> func) {
			return range(value, BoundType.CLOSED, value, BoundType.CLOSED, func);
		}

		private class FastIter implements Iterator<Integer> {
			int now;
			public FastIter() {
				now = lower;
			}
			@Override
			public final boolean hasNext() {
				return now <= upper;
			}

			@Override
			public final Integer next() {
				return now++;
			}

			@Override
			public final void remove() {
				throw new UnsupportedOperationException();
			}
		}

		private class Iter implements Iterator<Integer> {
			int now;
			public Iter() {
				now = lower;
			}
			@Override
			public final boolean hasNext() {
				return now <= upper;
			}

			@Override
			public final Integer next() {
				int ret = now;
				now = func.apply(now);
				return ret;
			}

			@Override
			public final void remove() {
				throw new UnsupportedOperationException();
			}
		}

		@Override
		public Iterator<Integer> iterator() {
			return lower == null || upper == null ? new EmptyIter() : useFastIter ? new FastIter() : new Iter();
		}

		@Override
		public int getDistance() {
			int ret = upper - lower;
			if (upperType == BoundType.CLOSED) ++ ret;
			return ret;
		}

		public int getClosedLower() {
			return lower;
		}

		public int getOpenLower() {
			return lower - 1;
		}

		public int getClosedUpper() {
			return upperType == BoundType.CLOSED ? upper : upper - 1;
		}

		public int getOpenUpper() {
			return upperType == BoundType.CLOSED ? upper + 1 : upper;
		}
	}

	/**
	 * 演算が結合法則を満たすことを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface Associative<T> extends BinaryOperator<T>{
		/**
		 * repeat個のelementを順次演算した値を返します。
		 * @param element 演算する値
		 * @param repeat 繰り返す回数、1以上であること
		 * @return 演算を+として、element + element + ... + elementと演算をrepeat-1回行った値
		 */
		public default T hyper(T element, int repeat) {
			if (repeat < 1) throw new IllegalArgumentException("undefined operation");
			T ret = element;
			-- repeat;
			for (T mul = element;repeat > 0;repeat >>= 1, mul = apply(mul, mul)) if ((repeat & 1) != 0) ret = apply(ret, mul);
			return ret;
		}
	}

	/**
	* この演算が逆元を持つことを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface Inverse<T> extends BinaryOperator<T>{
		public T inverse(T element);
	}

	/**
	 * 演算が交換法則を満たすことを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface Commutative<T> extends BinaryOperator<T>{

	}

	/**
	 * 演算が単位元を持つことを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface Unit<T> extends BinaryOperator<T>{
		/**
		 * 単位元を返します。
		 * @return 単位元
		 */
		public T unit();
	}

	/**
	 * 演算が群であることを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface Group<T> extends Monoid<T>, Inverse<T>{
		/**
		 * repeat個のelementを順次演算した値を返します。
		 * @param element 演算する値
		 * @param repeat 繰り返す回数
		 * @return 演算を+として、element + element + ... + elementと演算をrepeat-1回行った値
		 */
		@Override
		public default T hyper(T element, int repeat) {
			T ret = unit();
			if (repeat < 0) {
				repeat = -repeat;
				for (T mul = element;repeat > 0;repeat >>= 1, mul = apply(mul, mul)) if ((repeat & 1) != 0) ret = apply(ret, mul);
				return inverse(ret);
			}
			for (T mul = element;repeat > 0;repeat >>= 1, mul = apply(mul, mul)) if ((repeat & 1) != 0) ret = apply(ret, mul);
			return ret;
		}
	}

	/**
	 * 演算がモノイドであることを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface Monoid<T> extends Associative<T>, Unit<T> {
		/**
		 * repeat個のelementを順次演算した値を返します。
		 * @param element 演算する値
		 * @param repeat 繰り返す回数、0以上であること
		 * @return 演算を+として、element + element + ... + elementと演算をrepeat-1回行った値
		 */
		@Override
		public default T hyper(T element, int repeat) {
			if (repeat < 0) throw new IllegalArgumentException("undefined operation");
			T ret = unit();
			for (T mul = element;repeat > 0;repeat >>= 1, mul = apply(mul, mul)) if ((repeat & 1) != 0) ret = apply(ret, mul);
			return ret;
		}
	}

	/**
	 * 演算が可換モノイドであることを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface CommutativeMonoid<T> extends Monoid<T>, Commutative<T> {

	}

	/**
	 * 演算がアーベル群(可換群)であることを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 */
	public interface Abelian<T> extends Group<T>, CommutativeMonoid<T> {

	}

	/**
	 * 演算が半環であることを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 * @param <A> 和に関する演算
	 * @param <M> 積に関する演算
	 */
	public interface Semiring<T, A extends CommutativeMonoid<T>, M extends Monoid<T>> {
		public A getAddition();
		public M getMultiplication();
	}

	/**
	 * 演算が環であることを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 * @param <A> 和に関する演算
	 * @param <M> 積に関する演算
	 */
	public interface Ring<T, A extends Abelian<T>, M extends Monoid<T>> extends Semiring<T, A, M>{

	}

	/**
	 * 演算が可換環に属することを示すために使用するマーカー・インターフェースです。
	 * @author 31536000
	 *
	 * @param <T> 二項演算の型
	 * @param <A> 和に関する演算
	 * @param <M> 積に関する演算
	 */
	public interface CommutativeRing<T, A extends Abelian<T>, M extends CommutativeMonoid<T>> extends Ring<T, A, M>{

	}

	public static class ModInteger extends Number implements CommutativeRing<ModInteger, Abelian<ModInteger>, CommutativeMonoid<ModInteger>>{

		private static final long serialVersionUID = -8595710127161317579L;
		private final int mod;
		private int num;

		private final Addition add;
		private final Multiplication mul;

		private class Addition implements Abelian<ModInteger> {

			@Override
			public ModInteger unit() {
				return new ModInteger(mod, 0);
			}

			@Override
			public ModInteger inverse(ModInteger element) {
				return new ModInteger(element, element.mod - element.num);
			}

			@Override
			public ModInteger apply(ModInteger left, ModInteger right) {
				return new ModInteger(left).addEqual(right);
			}
		}

		private class Multiplication implements Abelian<ModInteger> {

			@Override
			public ModInteger unit() {
				return new ModInteger(mod, 1);
			}

			@Override
			public ModInteger apply(ModInteger left, ModInteger right) {
				return new ModInteger(left).multiplyEqual(right);
			}

			@Override
			public ModInteger inverse(ModInteger element) {
				return new ModInteger(element, element.inverse(element.num));
			}

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

		public ModInteger add(int n) {
			return new ModInteger(this).addEqual(n);
		}

		public ModInteger add(long n) {
			return new ModInteger(this).addEqual(n);
		}

		public ModInteger add(ModInteger n) {
			return new ModInteger(this).addEqual(n);
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
			return new ModInteger(this).subtractEqual(n);
		}

		public ModInteger subtract(long n) {
			return new ModInteger(this).subtractEqual(n);
		}

		public ModInteger subtract(ModInteger n) {
			return new ModInteger(this).subtractEqual(n);
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
			return new ModInteger(this).multiplyEqual(n);
		}

		public ModInteger multiply(long n) {
			return new ModInteger(this).multiplyEqual(n);
		}

		public ModInteger multiply(ModInteger n) {
			return new ModInteger(this).multiplyEqual(n);
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
			return new ModInteger(this).divideEqual(n);
		}

		public ModInteger divide(long n) {
			return new ModInteger(this).divideEqual(n);
		}

		public ModInteger divide(ModInteger n) {
			return new ModInteger(this).divideEqual(n);
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
			return new ModInteger(this).powEqual(n);
		}

		public ModInteger pow(long n) {
			return new ModInteger(this).powEqual(n);
		}

		public ModInteger pow(ModInteger n) {
			return new ModInteger(this).powEqual(n);
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

		@Override
		public Addition getAddition() {
			return add;
		}

		@Override
		public Multiplication getMultiplication() {
			return mul;
		}
	}

	/**
	 * 素数を法とする演算上で、組み合わせの計算を高速に行います。
	 * @author 31536000
	 *
	 */
	public static class ModUtility {
		private final int mod, totient;
		private int[] fact, inv, invfact;
		/**
		 * modを法とする
		 * @param mod
		 */
		public ModUtility(int mod) {
			this(mod, 2);
		}

		public ModUtility(int mod, int calc) {
			if (mod <= 0) throw new IllegalArgumentException("illegal mod: " + mod);
			this.mod = mod;
			int totient = mod;
			for (int i = 2;i * i <= mod;++ i) {
				if (mod % i == 0) {
					totient = totient / i * (i - 1);
					while ((mod %= i) % i == 0);
				}
			}
			this.totient = totient;
			precalc(calc);
		}

		public void precalc(int calc) {
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

		public ModInteger create() {
			return create(0);
		}

		public ModInteger create(int n) {
			return new ModInt(n);
		}

		private class ModInt extends ModInteger {

			private static final long serialVersionUID = -2435281861935422575L;

			public ModInt(int n) {
				super(mod, n);
			}

			@Override
			protected int inverse(int n) {
				return ModUtility.this.inverse(n);
			}
		}

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

		public int permutation(int n, int k) {
			if (k < 0) throw new IllegalArgumentException();
			if (n < k) return 0;
			if (fact.length > n) return (int)((long)fact[n] * invfact[n - k] % mod);
			long ret = 1;
			for (int i = n - k + 1;i <= n;++ i) ret = ret * i % mod;
			return (int)ret;
		}

		public int combination(int n, int k) {
			if (k < 0) throw new IllegalArgumentException();
			if (n < k) return 0;
			if (fact.length > n) return (int)((long)fact[n] * invfact[k] % mod * invfact[n - k] % mod);
			long ret = 1;
			if (n < 2 * k) k = n - k;
			if (invfact.length > k) ret = invfact[k];
			else ret = inverse(factorial(k));
			for (int i = n - k + 1;i <= n;++ i) ret = ret * i % mod;
			return (int)ret;
		}

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

		public int multichoose(int n, int k) {
			return combination(mod(n + k - 1), k);
		}

		public int catalan(int n) {
			return divide(combination(mod(2 * n), n), mod(n + 1));
		}

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

		public int pow(long n, long m) {
			return pow((int)(n % mod), (int)(m % (mod - 1)));
		}

		public int totient() {
			return totient;
		}

		public boolean isPrime() {
			return totient == mod - 1;
		}

		public int mod(int n) {
			return (n %= mod) < 0 ? n + mod : n;
		}

		public int mod(long n) {
			return (int)((n %= mod) < 0 ? n + mod : n);
		}

		public int add(int n, int m) {
			return mod(n + m);
		}

		public int add(long n, long m) {
			return mod(n + m);
		}

		public int subtract(int n, int m) {
			return mod(n - m);
		}

		public int subtract(long n, long m) {
			return mod(n - m);
		}

		public int multiply(int n, int m) {
			int ans = (int)((long)n * m % mod);
			return ans < 0 ? ans + mod : ans;
		}

		public int multiply(long n, long m) {
			return multiply(mod(n), mod(m));
		}

		public int divide(int n, int m) {
			return multiply(n, inverse(mod(m)));
		}

		public int divide(long n, long m) {
			return multiply(n, inverse(mod(m)));
		}

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

	public static class AbstractArray<T> extends AbstractList<T> implements RandomAccess{

		private final Object[] array;

		public AbstractArray(int size) {
			array = new Object[size];
		}

		public AbstractArray(T[] array) {
			this(array.length);
			System.arraycopy(array, 0, this.array, 0, array.length);
		}

		@Override
		public T set(int index, T element) {
			T ret = get(index);
			array[index] = element;
			return ret;
		}

		@Override
		public T get(int index) {
			@SuppressWarnings("unchecked")
			T ret = (T)array[index];
			return ret;
		}

		public Object[] get() {
			return array;
		}

		public T[] get(T[] array) {
			if (array.length < this.array.length) {
				@SuppressWarnings("unchecked")
				T[] ret  = (T[])Arrays.copyOfRange(this.array, 0, this.array.length, array.getClass());
				return ret;
			}
			System.arraycopy(this.array, 0, array, 0, this.array.length);
			return array;
		}

		@Override
		public int size() {
			return array.length;
		}

		public int length() {
			return size();
		}

		@Override
		public int hashCode() {
			return Arrays.hashCode(array);
		}

		private class Iter implements Iterator<T> {
			private int index;

			private Iter() {
				index = 0;
			}

			@Override
			public boolean hasNext() {
				return index < array.length;
			}

			@Override
			public T next() {
				return get(index++);
			}

			@Override
			public void remove() {
				throw new UnsupportedOperationException();
			}
		}

		@Override
		public Iterator<T> iterator() {
			return new Iter();
		}
	}

	public static class Array<T> extends AbstractArray<T> implements Serializable{

		private static final long serialVersionUID = 2749604433067098063L;

		public Array(int size) {
			super(size);
		}

		public Array(T[] array) {
			super(array);
		}

		public T front() {
			return get(0);
		}

		public T back() {
			return get(size() - 1);
		}
	}
}
