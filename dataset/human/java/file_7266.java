import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main implements Runnable { //クラス名はMain1

	public static void main(String[] args) {
		Thread.setDefaultUncaughtExceptionHandler((t, e) -> System.exit(1));
		new Thread(null, new Main(), "", 1024 * 1024 * 1024).start(); //16MBスタックを確保して実行
	}

	/**
	 * for (int i = 0; i < N; i++) {}
	 * System.out.println();
	 * HashMap<Integer, Integer> hm = new HashMap<>();
	 * int[] s = new int[M];
	 * ArrayDeque<Integer> deq = new ArrayDeque<>();
	 *
	 * 文字列のSort
	 * String sorted = S.chars()
						.sorted()
						.collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
						.toString();
	 * for (char i = 'a'; i <= 'z'; i++) {}
	 */
	public void run() {
		FastScannerMainC sc = new FastScannerMainC(System.in);

		try {
			//String S = sc.nextLine().trim();
			//int[] a = new int[N];
			//long l = sc.nextLong();
			//ArrayList<Integer> arr = new ArrayList<Integer>();
			//for (char i = 'a'; i <= 'z'; i++) {}
			int K = sc.nextInt();
			int N = sc.nextInt();
			long[] A = new long[N];

			for (int i = 0; i < N; i++) {
				A[i] = sc.nextLong();
			}

			long diff1 = Integer.MIN_VALUE;
			int start = 0;

			for (int i = 1; i < N; i++) {
				if (diff1 < Math.abs(A[i] - A[i - 1])) {
					diff1 = Math.abs(A[i] - A[i - 1]);
					start = i - 1;
				}
			}

			long diff = Math.abs(A[0]) + Math.abs(K - A[N - 1]);

			//System.out.println(diff);
			//System.out.println(diff1);
			//System.out.println(start);

			long count = 0;
			if (diff >= diff1) {
				for (int i = 1; i < N; i++) {
					count += Math.abs(A[i] - A[i - 1]);
				}
			} else {
				count = diff;
				//	System.out.println(count);
				for (int i = start; i > 0; i--) {
					count += Math.abs(A[i] - A[i - 1]);
				}
				//	System.out.println(count);
				for (int i = start + 1; i < N - 1; i++) {
					//		System.out.println(i + " " + (i + 1));
					count += Math.abs(A[i] - A[i + 1]);
				}
			}
			System.out.println(count);

		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}

//高速なScanner
class FastScannerMainC {
	private BufferedReader reader = null;
	private StringTokenizer tokenizer = null;

	public FastScannerMainC(InputStream in) {
		reader = new BufferedReader(new InputStreamReader(in));
		tokenizer = null;
	}

	public String next() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String nextLine() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken("\n");
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public int[] nextIntArray(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public long[] nextLongArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}
}
