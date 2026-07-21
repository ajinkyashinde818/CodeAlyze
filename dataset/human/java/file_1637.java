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
		A_ColorfulSubsequence solver = new A_ColorfulSubsequence();
		solver.solve(1, in, out);
		out.close();
	}

	static class A_ColorfulSubsequence {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			final int MOD = (int) (1e9 + 7);
			in.nextInt();
			char[] s = in.next().toCharArray();
			int[] a = new int[26];
			for (char c : s) {
				++a[c - 'a'];
			}
			long ans = 1;
			for (int x : a) {
				ans = ans * (x + 1) % MOD;
			}
			ans = (ans + MOD - 1) % MOD;
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

	}
}
