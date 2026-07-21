import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	int n;
	int[] a;
	
	void submit() {
		n = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		boolean ans1 = true;
		for (int i = 0; i < n - 1; i++) {
			ans1 &= a[i] < a[i + 1];
		}
		if (ans1) {
			out.println(1);
			return;
		}
		
		int low = 1; // not enough
		int high = n; // enough
		
		now = new Block[2 * n];
		
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (enough(mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		
		out.println(high);
		
	}
	
	static class Block {
		int val, rep;

		public Block(int val, int rep) {
			this.val = val;
			this.rep = rep;
		}
	}
	
	Block[] now;
	int nowSz;
	
	boolean enough(int s) {
		nowSz = 0;
		now[nowSz++] = new Block(0, a[0]);
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				if (last().val == 0) {
					last().rep += a[i] - a[i - 1];
				} else {
					now[nowSz++] = new Block(0, a[i] - a[i - 1]);
				}
				continue;
			}
			
			cutTail(a[i - 1] - a[i]);
			
			int remember = 0;
			while (nowSz > 0 && last().val == s - 1) {
				remember++;
				nowSz--;
			}
			if (nowSz == 0) {
				return false;
			}
			if (last().rep > 1) {
				last().rep -= 1;
				now[nowSz++] = new Block(0, 1);
			}
			last().val++;
			now[nowSz++] = new Block(0, remember);
		}
		return true;
	}
	
	void cutTail(int reps) {
		while (true) {
			if (last().rep <= reps) {
				reps -= last().rep;
				nowSz--;
			} else {
				last().rep -= reps;
				return;
			}
		}
	}
	
	Block last() {
		return now[nowSz - 1];
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	Main() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}
