import java.util.*;
import java.io.*;

public class Main {
	static PrintWriter out;
	static StringBuilder sb;
	static int mod = (int) 1e9 + 7;
	static int inf = (int) 1e8;
	static int[] col;
	static int n, m, k;
	static ArrayList<Integer>[] ad;
	static int[][][] memo;
	static ArrayList<Integer> h;
	static char[][] grid;
	static int[] a;
	static boolean f;
	static int offest = 30;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
		long n = sc.nextLong();
		int ans = 0;

		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 2; i <= n / i; i++) {
			if (n % i == 0) {
				int p = 0;
				while (n % i == 0) {
					n /= i;
					p++;
				}
				a.add(p);
			}
		}
		if (n > 1)
			ans++;
		for (int i = 0; i < a.size(); i++) {
			int v = a.get(i);
			int lo = 1;
			int hi = 1000;
			int ad = 0;
			while (lo <= hi) {
				int mid = lo + hi >> 1;
				int x = mid * (mid + 1) / 2;
				if (x <= v) {
					ad = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			ans += ad;
		}
		System.out.println(ans);
		out.flush();
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
