import java.io.*;
import java.util.*;

public class Main {
	static PrintWriter out;
	static StringBuilder sb;
	static int n, m, k;
	static long mod = 998244353;
	static Boolean[][] memo;
	static String s;
	static ArrayList<Integer>[] ad;
	static long inf = Long.MAX_VALUE;
	static int[] color;
	static ArrayList<Integer> o;
	static char[][] g;
	static boolean[] vis, vis1;
	static long[] f;
	static long[] a, dest;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
		int k = sc.nextInt();
		int n = sc.nextInt();
		f = new long[4001];
		f[0] = 1;
		long[][] tab = new long[4001][4001];
		// for (int i = 1; i < 4001; i++)
		// f[i] = i * f[i - 1] % mod;
		tab[0][0] = 1;
		for (int i = 1; i < 4001; i++) {
			tab[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				tab[i][j] = (tab[i - 1][j] + tab[i - 1][j - 1]) % mod;
			}
		}
		for (int i = 2; i <= 2 * k; i++) {
			long ans = 0;
			int und = i / 2;
			int up = k - (i - i / 2) + 1;
			int av = Math.min(up, und);
			for (int j = 0; j <= av; j++) {
				// System.out.println(i+" "+j+" "+av);
				if (n - j * 2 < 0)
					continue;
				long v = tab[av][j] * tab[n - j * 2 + k - 1][n - j * 2]% mod;
				if (j % 2 == 0) {
					ans = (ans + v) % mod;
				} else {
					ans = (ans - v + mod) % mod;
				}
			}
			out.println(ans);
		}
		out.flush();
	}

	static long nCk(int n, int k) {
		long ll = f[n] * modPow(f[n - k], mod - 2) % mod;
		ll = ll * modPow(f[k], mod - 2) % mod;
		return ll;
	}

	static long modPow(long a, long e)

	{
		long res = 1;
		while (e > 0) {
			if ((e & 1) == 1)
				res = (res * a) % mod;
			a = (a * a) % mod;
			e >>= 1;
		}
		return res;
	}

	static class pair implements Comparable<pair> {
		long x;
		int y, lv;

		pair(long x, int y, int l) {
			this.x = x;
			this.y = y;
			lv = l;
		}

		public String toString() {
			return x + " " + y + " " + lv;
		}

		@Override
		public int compareTo(pair o) {
			if (x == o.x)
				return y - o.y;
			return Long.compare(o.x, x);
		}

	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public int[] nextArrInt(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextArrLong(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}
