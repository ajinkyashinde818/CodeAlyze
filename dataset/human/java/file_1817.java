import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class Main implements Runnable { // クラス名はMain1

	public static void main(String[] args) {
		Thread.setDefaultUncaughtExceptionHandler((t, e) -> System.exit(1));
		new Thread(null, new Main(), "", 1024 * 1024 * 1024).start(); // 16MBスタックを確保して実行
	}

	public void run() {
		FastScannerMain1 sc = new FastScannerMain1(System.in);

		try {
			/**
			 * 表示系
			 *   System.out.println();
			 *   System.out.println("i:" + i + " ,j:" + j);
			 *   System.out.println(Arrays.toString(A));
			 *
			 * Sort (Arrays)
			 *  Integer[] A = new Integer[N];
			 *    Desc : Arrays.sort(A , Collections.reverseOrder());
			 *    Asc  : Arrays.sort(A);
			 *
			 * 定義系
			 *   int[] s = new int[M];
			 *   ArrayDeque<Integer> deq= new ArrayDeque<>();//先頭と末尾への要素の追加・先頭と末尾の要素の取り出しと削除が定数時間
			 *   ArrayList<Integer> arr = new ArrayList<Integer>();//定数時間
			 *   HashMap<Integer,Integer> hm = new HashMap<>(); //定数時間
			 *
			 *   //要素の追加と、最小の要素の取り出しと削除が対数時間
			 *   PriorityQueue<Integer> pq = new PriorityQueue<>();//昇順
			 *   PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); //逆順。降順
			 *
			 *   TreeSet<Integer> ts = new TreeSet<>();//対数時間(重複はできない)
			 *
			 * 文字系
			 *   String S = sc.nextLine().trim();
			 *   for (char i = 'a'; i <= 'z'; i++) {}
			 *   S.substring(1,2);//あいうえお → い
			 *   S.substring(0,1); // 1文字目をとりたいとき
			 *   文字列のSort
			 *    String sorted = S.chars().sorted().collect(StringBuilder::new,StringBuilder::appendCodePoint, StringBuilder::append) .toString();
			 */
			// long l = sc.nextLong();

			int D = sc.nextInt();
			int G = sc.nextInt();
			int[] p = new int[D];
			int[] c = new int[D];
			for (int i = 0; i < D; i++) {
				p[i] = sc.nextInt();
				c[i] = sc.nextInt();
			}

			int ans = Integer.MAX_VALUE;

			Outer: for (int bit = 0; bit < (1 << D); bit++) {
				boolean[] used = new boolean[D];
				int score = 0;
				int count = 0;
				//System.out.println("----" + Integer.toBinaryString(bit) + "----");

				Inner: for (int j = 0; j < D; j++) {
					if ((1 & bit >> j) == 1) {
						count += p[j];
						score += ((j + 1) * p[j] * 100 + c[j]);
						used[j] = true;
					}
				}
				//System.out.println(Integer.toBinaryString(bit) + " =  score : " + score + " , count : " + count);

				if (score < G) {
					second: for (int i = D - 1; i >= 0; i--) {
						if (used[i]) {
							continue second;
						} else {
							double diff = G - score;
							double num = Math.ceil(diff / ((i + 1) * 100));
							if (num <= p[i]) {
								count += num;
								break second;
							} else {
								continue Outer;
							}
						}
					}
				}

				ans = Math.min(ans, count);
				//System.out.println(Integer.toBinaryString(bit) + " =  score : " + score + " , count : " + count
				//		+ " , ans : " + ans);

			}

			System.out.println(ans);

			/*
			int ans = Integer.MAX_VALUE;
			for (int bits = 0; bits < (1 << D); bits++) {
				System.out.println("----" + Integer.toBinaryString(bits) + "----");
				int score = 0, cnt = 0, restMax = -1;
			
				for (int i = 0; i < D; i++) {
					if ((bits >> i & 1) == 1) {
						score += 100 * (i + 1) * p[i] + c[i];
						cnt += p[i];
					} else {
						restMax = i;
					}
				}
			
				System.out.println(Integer.toBinaryString(bits) + " =  score : " + score + " , cnt : " + cnt
						+ " , restMax : " + restMax);
			
				if (score < G) {
					int point = 100 * (restMax + 1);
					int add = (G - score + (point - 1)) / point;
			
					if (add >= p[restMax])
						continue;
			
					cnt += add;
				}
			
				System.out.println(Integer.toBinaryString(bits) + " cnt : " + cnt);
			
				ans = Math.min(ans, cnt);
				System.out.println(ans);
			}
			*/

			/*
			String[] ar = { "a", "b", "c" };
			
			//要素数
			int n = 3;
			
			//以下メイン処理
			for (int i = 0; i < (Math.pow(2, n)); i++) {
				String s = "-";
				System.out.println("------" + Integer.toBinaryString(i) + "------");
				for (int j = 0; j < n; j++) {
					System.out.println(1 & (i >> j));
					if ((1 & i >> j) == 1) {
						s += ar[j];
					}
				}
				System.out.println("------" + " " + s + "------");
			}
			*/

		} catch (

		ArithmeticException ae) {
			ae.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	// 下記はオーバーフローでExceptionをキャッチするよう
	private long multiple(long a, long b) {
		long ans = 0;
		try {
			ans = Math.multiplyExact(a, b);
			return ans;
		} catch (ArithmeticException ae) {
			throw new ArithmeticException();
		}
	}

	private int multiple(int a, int b) {
		int ans = 0;
		try {
			ans = Math.multiplyExact(a, b);
			return ans;
		} catch (ArithmeticException ae) {
			throw new ArithmeticException();
		}
	}

	private long add(long a, long b) {
		long ans = 0;
		try {
			ans = Math.addExact(a, b);
			return ans;
		} catch (ArithmeticException ae) {
			throw new ArithmeticException();
		}
	}

	private int add(int a, int b) {
		int ans = 0;
		try {
			ans = Math.addExact(a, b);
			return ans;
		} catch (ArithmeticException ae) {
			throw new ArithmeticException();
		}
	}

	/*
	 * HashmapのSort
	 * hmはhashmap
	 * keyvalは"key" or "val"を指定して
	 * ascdescは"asc" or "desc"を指定して
	 */
	private List<Entry<Integer, Integer>> sortHashMapValue(HashMap<Integer, Integer> hm, String keyval,
			String ascdesc) {
		// 1.Map.Entryのリストを作成する
		List<Entry<Integer, Integer>> list_entries = new ArrayList<Entry<Integer, Integer>>(hm.entrySet());

		// 2.比較関数Comparatorを使用してMap.Entryの値を比較する(昇順)
		Collections.sort(list_entries, new Comparator<Entry<Integer, Integer>>() {
			public int compare(Entry<Integer, Integer> obj1, Entry<Integer, Integer> obj2) {
				if (keyval.equals("val")) {
					if (ascdesc.equals("asc")) {
						// 昇順(value)
						return obj1.getValue().compareTo(obj2.getValue());
					} else {
						// 降順(value)
						return obj2.getValue().compareTo(obj1.getValue());
					}
				} else {
					if (ascdesc.equals("asc")) {
						// 昇順(value)
						return obj1.getKey().compareTo(obj2.getKey());
					} else {
						// 降順(value)
						return obj2.getKey().compareTo(obj1.getKey());
					}
				}
			}
		});
		/*
		// 3. ループで要素順に値を取得する
		for (Entry<Integer, Integer> entry : list_entries) {
			System.out.println(entry.getKey() + " : " + entry.getValue());
		}
		*/
		return list_entries;
	}
}

// 高速なScanner
class FastScannerMain1 {
	private BufferedReader reader = null;
	private StringTokenizer tokenizer = null;

	public FastScannerMain1(InputStream in) {
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
