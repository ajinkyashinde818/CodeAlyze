import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

class FastScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		}

		ptr = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}

		return buflen > 0;
	}

	private int readByte() {
		return hasNextByte() ? buffer[ptr++] : -1;
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
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
			throw new NumberFormatException();
		}
		return (int) nl;
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}

class UnionFind {

	private int[] root;
	private int[] connected;

	public UnionFind(int N) {
		root = new int[N];
		for (int i = 0; i < N; ++i) {
			root[i] = i;
		}

		connected = new int[N];
		Arrays.fill(connected, 1);
	}

	public int getRootOf(int x) {
		if (x == root[x]) {
			return x;
		}

		return root[x] = getRootOf(root[x]);
	}

	public int getConnectedCount(int x) {
		return connected[getRootOf(x)];
	}

	public boolean areConnected(int x, int y) {
		return getRootOf(x) == getRootOf(y);
	}

	public void unite(int x, int y) {
		int xRoot = getRootOf(x);
		int yRoot = getRootOf(y);
		if (areConnected(xRoot, yRoot)) {
			return;
		}

		if (connected[xRoot] <= connected[yRoot]) {
			root[xRoot] = yRoot;
			connected[yRoot] += connected[xRoot];
		} else {
			unite(y, x);
		}
	}
}

public class Main {

	static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		int n = sc.nextInt();
		UnionFind road = new UnionFind(n);
		UnionFind rail = new UnionFind(n);
		int k = sc.nextInt();
		int l = sc.nextInt();

		for (int i = 0; i < k + l; ++i) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			if (i < k) {
				road.unite(x, y);
			} else {
				rail.unite(x, y);
			}
		}

		Map<String, Integer> pairCounter = new HashMap<>();
		for (int i = 0; i < n; ++i) {
			String key = road.getRootOf(i) + ":" + rail.getRootOf(i);
			pairCounter.putIfAbsent(key, 0);
			pairCounter.put(key, pairCounter.get(key) + 1);
		}

		PrintWriter pw = new PrintWriter(System.out);
		for (int i = 0; i < n; ++i) {
			String key = road.getRootOf(i) + ":" + rail.getRootOf(i);
			pw.printf("%d%c", pairCounter.get(key), i < n - 1 ? ' ' : '\n');
		}
		pw.flush();
	}

}
