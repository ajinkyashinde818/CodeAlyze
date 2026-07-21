import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		if (N == 1) {
			System.out.println("Yes");
			System.out.println(2);
			System.out.println(1 + " " + 1);
			System.out.println(1 + " " + 1);
			return;
		}
		int p = ok(N);
		if (p == -1) {
			System.out.println("No");
			return;
		}
		System.out.println("Yes");

		PrintWriter pw = new PrintWriter(System.out);
		ArrayList<Integer>[] s = new ArrayList[p];
		for (int i = 0; i < p; ++i) {
			s[i] = new ArrayList<>();
		}
		int cur = 1;
		for (int i = 0; i < p; ++i) {
			for (int j = i + 1; j < p; ++j) {
				s[i].add(cur);
				s[j].add(cur);
				++cur;
			}
		}
		if (cur - 1 != N)
			throw new AssertionError();
		System.out.println(p);
		for (int i = 0; i < p; ++i) {
			System.out.print(s[i].size() + " ");
			for (int j = 0; j < s[i].size(); ++j) {
				System.out.print(s[i].get(j) + (j == s[i].size() - 1 ? "\n" : " "));
			}
		}
		System.out.println();
		pw.close();
	}

	int ok(int N) {
		for (long i = 2; i <= 100000; ++i) {
			if (i * (i - 1) == 2 * N) {
				return (int) i;
			}
		}
		return -1;
	}

	static class Scanner {
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

		private boolean isPrintableChar(int c) {
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
	}

	public static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}
