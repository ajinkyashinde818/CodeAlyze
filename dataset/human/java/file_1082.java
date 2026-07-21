import java.awt.Point;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.Locale;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledFuture;
import java.util.concurrent.TimeUnit;
import java.util.function.IntPredicate;

public class Main implements Runnable{

	private static final int LIMIT = 1800; // ループで回せる時間
	private static final int ESTIMATE_LOOP = 8192; // 1msで回ると予想する回数

	private static class Marathon implements MarathonInterface {
		private FastIO io;
		private FastRandom rnd;
		private long loop;
		private long score;

		private final int N;
		private final int[] A;
		private final int[] B;
		private final int[] swapB;
		private int[] ans;
		private Stop stop;
		private WantArray want;

		public Marathon(FastIO io) {
			this.io = io;
			rnd = new FastRandom();

			N = io.nextInt();
			A = io.nextInt(N);
			B = io.nextInt(N);
			swapB = new int[N];
		}
		/*
		 * author: 31536000
		 *
		 * 考察メモ
		 * ABC178Fを焼きなます！
		 */


		@Override
		public void init(Stop stop) {
			loop = 0;
			for (int i = 0;i < log.length;++ i) log[i] = Math.log(rnd.nextDouble());
			this.stop = stop;
			// ここから初期化
			greedy();
		}

		// 初期構築はここで
		public void greedy() {
			for (int i = 0;i < N;++ i) swapB[i] = B[(i + N / 2) % N];
			for (int i = 0;i < N;++ i) if (A[i] != swapB[i]) ++ score;
			if (score == N) {
				ans = Arrays.copyOf(swapB, N);
				stop.stop();
				return;
			}
			if (N == 1) stop.stop(); // 後で例外吐くのでどうにかする
			want = new WantArray(N, i -> A[i] == swapB[i]);
			int[] count = new int[200001];
			for (int j : A) ++ count[j];
			for (int j : B) ++ count[j];
			for (int j : count) if (j > N) stop.stop(); // 不可能
		}

		@Override
		public void delayUpdate(int delay) {
			temperature = temperature(delay);
			loop += ESTIMATE_LOOP;
			// ここから処理、デバッグ出力なんかもここの方が良さげ
		}

		private void swap(int i, int j) {
			int swap = swapB[i];
			swapB[i] = swapB[j];
			swapB[j] = swap;
		}

		private static final double START_TEMP = 0.1; // TODO 焼きなまし関数
		private static final double END_TEMP = 0.00001;
		private static final double DIFF = START_TEMP - END_TEMP;
		private static final double INV_LIMIT = 1.0 / LIMIT;
		private double temperature = START_TEMP;
		private static final int LOG_SIZE = 1 << 12;
		private static final int LOG_MASK = LOG_SIZE - 1;
		final double[] log = new double[LOG_SIZE];

		private static double temperature(int delay) {
			return DIFF * delay * INV_LIMIT + END_TEMP;
		}


		private boolean isChange(int change) {
//			return change >= 0; // 山登り法
			return change >= temperature * log[rnd.nextInt() & LOG_MASK]; // 焼きなまし法
		}

		@Override
		public void update() {
			int x = rnd.nextInt(want.want());
			int y = rnd.nextInt(N - 1);
			if (y >= x) ++ y;
			int x2 = want.get(x), y2 = want.get(y);
			int diff = 0;
			if (A[x2] != swapB[x2]) -- diff;
			if (A[x2] != swapB[y2]) ++ diff;
			if (A[y2] != swapB[y2]) -- diff;
			if (A[y2] != swapB[x2]) ++ diff;
			if (isChange(diff)) {
				swap(x2,y2);
				want.set(x, y, i -> A[i] == swapB[i]);
				score += diff;
				if (score == N && ans == null) {
					ans = Arrays.copyOf(swapB, N);
					stop.stop();
				}
			}
		}

		@Override
		public void terminate() {
			if (ans != null) {
				io.println("Yes");
				io.println(ans);
			} else {
				io.println("No");
			}
			// ここまで処理
			io.debugln(loop + "," + score);
			io.flush();
		}

		public long getLoop() {
			return loop;
		}

		public long getScore() {
			return score;
		}

	}

	public static class WantArray {
		private final int[] index;
		private int k = 0;
		public WantArray(int n, IntPredicate want) {
			index = new int[n];
			for (int i = 0;i < n;++ i) index[i] = i;
			set(want);
		}

		private void swap(int i, int j) {
			int swap = index[i];
			index[i] = index[j];
			index[j] = swap;
		}

		public int get(int i) {
			return index[i];
		}

		public void set(IntPredicate want) {
			k = 0;
			for (int i = index.length - 1;i >= k;) {
				if (want.test(index[i])) {
					swap(i, k);
					++ k;
				} else {
					-- i;
				}
			}
		}

		public void set(int i, boolean want) {
			if (i < k) {
				if (want) return;
				swap(i, k - 1);
				-- k;
			} else {
				if (want) {
					swap(i, k);
					++ k;
				} else return;
			}
		}

		public void set(int i, int j, IntPredicate want) {
			if (i < k) {
				if (!want.test(index[i])) {
					swap(i, k - 1);
					if (j == k - 1) j = i;
					-- k;
				}
			} else {
				if (want.test(index[i])) {
					swap(i, k);
					if (j == k) j = i;
					++ k;
				}
			}
			set(j, want.test(index[j]));
		}

		public int want() {
			return k;
		}
	}

	/** デバッグ用コードのお供に */
	private static boolean DEBUG = false;
	/** 確保するメモリの大きさ(単位: MB)*/
	private static final long MEMORY = 256;
	private final FastIO io;

	public static void main(String[] args) {
	        Thread.setDefaultUncaughtExceptionHandler((t, e) -> e.printStackTrace());
	        new Thread(null, new Main(), "", MEMORY * 1048576).start();
	}

	public Main() {
		this(new FastIO());
	}

	public Main(FastIO io) {
		this.io = io;
		if (DEBUG) {
			io.setAutoFlush(true);
			io.debugln("debug mode");
		}
	}

	@Override
	public void run() {
		solve(io);
		io.flush();
	}
	Marathon marathon;

	private void solve(FastIO io) {
		io.setAutoFlush(true);
		marathon = new Marathon(io);
		MarathonTimer timer = new MarathonTimer(marathon);
		timer.start(LIMIT);

	}

	public long getLoop() {
		return marathon.getLoop();
	}

	public long getScore() {
		return marathon.getScore();
	}

	// 以下、ライブラリ

	public static final class FastRandom extends Random{
		private static final long serialVersionUID = -302298413684195190L;
		private long rand;
		private static final float FLOAT_INV = 1f / (1 << 24);
		private static final double DOUBLE_INV = 1. / (1L << 53);
		public FastRandom() {
			this(new Random().nextLong());
		}
		public FastRandom(long seed) {
			rand = seed;
		}
		@Override
		public void setSeed(long seed) {
			this.rand = seed;
		}
		@Override
		protected int next(int bits) {
			return (int)nextLong() & (1 << bits) - 1;
		}
		@Override
		public int nextInt() {
			rand = rand ^ (rand << 7);
			rand = rand ^ (rand >>> 9);
			return (int)(rand & Integer.MAX_VALUE);
		}
		@Override
		public int nextInt(int bounds) {
			return nextInt() % bounds;
		}
		public int nextRange(int startInclusive, int endExclusive) {
			return nextInt(endExclusive - startInclusive) + startInclusive;
		}
		@Override
		public long nextLong() {
			rand = rand ^ (rand << 7);
			rand = rand ^ (rand >>> 9);
			return rand & Long.MAX_VALUE;
		}
		@Override
		public boolean nextBoolean() {
			rand = rand ^ (rand << 7);
			rand = rand ^ (rand >>> 9);
			return (rand & 1) != 0;
		}
		@Override
		public float nextFloat() {
			rand = rand ^ (rand << 7);
			rand = rand ^ (rand >>> 9);
			return ((int)(rand & 0x00FFFFFF)) * FLOAT_INV;
		}
		@Override
		public double nextDouble() {
			rand = rand ^ (rand << 7);
			rand = rand ^ (rand >>> 9);
			return (rand & 0x001FFFFFFFFFFFFFL) * DOUBLE_INV;
		}
	}

	private static interface MarathonInterface {
		/**
		 * 標準入力を受け取り、処理しやすいように加工する関数です。
		 */
		public void init(Stop stop);
		/**
		 * 残り時間に応じた処理や、少し重い前処理などを行う関数です・
		 * @param delay 残り時間
		 */
		public void delayUpdate(int delay);
		/**
		 * 近傍を探したりなど、毎回更新の処理を行う関数です。
		 */
		public void update();
		/**
		 * 求まった結果を出力する関数です。
		 */
		public void terminate();
	}

	private static interface Stop {
		public void stop();
	}

	private static class MarathonTimer implements Runnable {

		private MarathonInterface marathon;
		private volatile boolean loopFlag;
		private ScheduledExecutorService  threadPool;
		private ScheduledFuture<?> future;

		public MarathonTimer(Marathon marathon) {
			this.marathon = marathon;
			threadPool = Executors.newScheduledThreadPool(2);
		}

		public void start(int millis) {
			loopFlag = true;
			marathon.init(() -> {
				if (marathon != null) marathon.terminate();
				marathon = null;
			});
			if (marathon == null) {
				return;
			}
			future = threadPool.schedule(() -> loopFlag = false, millis, TimeUnit.MILLISECONDS);
			threadPool.execute(this);
			try {
				threadPool.awaitTermination(7, TimeUnit.DAYS);
			} catch (InterruptedException e) {
				// TODO 自動生成された catch ブロック
				e.printStackTrace();
			}
		}

		@Override
		public void run() {
			try {
				while(loopFlag) {
					int delay = (int)future.getDelay(TimeUnit.MILLISECONDS);
					if (delay <= 0) {
						loopFlag = false;
						break;
					}
					marathon.delayUpdate(delay);
					for (int i = 0;i < ESTIMATE_LOOP;++ i) marathon.update();
				}
				marathon.terminate();
			} catch (NullPointerException e) {
				// これは想定なので問題なし
			} catch (Throwable e) {
				e.printStackTrace();
			}
			future.cancel(true);
			threadPool.shutdown();
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
			if (obj.getClass().isArray()) {
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
				if (array.getClass().isArray()) throw new IllegalArgumentException("not equal dimension");
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
}
