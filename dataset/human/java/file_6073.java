import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;


public class Main {
	public static long MOD = 998244353;
	public static void main(String[] args) {
		IO io = new IO();
		int k = io.nextInt();
		int n = io.nextInt();
		long[][] dp = new long[k+1][n+1];
		dp[0][0] = 1;
		for(int i=1;i<=k;i++) {
			long sum = 0;
			for(int j=0;j<=n;j++) {
				dp[i][j] = (sum * 2 + dp[i-1][j]) % MOD;
				sum += dp[i-1][j];
				if (sum >= MOD) sum -= MOD;
			}
		}
		comb = Mod.combinationArray(4010, 4010, MOD);
		for(int i=2;i<=2*k;i++) {
			//naive
			int width = 0;
			for(int j=1;j<=i/2;j++) {
				if (i - j <= k) width++;
			}
			if (i % 2 == 0) width--;
			
			long sum = 0;
			for(int j=0;j<=n;j++) {
				if (width == 0 && j > 0) break;
				int usable = k - width * 2;
				long left;
				if (i % 2 == 1) {
					//odd
					left = h(usable , n - j);
				}else {
					//even
					left = h(usable - 1, n - j);
					if (n - j - 1 >= 0) {
						left += h(usable - 1, n - j - 1);
					}
					if (left >= MOD) left -= MOD;
				}
				sum = (sum + left * dp[width][j]) % MOD;
			}
			io.println(sum);
		}
		io.flush();
	}
	
	public static long[][] comb;
	public static long h(int n, int k) {
		if (n + k == 0) return 1; //hack?
		return comb[n+k-1][k];
	}
}
class Mod {
	public static long n(long x,long mod) {
		x %= mod;
		if (x < 0) {
			x += mod;
		}
		return x;
	}
	public static long pow(long a,long n,long mod) {
		long res = 1;
		while(n > 0) {
			if ((n & 1) > 0) {
				res = (res * a) % mod;
			}
			a = (a * a) % mod;
			n/=2;
		}
		return res;
	}
	public static long inverse(long a,long mod) {
		long b = mod, u = 1, v = 0;
		while(b > 0) {
			long temp;
			long t = a / b;
			a -= t * b;
			temp = a; a = b; b = temp;
			u -= t * v;
			temp = u; u = v; v = temp;
		}
		return (u % mod + mod) % mod;
	}
	public static long[] inverseArray(int maxN,long modP) {
		long[] inv = new long[maxN+1];
		inv[1] = 1;
		for(int i=2;i<=maxN;i++) {
			inv[i] = modP - (modP / i) * inv[(int) (modP%i)] % modP;
		}
		return inv;
	}
	public static long[] factorialArray(int maxN,long mod) {
		long[] fact = new long[maxN+1];
		fact[0] = 1 % mod;
		for(int i=1;i<=maxN;i++) {
			fact[i] = fact[i-1] * i % mod;
		}
		return fact;
	}
	public static long[] factorialInverseArray(int maxN,long modP,long[] inverseArray) {
		long[] factInv = new long[maxN+1];
		factInv[0] = 1;
		for(int i=1;i<=maxN;i++) {
			factInv[i] = factInv[i-1] * inverseArray[i] % modP;
		}
		return factInv;
	}
	public static long[][] combinationArray(int maxN,int maxR,long mod) {
		long[][] c = new long[maxN+1][maxR+1];
		for(int i=0;i<=maxN;i++) {
			c[i][0] = 1;
			c[i][i] = 1;
		}
		for(int i=1;i<=maxN;i++) {
			for(int j=1;j<=i-1;j++) {
				c[i][j] = c[i-1][j-1] + c[i-1][j];
				if (c[i][j] >= mod) {
					c[i][j] -= mod;
				}
			}
		}
		return c;
	}
}

class IO extends PrintWriter {
	private final InputStream in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	public IO() {
		this(System.in);
	}

	public IO(InputStream source) {
		super(System.out);
		this.in = source;
	}

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				buflen = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen <= 0) {
				return false;
			}
		}
		return true;
	}

	private int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	private static boolean isNewLine(int c) {
		return c == '\n' || c == '\r';
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
		return hasNextByte();
	}

	public boolean hasNextLine() {
		while (hasNextByte() && isNewLine(buffer[ptr]))
			ptr++;
		return hasNextByte();
	}

	public String next() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public char[] nextCharArray(int len) {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		char[] s = new char[len];
		int i = 0;
		int b = readByte();
		while (isPrintableChar(b)) {
			if (i == len) {
				throw new InputMismatchException();
			}
			s[i++] = (char) b;
			b = readByte();
		}
		return s;
	}

	public String nextLine() {
		if (!hasNextLine()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (!isNewLine(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		long n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) {
			throw new NumberFormatException();
		}
		while (true) {
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			} else if (b == -1 || !isPrintableChar(b)) {
				return minus ? -n : n;
			} else {
				throw new NumberFormatException();
			}
			b = readByte();
		}
	}

	public int nextInt() {
		long nl = nextLong();
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
			throw new NumberFormatException();
		}
		return (int) nl;
	}

	public char nextChar() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		return (char) readByte();
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

	public double[] nextDoubleArray(int n) {
		double[] a = new double[n];
		for (int i = 0; i < n; i++)
			a[i] = nextDouble();
		return a;
	}

	public void nextIntArrays(int[]... a) {
		for (int i = 0; i < a[0].length; i++)
			for (int j = 0; j < a.length; j++)
				a[j][i] = nextInt();
	}

	public int[][] nextIntMatrix(int n, int m) {
		int[][] a = new int[n][];
		for (int i = 0; i < n; i++)
			a[i] = nextIntArray(m);
		return a;
	}

	public char[][] nextCharMap(int n, int m) {
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++)
			a[i] = nextCharArray(m);
		return a;
	}

	public void close() {
		super.close();
		try {
			in.close();
		} catch (IOException e) {
		}
	}
}
