import java.util.*;
import java.io.*;

public class Main {
	static int mod = (int) 1e9 + 7;
	static int DX[] = { -1, 0, 1, 0 }, DY[] = { 0, -1, 0, 1 };
	static final int INF = Integer.MAX_VALUE / 3;
	static final long LINF = Long.MAX_VALUE / 3;

	public static void main(String[] args) {
		FastScanner fs = new FastScanner(System.in);
		int n = fs.nextInt();
		int x[] = fs.nextIntArray(n);
		
		long rsum[] = new long[n+1];
		for(int i=0;i<n;i++) {
			rsum[i+1] = plus(rsum[i], div(1,(i+1)));
		}
		
		int d[] = new int[n-1];
		for(int i=0;i<n-1;i++) {
			d[i] = x[i+1] - x[i];
		}
		
		long res = 0;
		for(int i=0;i<n-1;i++) {
			long t = mul(d[i], rsum[i+1]);
			res = plus(res, t);
		}
		
		for(int i=1;i<n;i++) {
			res = mul(res, i);
		}
		System.out.println(res);
		
	}
	
	//MOD culculations
	static long plus(long x, long y) {
		return (x + y) % mod;
	}

	static long sub(long x, long y) {
		return (x - y + mod) % mod;
	}

	static long mul(long x, long y) {
		return (x * y) % mod;
	}

	static long div(long x, long y) {
		return x * modpow(y, mod - 2) % mod;
	}

	static long modpow(long x, long y) {
		if (y == 0)
			return 1;
		if (y % 2 == 1)
			return (x * modpow(x, y - 1)) % mod;
		long root = modpow(x, y / 2);
		return root * root % mod;
	}
	
}

//高速なScanner
class FastScanner {
	private BufferedReader reader = null;
	private StringTokenizer tokenizer = null;

	public FastScanner(InputStream in) {
		reader = new BufferedReader(new InputStreamReader(in));
		tokenizer = null;
	}

	public String next() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String nextLine() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken("\n");
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public int[] nextIntArray(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public long[] nextLongArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}
}
