import java.io.*;
import java.util.*;

public class Main {
	static InputReader scn = new InputReader(System.in);
	static OutputWriter out = new OutputWriter(System.out);

	public static void main(String[] args) {
		int t = 1;
		while (t-- > 0)
			solve();
		out.close();
	}

	public static void solve() {
		int n = scn.nextInt();
		int max = 0;
		int val = 0;
		while (n-- > 0) {
			int a = scn.nextInt();
			int b = scn.nextInt();
			if (a == b) {
				val++;
				max = Math.max(max, val);
			} else {
				val = 0;
			}
		}
		if (max >= 3)
			out.println("Yes");
		else
			out.println("No");
	}

	public static HashMap<Integer, Integer> CountFrequencies(int[] arr) {
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < arr.length; i++) {
			int a = arr[i];
			if (map.containsKey(a)) {
				map.put(a, map.get(a) + 1);
			} else {
				map.put(a, 1);
			}
		}
		return map;
	}

	public static int countPrimeFactors(int n) {
		int count = 0;
		while (n % 2 == 0) {
			n = n / 2;
			count++;
		}
		for (int i = 3; i <= Math.sqrt(n); i = i + 2) {
			while (n % i == 0) {
				n = n / i;
				count++;
			}
		}
		if (n > 2)
			count++;
		return (count);
	}

	public static int max(int a, int b) {
		if (a >= b)
			return a;
		return b;
	}

	public static int min(int a, int b) {
		if (a <= b)
			return a;
		return b;
	}

	public static long gcd(long a, long b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	public static long lcm(long a, long b) {
		return (a * b) / gcd(a, b);
	}

	public static boolean isPrime(long n) {
		if (n < 2)
			return false;
		if (n == 2 || n == 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;
		long sqrtN = (long) Math.sqrt(n) + 1;
		for (long i = 6L; i <= sqrtN; i += 6) {
			if (n % (i - 1) == 0 || n % (i) + 1 == 0)
				return false;
		}
		return true;
	}

	public static int[] SieveOfEratosthenes(int[] arr) {
		int n = arr.length;
		for (long i = 3; i < n; i = i + 2) {
			arr[(int) i] = 1;
		}
		for (long i = 3; i < n; i = i + 2) {
			if (arr[(int) i] == 1) {
				for (long j = (long) i * i; j < n; j = j + i) {
					arr[(int) j] = 0;
				}
			}
		}
		arr[2] = 1;
		arr[0] = arr[1] = 0;
		return arr;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l = new ArrayList<>();
		for (int i : a) {
			l.add(i);
		}
		Collections.sort(l);
		for (int i = 0; i < a.length; i++) {
			a[i] = l.get(i);
		}
	}

	public static ArrayList<String> printPermutn(String str, String ans, ArrayList<String> list) {
		if (str.length() == 0) {
			list.add(ans);
		}
		for (int i = 0; i < str.length(); i++) {
			char ch = str.charAt(i);
			String ros = str.substring(0, i) + str.substring(i + 1);
			printPermutn(ros, ans + ch, list);
		}
		return list;
	}

	public static int binarySearch(int arr[], int l, int r, int x) {
		if (r >= l) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == x)
				return mid;
			if (arr[mid] > x)
				return binarySearch(arr, l, mid - 1, x);
			return binarySearch(arr, mid + 1, r, x);
		}
		return -1;
	}

	public static int firstOccurence(int array1[], int low, int high, int x, int n) {
		if (low <= high) {
			int mid = low + (high - low) / 2;
			if ((mid == 0 || x > array1[mid - 1]) && array1[mid] == x)
				return mid;
			else if (x > array1[mid])
				return firstOccurence(array1, (mid + 1), high, x, n);
			else
				return firstOccurence(array1, low, (mid - 1), x, n);
		}
		return -1;
	}

	public static int lastOccurence(int array2[], int low, int high, int x, int n) {
		if (low <= high) {
			int mid = low + (high - low) / 2;
			if ((mid == n - 1 || x < array2[mid + 1]) && array2[mid] == x)
				return mid;
			else if (x < array2[mid])
				return lastOccurence(array2, low, (mid - 1), x, n);
			else
				return lastOccurence(array2, (mid + 1), high, x, n);
		}
		return -1;
	}

	static final Random random = new Random();

	static void ruffleSort(int[] a) {
		int n = a.length;// shuffle, then sort
		for (int i = 0; i < n; i++) {
			int oi = random.nextInt(n), temp = a[oi];
			a[oi] = a[i];
			a[i] = temp;
		}
		Arrays.sort(a);
	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int[] readArrays(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = scn.nextInt();
			}
			return arr;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return nextLine();
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0) {
					writer.print(' ');
					// writer.print(1);
				}
				writer.print(objects[i]);
			}
		}

		public void println(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}
	}

}
