import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] sa = br.readLine().split(" ");
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = Integer.parseInt(sa[i]);
		}
		br.close();

		int mod = 1000000007;
		long[] p = new long[n];
		long[] pi = new long[n];
		p[0] = 1;
		pi[0] = 1;
		long[] d = new long[n];
		for (int i = 1; i < n; i++) {
			p[i] = p[i - 1] * i % mod;
			pi[i] = modinv(p[i], mod);
			d[i] = x[i] - x[i - 1];
		}

		long[] b = new long[n];
		b[1] = 1;
		for (int i = 2; i < n; i++) {
			b[i] = (b[i - 1] * i + p[i - 1]) % mod;
		}
		long[] c = new long[n];
		for (int i = 1; i < n; i++) {
			c[i] = b[i] * p[n - 1] % mod * pi[i] % mod;
		}

		long ans = 0;
		for (int i = 1; i < n; i++) {
			long val = c[i] * d[i];
			ans += val;
			ans %= mod;
		}
		System.out.println(ans);
	}

	static long modinv(long a, long m) {
		long b = m;
		long u = 1;
		long v = 0;
		long tmp = 0;

		while (b > 0) {
			long t = a / b;
			a -= t * b;
			tmp = a;
			a = b;
			b = tmp;

			u -= t * v;
			tmp = u;
			u = v;
			v = tmp;
		}

		u %= m;
		if (u < 0) u += m;
		return u;
	}
}
