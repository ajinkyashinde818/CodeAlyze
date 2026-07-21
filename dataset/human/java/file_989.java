import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskD {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			long c = in.nextLong();
			long[] x = new long[n];
			long[] v = new long[n];
			for (int i = 0; i < n; i++) {
				x[i] = in.nextLong();
				v[i] = in.nextLong();
			}

			// Full circle.
			long ans = -c;
			for (int i = 0; i < n; i++) {
				ans += v[i];
			}

			long[] d0 = new long[n];
			{
				long sum = 0;
				for (int i = 0; i < n; i++) {
					sum += v[i];
					d0[i] = sum - 2 * x[i];
					if (i > 0) {
						d0[i] = Math.max(d0[i], d0[i - 1]);
					} else {
						d0[i] = Math.max(d0[i], 0);
					}
				}
			}

			long[] d1 = new long[n];
			{
				long sum = 0;
				for (int i = n - 1; i >= 0; i--) {
					sum += v[i];
					d1[i] = sum - 2 * (c - x[i]);
					if (i + 1 < n) {
						d1[i] = Math.max(d1[i], d1[i + 1]);
					} else {
						d1[i] = Math.max(d1[i], 0);
					}
				}
			}

			{
				long sum = 0;
				for (int i = 0; i < n; i++) {
					sum += v[i];
					long cur = Math.max(0, sum - x[i]);
					if (i + 1 < n) {
						cur += d1[i + 1];
					}
					ans = Math.max(ans, cur);
				}
			}

			{
				long sum = 0;
				for (int i = n - 1; i >= 0; i--) {
					sum += v[i];
					long cur = Math.max(0, sum - (c - x[i]));
					if (i - 1 >= 0) {
						cur += d0[i - 1];
					}
					ans = Math.max(ans, cur);
				}
			}

			out.println(ans);
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}
