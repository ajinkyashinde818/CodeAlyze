import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	void solve() throws IOException {
		int d = ni();
		long g = nl() / 100;
		int[][] a = nia(d, 2);
		long[] dp = new long[1001];
		for (int i = 0; i < d; i++) {
			for (int k = 1000; k >= 1; k--) {
				for (int j = 1; j <= a[i][0] && j <= k; j++) {
					int inc = (j < a[i][0] ? 0 : a[i][1] / 100) + (i + 1) * j;
					dp[k] = Math.max(dp[k], dp[k - j] + inc);
				}
			}
		}
		for (int i = 1; i <= 1000; i++)
			if (dp[i] >= g) {
				out.println(i);
				break;
			}
	}

	String ns() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine(), " ");
		}
		return tok.nextToken();
	}

	int ni() throws IOException {
		return Integer.parseInt(ns());
	}

	long nl() throws IOException {
		return Long.parseLong(ns());
	}

	double nd() throws IOException {
		return Double.parseDouble(ns());
	}

	String[] nsa(int n) throws IOException {
		String[] res = new String[n];
		for (int i = 0; i < n; i++) {
			res[i] = ns();
		}
		return res;
	}

	int[] nia(int n) throws IOException {
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = ni();
		}
		return res;
	}

	int[][] nia(int n, int m) throws IOException {
		int[][] res = new int[n][];
		for (int i = 0; i < n; i++) {
			res[i] = nia(m);
		}
		return res;
	}

	long[] nla(int n) throws IOException {
		long[] res = new long[n];
		for (int i = 0; i < n; i++) {
			res[i] = nl();
		}
		return res;
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		tok = new StringTokenizer("");
		Main main = new Main();
		main.solve();
		out.close();
	}
}
