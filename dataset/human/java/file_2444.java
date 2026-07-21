import java.io.*;
import java.util.*;

public class Main {
	FastScanner in;
	PrintWriter out;

	class O implements Comparable<O> {
		int type;
		int x;

		public O(int type, int x) {
			super();
			this.type = type;
			this.x = x;
		}

		public int compareTo(O arg0) {
			return Integer.compare(x, arg0.x);
		}

	}

	void solve() {
		int n = in.nextInt();
		O[] o = new O[n * 2];
		for (int i = 0; i < n; i++) {
			o[i] = new O(+1, in.nextInt());
		}
		for (int i = 0; i < n; i++) {
			o[i + n] = new O(-1, in.nextInt());
		}
		Arrays.sort(o);
		int cur = 0;
		long res = 1;
		long mod = (long) 1e9 + 7;
		for (O oo : o) {
			if (cur != 0 && oo.type == cur / Math.abs(cur)) {
				res = (res * (Math.abs(cur) + 1) % mod);
			}
			cur += oo.type;
		}
		out.println(res);
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new Thread(null, new Runnable() {
			public void run() {
				new Main().runIO();
			}
		}, "1", 1 << 26).start();
	}
}
