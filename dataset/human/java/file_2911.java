import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main implements Runnable { // クラス名はMain1

	PrintWriter out = new PrintWriter(System.out);
	InputReader sc = new InputReader(System.in);
	static int mod = (int) (1e9 + 7); //10^9+7
	int[] dx = { 1, 0, -1, 0 }, dy = { 0, 1, 0, -1 }; //4 directions

	public static void main(String[] args) {
		Thread.setDefaultUncaughtExceptionHandler((t, e) -> System.exit(1));
		new Thread(null, new Main(), "", 1024 * 1024 * 1024).start(); // 16MBスタックを確保して実行
	}

	public void run() {

		try {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[][] AB = new int[M][3];
			for (int i = 0; i < M; i++) {
				AB[i][0] = sc.nextInt() - 1;
				AB[i][1] = sc.nextInt() - 1;
				AB[i][2] = 1;
			}

			Dijkstra d = new Dijkstra(N, AB);
			long count = d.dijkstra(0, N - 1);
			if (count <= 2) {
				out.println("POSSIBLE");
			} else {
				out.println("IMPOSSIBLE");
			}

			//out.println(d.dijkstra(0, N - 1));

		} catch (ArithmeticException ae) {
			//ae.printStackTrace();
			throw new RuntimeException();
		} catch (Exception e) {
			//e.printStackTrace();
			throw new RuntimeException();
		} finally {
			out.flush();
			out.close();
		}

	}

	class Dijkstra {
		int n; //頂点数
		int[][] adj;
		List<Edge>[] edges;
		long[] distance;

		public Dijkstra(int N, int[][] ADJ) {
			//Wikipedia の例(図)をデータにしたもの
			this.n = N; //頂点数
			//this.s = S; //スタート頂点(頂点番号は -1 されている[元は 1])
			/**
			 * { 0, 1, 7 },
			 * { 0, 2, 9 },
			 * { 0, 5, 14 },
			 * { 1, 2, 10 },
			 * { 1, 3, 15 },
			 * { 2, 3, 11 },
			 * { 2, 5, 2 },
			 * { 3, 4, 6 },
			 * { 4, 5, 9 }
			 * s:0 → g:4 のとき、答えは 20
			 */
			this.adj = ADJ;

			//隣接リスト
			@SuppressWarnings("unchecked")
			List<Edge>[] edges = new List[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new ArrayList<Edge>();
			}

			for (int i = 0; i < adj.length; i++) {
				edges[adj[i][0]].add(new Edge(adj[i][0], adj[i][1], (long) adj[i][2]));
				edges[adj[i][1]].add(new Edge(adj[i][1], adj[i][0], (long) adj[i][2])); //無向グラフなので、逆方向も接続する
			}
			this.edges = edges;
		}

		static final long INF = Long.MAX_VALUE / 2; //INF 値(十分に大きな値)

		//ダイクストラ法[単一始点最短経路(Single Source Shortest Path)]
		long dijkstra(int s, int g) {
			distance = new long[n]; //始点からの最短距離

			Arrays.fill(distance, INF); //各頂点までの距離を初期化(INF 値)
			distance[s] = 0; //始点の距離は０

			Queue<Edge> q = new PriorityQueue<Edge>();
			q.add(new Edge(s, s, 0)); //始点を入れる

			while (!q.isEmpty()) {
				Edge e = q.poll(); //最小距離(cost)の頂点を取り出す
				if (distance[e.target] < e.cost) {
					continue;
				}

				//隣接している頂点の最短距離を更新する
				for (Edge v : edges[e.target]) {
					if (distance[v.target] > distance[e.target] + v.cost) { //(始点～)接続元＋接続先までの距離
						distance[v.target] = distance[e.target] + v.cost; //現在記録されている距離より小さければ更新
						q.add(new Edge(e.target, v.target, distance[v.target])); //始点～接続先までの距離
					}
				}
			}

			this.distance = distance;
			return distance[g]; //到達できなかったときは、INF となる
		}

		//ダイクストラ法[単一始点最短経路(Single Source Shortest Path)]
		long[] dijkstras(int s) {
			distance = new long[n]; //始点からの最短距離

			Arrays.fill(distance, INF); //各頂点までの距離を初期化(INF 値)
			distance[s] = 0; //始点の距離は０

			Queue<Edge> q = new PriorityQueue<Edge>();
			q.add(new Edge(s, s, 0)); //始点を入れる

			while (!q.isEmpty()) {
				Edge e = q.poll(); //最小距離(cost)の頂点を取り出す
				if (distance[e.target] < e.cost) {
					continue;
				}

				//隣接している頂点の最短距離を更新する
				for (Edge v : edges[e.target]) {
					if (distance[v.target] > distance[e.target] + v.cost) { //(始点～)接続元＋接続先までの距離
						distance[v.target] = distance[e.target] + v.cost; //現在記録されている距離より小さければ更新
						q.add(new Edge(e.target, v.target, distance[v.target])); //始点～接続先までの距離
					}
				}
			}

			return this.distance = distance; //到達できなかったときは、INF となる

		}
	}

	//辺情報の構造体
	class Edge implements Comparable<Edge> {
		public int source = 0; //接続元ノード
		public int target = 0; //接続先ノード
		public long cost = 0; //重み

		public Edge(int source, int target, long cost) {
			this.source = source;
			this.target = target;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return Long.compare(this.cost, o.cost); //重みの小さい順
		}

		@Override
		public String toString() { //デバッグ用
			return "source = " + source + ", target = " + target + ", cost = " + cost;
		}
	}

	class Info implements Comparable<Info> {
		public long a;
		public long b;

		public Info(long a, long b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Info o) {
			//return this.a - o.a;//昇順
			// return o.a - this.a;//降順
			//複数項目で並び替え。aの降順、aが同じならbの降順
			if (this.a == o.a) {
				return Long.compare(o.b, this.b);
			} else {
				return Long.compare(o.a, this.a);
			}
		}
	}

	//Arrays.sort(Sample,new Comp());
	class Comp implements Comparator<Info> {
		public int compare(Info be, Info af) {
			return Long.compare(af.a, be.a);
		}
	}

	/**
	 *
	 * @param n
	 * @param m
	 * @return Combinationの数を返す(mod無しなので、大きい値には使用できない桁溢れする)
	 */
	long calcCombination(int n, int m) {
		if (n < m || m < 0) {
			throw new IllegalArgumentException("引数の値が不正です ( n : " + n + ", m : " + m + ")");
		}
		long c = 1;
		m = (n - m < m ? n - m : m);
		for (int ns = n - m + 1, ms = 1; ms <= m; ns++, ms++) {
			c *= ns;
			c /= ms;
		}
		return c;
	}

	/*
	 * 使用するときはModに注意。Global変数を参照
	 */
	public static long comb(long a, long b) {
		if (a < b)
			return 0;
		long res = 1;
		long inv = pow(fact(Math.min(b, a - b)), mod - 2);
		for (long i = a; i > a - Math.min(b, a - b); i--) {
			res *= i;
			res %= mod;
		}
		res *= inv;
		res %= mod;
		return res;
	}

	public static long pow(long x, long n) {
		long res = 1;
		while (n > 0) {
			if ((n & 1) == 1) {
				res *= x;
				res %= mod;
			}
			x *= x;
			x %= mod;
			n >>= 1;
		}
		return res;
	}

	public static long fact(long n) {
		long res = 1;
		while (n > 0) {
			res *= n;
			res %= mod;
			n--;
		}
		return res;
	}

	// 高速なScanner
	static class InputReader {
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
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

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}
