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
import java.util.Random;
import java.util.RandomAccess;
import java.util.function.BinaryOperator;
import java.util.function.UnaryOperator;

public class Main implements Runnable{

	private void solve(FastIO io) {
		/*
		 * author: 31536000
		 *
		 * 考察メモ
		 * 1. 一度の操作でN(N+1)/2個取り除く
		 * ⇒これの倍数で無ければNO
		 * 2. 差について、1ヶ所に+N-1、残りに-1を追加することができる
		 * ⇒操作回数がこれを用いて定まる
		 * 従って、これを用いれば解ける
		 * 2に関しては、操作回数をxとすると各操作は(diff+x)/N
		 * なお割り切れないならそもそもNo
		 *
		 */
		int N = io.nextInt();
		int[] A = io.nextInt(N);
		long sum = 0, put = (long)N * (N + 1) >> 1;
		for (int i : A) sum += i;
		if (sum % put != 0) {
			io.println("NO");
			return;
		}
		long get = sum / put, count = 0;
		CircularArray<Integer> array = new CircularArray<>(ArrayUtility.toObject(A));
		for (int i = 0;i < N;++ i) {
			long diff = array.get(i) - array.get(i + 1) + get;
			if (diff % N != 0) {
				io.println("NO");
				return;
			}
			count += Math.max(0, diff / N);
		}
		io.println(get == count, "YES", "NO");

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
		this(new FastIO());
	}

	public Main(FastIO io) {
		this.io = io;
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

	public static class ArrayUtility {

		private ArrayUtility() {
			throw new AssertionError();
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(boolean[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(boolean[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(boolean[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(byte[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(byte[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(byte[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(short[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(short[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(short[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(int[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(int[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(int[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(long[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(long[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(long[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(float[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(float[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(float[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(double[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(double[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(double[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(char[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(char[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(char[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 */
		public static void reverse(Object[] array) {
			if (array != null) for (int i = 0, l = array.length + 1 >> 1;i < l;++ i) ArrayUtility.swap(array, i, array.length - 1 - i);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param left 逆順にする左閉区間
		 * @param right 逆順にする右開区間
		 */
		public static void reverse(Object[] array, int left, int right) {
			for (-- right;left < right;++ left, -- right) ArrayUtility.swap(array, left, right);
		}

		/**
		 * 配列を逆順にします。
		 * @param array 元の配列
		 * @param range 逆順にする区間
		 */
		public static void reverse(Object[] array, IntRange range) {
			reverse(array, range.getClosedLower(), range.getOpenUpper());
		}

		/**
		 * 配列をシャッフルします。
		 * @param array 元の配列
		 */
		public static void shuffle(boolean[] array) {
			shuffle(array, new Random());
		}

		/**
		 * 配列をシャッフルします。
		 * @param array 元の配列
		 * @param random 乱数
		 */
		public static void shuffle(boolean[] array, Random random) {
			if (array != null) for (int i = array.length - 1;i > 0;-- i) ArrayUtility.swap(array, i, random.nextInt(i+1));
		}


		public static boolean[] getArray(int size, boolean value) {
			boolean[] ret = new boolean[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static byte[] getArray(int size, byte value) {
			byte[] ret = new byte[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static short[] getArray(int size, short value) {
			short[] ret = new short[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static int[] getArray(int size, int value) {
			int[] ret = new int[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static long[] getArray(int size, long value) {
			long[] ret = new long[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static float[] getArray(int size, float value) {
			float[] ret = new float[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static double[] getArray(int size, double value) {
			double[] ret = new double[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static char[] getArray(int size, char value) {
			char[] ret = new char[size];
			Arrays.fill(ret, value);
			return ret;
		}

		public static Boolean[] toObject(boolean[] array) {
			Boolean[] ret = new Boolean[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static Byte[] toObject(byte[] array) {
			Byte[] ret = new Byte[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static Short[] toObject(short[] array) {
			Short[] ret = new Short[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static Integer[] toObject(int[] array) {
			Integer[] ret = new Integer[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static Long[] toObject(long[] array) {
			Long[] ret = new Long[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static Float[] toObject(float[] array) {
			Float[] ret = new Float[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static Double[] toObject(double[] array) {
			Double[] ret = new Double[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static Character[] toObject(char[] array) {
			Character[] ret = new Character[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static boolean[] toPrimitive(Boolean[] array) {
			boolean[] ret = new boolean[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static boolean[] toPrimitive(Boolean[] array, boolean valueForNull) {
			boolean[] ret = new boolean[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static byte[] toPrimitive(Byte[] array) {
			byte[] ret = new byte[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static byte[] toPrimitive(Byte[] array, byte valueForNull) {
			byte[] ret = new byte[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static short[] toPrimitive(Short[] array) {
			short[] ret = new short[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static short[] toPrimitive(Short[] array, short valueForNull) {
			short[] ret = new short[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static int[] toPrimitive(Integer[] array) {
			int[] ret = new int[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static int[] toPrimitive(Integer[] array, int valueForNull) {
			int[] ret = new int[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static long[] toPrimitive(Long[] array) {
			long[] ret = new long[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static long[] toPrimitive(Long[] array, long valueForNull) {
			long[] ret = new long[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static float[] toPrimitive(Float[] array) {
			float[] ret = new float[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static float[] toPrimitive(Float[] array, float valueForNull) {
			float[] ret = new float[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static double[] toPrimitive(Double[] array) {
			double[] ret = new double[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static double[] toPrimitive(Double[] array, double valueForNull) {
			double[] ret = new double[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static char[] toPrimitive(Character[] array) {
			char[] ret = new char[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i];
			return ret;
		}

		public static char[] toPrimitive(Character[] array, char valueForNull) {
			char[] ret = new char[array.length];
			for (int i = 0;i < ret.length;++ i) ret[i] = array[i] == null ? valueForNull : array[i];
			return ret;
		}

		public static <T> T min(T[] array, Comparator<T> comparator) {
			if (array == null || array.length == 0) return null;
			T min = array[0];
			for (int i = 1;i < array.length;++ i) if (comparator.compare(min, array[i]) > 0) min = array[i];
			return min;
		}

		public static <T extends Comparable<T>> T min(T[] array) {
			if (array == null || array.length == 0) return null;
			T min = array[0];
			for (int i = 1;i < array.length;++ i) if (min.compareTo(array[i]) > 0) min = array[i];
			return min;
		}

		public static <T> T max(T[] array, Comparator<T> comparator) {
			if (array == null || array.length == 0) return null;
			T max = array[0];
			for (int i = 1;i < array.length;++ i) if (comparator.compare(max, array[i]) < 0) max = array[i];
			return max;
		}

		public static <T extends Comparable<T>> T max(T[] array) {
			if (array == null || array.length == 0) return null;
			T max = array[0];
			for (int i = 1;i < array.length;++ i) if (max.compareTo(array[i]) < 0) max = array[i];
			return max;
		}

		public static void swap(boolean[] array, int n, int m) {
			boolean swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(byte[] array, int n, int m) {
			byte swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(short[] array, int n, int m) {
			short swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(int[] array, int n, int m) {
			int swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(long[] array, int n, int m) {
			long swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(float[] array, int n, int m) {
			float swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(double[] array, int n, int m) {
			double swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(char[] array, int n, int m) {
			char swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static void swap(Object[] array, int n, int m) {
			Object swap = array[n];
			array[n] = array[m];
			array[m] = swap;
		}

		public static <T> boolean nextPermutation(T[] array, Comparator<T> comparator) {
			if (array == null) return false;
			int change;
			for (change = array.length - 2;change >= 0;-- change) {
				if (comparator.compare(array[change], array[change + 1]) < 0) {
					int min = change, max = array.length, halfDiff, mid;
					while((halfDiff = max - min >> 1) != 0) if (comparator.compare(array[change], array[mid = min + halfDiff]) < 0) min = mid; else max = mid;
					ArrayUtility.swap(array, change, min);
					for (min = change + 1, max = array.length - 1;min < max;++ min, -- max) ArrayUtility.swap(array, min, max);
					return true;
				}
			}
			return false;
		}
	}

	/**
	 * 端がもう片側の端と繋がり、循環する固定長配列を提供します。
	 * @author 31536000
	 *
	 * @param <T> 配列の型
	 */
	public static class CircularArray<T> extends Array<T>{

		private static final long serialVersionUID = 8755553665486205607L;
		private int first = 0;
		/**
		 * 長さsizeで、初期の要素が全てnullの配列を作成します。
		 * @param size 要素数
		 */
		public CircularArray(int size) {
			super(size);
		}

		/**
		 * arrayを固定長配列として扱います。
		 * @param array 元となる配列
		 */
		public CircularArray(T[] array) {
			super(array);
		}

		/**
		 * index番目の要素を取得します。
		 * @param index 取得する要素のインデックス
		 * @return index番目の要素
		 */
		private int getIndex(int index) {
			index -= first;
			if (index >= size()) index %= size();
			else if (index < 0) index = size() + index % size();
			return index;
		}

		/**
		 * 先頭の要素を上書きします。<br>
		 * この関数はset(0, value)と同一です。
		 * @param value 上書きする要素
		 */
		public void setFront(T value) {
			super.set(first, value);
		}

		/**
		 * index番目の要素を上書きします。<br>
		 * この時、indexは要素数を法とする自然数上に丸められます。
		 * @param index 上書きする場所
		 * @param value 上書きする値
		 */
		@Override
		public T set(int index, T value) {
			return super.set(getIndex(index), value);
		}

		/**
		 * 末尾の要素を上書きします。<br>
		 * この関数はset(-1, value)と同一です。
		 * @param value 上書きする要素
		 */
		public void setBack(T value) {
			super.set(first == 0 ? size() - 1 : first - 1, value);
		}

		/**
		 * index番目の要素を取得します。<br>
		 * この時、indexは要素数を法とする自然数上に丸められます。
		 * @param index 取得する場所
		 * @return index番目の要素
		 */
		@Override
		public T get(int index) {
			return super.get(getIndex(index));
		}

		/**
		 * 先頭の要素を取得します。<br>
		 * この関数はget(0)と同一です。
		 * @return 先頭の要素
		 */
		@Override
		public T front() {
			return super.get(first);
		}

		/**
		 * 末尾の要素を取得します。<br>
		 * この関数はget(-1)と同一です。
		 * @return 末尾の要素
		 */
		@Override
		public T back() {
			return super.get(first == 0 ? size() - 1 : first - 1);
		}

		/**
		 * 先頭の位置をずらします。<br>
		 * 例えばrotateが1の時、get(1)で取り出せていた要素は次からget(0)で取り出せるようになります。
		 * @param rotate ずらす量
		 */
		public void rotate(int rotate) {
			first = getIndex(rotate);
		}

		/**
		 * 先頭の位置を一つ後にずらします。<br>
		 * この関数はrotate(1)と同一です。
		 */
		public void rotateNext() {
			if (++first >= size()) first = 0;
		}


		/**
		 * 先頭の位置を一つ前にずらします。<br>
		 * この関数はrotate(-1)と同一です。
		 */
		public void rotatePrevious() {
			if (--first < 0) first = size() - 1;
		}

		private class Iter implements Iterator<T> {
			private int index;
			private int count;

			Iter() {
				index = first;
				count = 0;
			}

			@Override
			public boolean hasNext() {
				return count < size();
			}

			@Override
			public T next() {
				T ret = get(index);
				if (++index >= size()) index = 0;
				++ count;
				return ret;
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
			for (int i = 0;i < ret.length;++ i) ret[i] = Integer.valueOf(get[i]);
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
			for (int i = 0;i < ret.length;++ i) ret[i] = Long.valueOf(get[i]);
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
		private final int mod;
		private int[] fact, inv, invfact;

		/**
		 * modを法として、演算を行います。
		 * @param mod 法とする素数
		 */
		public ModUtility(Prime mod) {
			this(mod, 2);
		}

		/**
		 * modを法として、演算を行います。
		 * @param mod 法とする素数
		 * @param calc 予め前計算しておく大きさ
		 */
		public ModUtility(Prime mod, int calc) {
			this.mod = mod.prime;
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
			if (k < 0) throw new IllegalArgumentException();
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

	/**
	 * 素数を渡すためのクラスです。<br>
	 * 中身が確実に素数であることを保証するときに使ってください。
	 *
	 * @author 31536000
	 *
	 */
	public static class Prime extends Number{

		private static final long serialVersionUID = 8216169308184181643L;
		public final int prime;

		/**
		 * 素数を設定します。
		 *
		 * @param prime 素数
		 * @throws IllegalArgumentException 素数以外を渡した時
		 */
		public Prime(int prime) {
			if (!isPrime(prime)) throw new IllegalArgumentException(prime + " is not prime");
			this.prime = prime;
		}

		private static final int bases[] = {15591, 2018, 166, 7429, 8064, 16045, 10503, 4399, 1949, 1295, 2776, 3620, 560, 3128, 5212, 2657, 2300, 2021, 4652, 1471, 9336, 4018, 2398, 20462, 10277, 8028, 2213, 6219, 620, 3763, 4852, 5012, 3185, 1333, 6227, 5298, 1074, 2391, 5113, 7061, 803, 1269, 3875, 422, 751, 580, 4729, 10239, 746, 2951, 556, 2206, 3778, 481, 1522, 3476, 481, 2487, 3266, 5633, 488, 3373, 6441, 3344, 17, 15105, 1490, 4154, 2036, 1882, 1813, 467, 3307, 14042, 6371, 658, 1005, 903, 737, 1887, 7447, 1888, 2848, 1784, 7559, 3400, 951, 13969, 4304, 177, 41, 19875, 3110, 13221, 8726, 571, 7043, 6943, 1199, 352, 6435, 165, 1169, 3315, 978, 233, 3003, 2562, 2994, 10587, 10030, 2377, 1902, 5354, 4447, 1555, 263, 27027, 2283, 305, 669, 1912, 601, 6186, 429, 1930, 14873, 1784, 1661, 524, 3577, 236, 2360, 6146, 2850, 55637, 1753, 4178, 8466, 222, 2579, 2743, 2031, 2226, 2276, 374, 2132, 813, 23788, 1610, 4422, 5159, 1725, 3597, 3366, 14336, 579, 165, 1375, 10018, 12616, 9816, 1371, 536, 1867, 10864, 857, 2206, 5788, 434, 8085, 17618, 727, 3639, 1595, 4944, 2129, 2029, 8195, 8344, 6232, 9183, 8126, 1870, 3296, 7455, 8947, 25017, 541, 19115, 368, 566, 5674, 411, 522, 1027, 8215, 2050, 6544, 10049, 614, 774, 2333, 3007, 35201, 4706, 1152, 1785, 1028, 1540, 3743, 493, 4474, 2521, 26845, 8354, 864, 18915, 5465, 2447, 42, 4511, 1660, 166, 1249, 6259, 2553, 304, 272, 7286, 73, 6554, 899, 2816, 5197, 13330, 7054, 2818, 3199, 811, 922, 350, 7514, 4452, 3449, 2663, 4708, 418, 1621, 1171, 3471, 88, 11345, 412, 1559, 194};

		private static boolean isSPRP(int n, int a) {
			int d = n - 1, s = 0;
			while ((d & 1) == 0) {
				++s;
				d >>= 1;
			}
			long cur = 1, pw = d;
			while (pw != 0) {
				if ((pw & 1) != 0) cur = (cur * a) % n;
				a = (int)(((long)a * a) % n);
				pw >>= 1;
			}
			if (cur == 1) return true;
			for (int r = 0; r < s; r++ ) {
				if (cur == n - 1) return true;
				cur = (cur * cur) % n;
			}
			return false;
		}

		/**
		 * 与えられた値が素数か否かを判定します。<br>
		 * この実装はhttp://ceur-ws.org/Vol-1326/020-Forisek.pdfに基づきます。
		 * @param x 判定したい値
		 * @return xが素数ならtrue
		 */
		public static boolean isPrime(int x) {
			if (x == 2 || x == 3 || x == 5 || x == 7) return true;
			if ((x & 1) == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;
			if (x < 121) return x > 1;
			long h = x;
			h = ((h >> 16) ^ h) * 0x45d9f3b;
			h = ((h >> 16) ^ h) * 0x45d9f3b;
			h = ((h >> 16) ^ h) & 0xFF;
			return isSPRP(x, bases[(int)h]);
		}

		@Override
		public int intValue() {
			return prime;
		}

		@Override
		public long longValue() {
			return prime;
		}

		@Override
		public float floatValue() {
			return prime;
		}

		@Override
		public double doubleValue() {
			return prime;
		}

		@Override
		public String toString() {
			return String.valueOf(prime);
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
