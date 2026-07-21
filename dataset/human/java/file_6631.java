import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);

		char[] s = sc.next().toCharArray();
		int x = sc.nextInt();
		int y = sc.nextInt();

		int i = 0;
		for (i = 0; i < s.length; i++) {
			if (s[i] != 'F') break;
			x--;
		}

		ArrayList<Integer> xs = new ArrayList<>(), ys = new ArrayList<>();
		int tmp = 0, dir = 0;
		for (; i < s.length; i++) {
			switch (s[i]) {
				case 'F':
					tmp++;
					break;
				case 'T':
					if (tmp > 0) {
						if (dir == 0) xs.add(tmp);
						else ys.add(tmp);
					}
					dir = (dir + 1) % 2;
					tmp = 0;
					break;
			}
		}
		if (dir == 0) xs.add(tmp);
		else ys.add(tmp);

		Collections.sort(xs);
		Collections.sort(ys);

		HashSet<Integer> setX = new HashSet<>();
		setX.add(0);
		for (int dx : xs) {
			HashSet<Integer> tmpS = new HashSet<>();
			for (int xx : setX) {
				tmpS.add(xx + dx);
				tmpS.add(xx - dx);
			}
			setX = tmpS;
		}
		HashSet<Integer> setY = new HashSet<>();
		setY.add(0);
		for (int dy : ys) {
			HashSet<Integer> tmpS = new HashSet<>();
			for (int yy : setY) {
				tmpS.add(yy + dy);
				tmpS.add(yy - dy);
			}
			setY = tmpS;
		}

		out.println(setX.contains(x) && setY.contains(y) ? "Yes" : "No");
		out.flush();
	}

}

class FastScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (ptr < buflen) return true;
		else {
			ptr = 0;
			try {
				buflen = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen <= 0) return false;
		}
		return true;
	}

	private byte readByte() {
		if (hasNextByte()) return buffer[ptr++];
		return -1;
	}

	private boolean isPrintableChar(byte c) {
		return '!' <= c && c <= '~';
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
			ptr++;
		}
	}

	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}

	public String next() {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		byte b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public int nextInt() {
		if (!hasNext()) throw new NoSuchElementException();
		int n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) throw new NumberFormatException();
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

	public int[] nextIntArray(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		return a;
	}

	public long nextLong() {
		if (!hasNext()) throw new NoSuchElementException();
		long n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) throw new NumberFormatException();
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

	public long[] nextLongArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		return a;
	}
}
