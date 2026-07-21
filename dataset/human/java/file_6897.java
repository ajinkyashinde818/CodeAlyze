import static java.lang.System.*;

import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {

	public void solve() {
		int K = nextInt();
		int N = nextInt();
		int[] A = new int[N];
		int max = 0;

		for(int i=0;i<N;i++) {
			A[i] = nextInt();
		}

		for(int i=0;i<N;i++) {
			int len = A[i]-A[(i-1+N)%N];
			len = (len+K)%K;
			max = max(max,len);
		}
		out.println(K-max);
	}

	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

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

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
	}

	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
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
		return (int) nextLong();
	}

	public int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	long lcm(long a, long b) {
		return a * b / gcd(a, b);
	}

	double sqrt(double x) {
		return Math.sqrt(x);
	}

	double pow(double x, double y) {
		return Math.pow(x, y);
	}
	int max(int a,int b) {
		return Math.max(a, b);
	}

	public static void main(String[] args) {
		Main m = new Main();

		m.solve();
	}

	public void println(Object o) {
		out.println(o);
	}

}
