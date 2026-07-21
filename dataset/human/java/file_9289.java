import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static int pow(int a, int e) {
		if (e == 0) {
			return 1;
		}
		int r = a;
		for (int i = 30 - Integer.numberOfLeadingZeros(e); i >= 0; i--) {
			r = mul(r, r);
			if ((e & (1 << i)) != 0) {
				r = mul(r, a);
			}
		}
		return r;
	}

	static int inv(int a) {
		return pow(a, MOD - 2);
	}

	static int h, p[], pprod[], pprodInv[];
	static int ans;

	static void solve() throws Exception {
		h = scanInt();
		p = new int[1 << (h - 1)];
		for (int i = 0; i < p.length; i++) {
			p[i] = scanInt() - 1;
		}
		pprod = new int[1 << h];
		pprodInv = new int[1 << h];
		pprod[1] = pprodInv[1] = 1;
		for (int i = 2; i < 1 << h; i++) {
			pprod[i] = mul(pprod[i / 2], i);
			pprodInv[i] = inv(pprod[i]);
		}
		ans = 0;
		int vs[] = new int[1 << (h - 1)];
		for (int i = 0; i < vs.length; i++) {
			vs[i] = i;
		}
		go(0, 0, 0, 0, vs);
		out.print(mul(ans, (MOD + 1) / 2));
	}

	static void go(int p1, int l1, int p2, int l2, int vs[]) {
		int cnt = 0, sum = 0;
		int nvs[] = new int[vs.length];
		for (int i: vs) {
			int j = p[i];
			if (i >> (h - 1 - l1) == p1 && j >> (h - 1 - l2) == p2) {
				nvs[cnt++] = i;
				sum = add(sum, mul(pprod[(1 << (h - 1)) + i], pprod[(1 << (h - 1)) + j]));
			}
		}
		if (cnt == 0) {
			return;
		}
		nvs = Arrays.copyOf(nvs, cnt);
		int mul = mul(mulAt2(p1, l1), mulAt2(p2, l2));
		ans = add(ans, mul(mul, mul(sum, sum)));
		if (l1 < h - 1) {
			go(2 * p1, l1 + 1, p2, l2, nvs);
			go(2 * p1 + 1, l1 + 1, p2, l2, nvs);
		}
		if (l1 == 0 && l2 < h - 1) {
			go(p1, l1, 2 * p2, l2 + 1, nvs);
			go(p1, l1, 2 * p2 + 1, l2 + 1, nvs);
		}
	}

	static int mulAt(int p, int l) {
		if (l == h - 1) {
			return 0;
		}
		int res = pprodInv[(1 << l) + p];
		if (l > 0) {
			res = mul(res, pprodInv[(1 << (l - 1)) + (p >> 1)]);
		}
		return res;
	}

	static int mulAt2(int p, int l) {
		int res = mulAt(p, l);
		if (l > 0) {
			res = sub(res, mulAt(p >> 1, l - 1));
		}
		return res;
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
