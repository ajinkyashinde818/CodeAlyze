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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskB {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int[] a = new int[n];
			long s = 0;
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
				s += a[i];
			}
			long s1 = n * (long) (n + 1) / 2;
			if (s % s1 != 0) {
				out.println("NO");
				return;
			}
			long m = s / s1;
			long used = 0;
			for (int i = 0; i < n; i++) {
				long x = a[(i + 1) % n] - a[i];
				if ((m - x) % n != 0) {
					out.println("NO");
					return;
				}
				long k = (m - x) / n;
				if (k < 0 || k > m) {
					out.println("NO");
					return;
				}
				used += k;
			}
			if (used != m) {
				out.println("NO");
				return;
			}
			out.println("YES");
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

	}
}
