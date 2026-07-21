import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static void solve() throws Exception {
		int n = scanInt();
		int a[] = new int[n];
		int prev = 0;
		boolean inc = true;
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
			if (a[i] <= prev) {
				inc = false;
			}
			prev = a[i];
		}
		if (inc) {
			out.print(1);
			return;
		}
		int l = 2, r = n;
		int pos[] = new int[n];
		int val[] = new int[n];
		bs: while (l < r) {
			int mid = (l + r) >> 1;
			int cnt = 0;
			int clen = 0;
			for (int ca: a) {
				if (ca > clen) {
					clen = ca;
					continue;
				}
				while (cnt > 0 && pos[cnt - 1] >= ca) {
					--cnt;
				}
				int cpos = ca - 1;
				while (cnt > 0 && pos[cnt - 1] == cpos && val[cnt - 1] == mid - 1) {
					--cnt;
					--cpos;
				}
				if (cpos == -1) {
					l = mid + 1;
					continue bs;
				}
				if (cnt > 0 && pos[cnt - 1] == cpos) {
					++val[cnt - 1];
				} else {
					pos[cnt] = cpos;
					val[cnt] = 1;
					++cnt;
				}
				clen = ca;
			}
			r = mid;
		}
		out.print(l);
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}
