import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		String s = sc.next();
		int q = sc.nextInt();
		int[] t = new int[q];
		int[] f = new int[q];
		String[] c = new String[q];
		for (int i = 0; i < q; i++) {
			if ((t[i] = sc.nextInt()) == 2) {
				f[i] = sc.nextInt();
				c[i] = sc.next();
			}
		}
		boolean isReversed = false;
		StringBuilder tail = new StringBuilder();
		StringBuilder head = new StringBuilder();
		for (int i = 0; i < q; i++) {
			if (t[i] == 1) {
				isReversed = !isReversed;
			} else {
				if (f[i] == 1) {
					if (!isReversed) {
						head.append(c[i]);
					} else {
						tail.append(c[i]);
					}
				} else {
					if (!isReversed) {
						tail.append(c[i]);
					} else {
						head.append(c[i]);
					}
				}
			}
		}
		if (!isReversed) {
			System.out.println(head.reverse().append(s).append(tail));
		} else {
			System.out.println(head.reverse().append(s).append(tail).reverse());
		}
	}
}

class FastScanner {
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
		if (hasNextByte()) {
			return buffer[ptr++];
		} else {
			return -1;
		}
	}
	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}
	public boolean hasNext() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
			ptr++;
		}
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
		if (nl < Integer.MIN_VALUE || Integer.MAX_VALUE < nl) {
			throw new NumberFormatException();
		}
		return (int) nl;
	}
	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
