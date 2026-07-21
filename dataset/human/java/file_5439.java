import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		if(n <1200) out.println("ABC");
		else out.println("ARC");
		//for (int i = 1 ; i <= m; i++) {
		//	out.println(ans[i]);
		//}
		out.flush();
	}

	// ----------------------

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int next() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public char nextChar() {
			int c = next();
			while (isSpaceChar(c))
				c = next();
			if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
				return (char) c;
			}
			throw new InputMismatchException();
		}

		public String nextToken() {
			int c = next();
			while (isSpaceChar(c))
				c = next();
			StringBuilder res = new StringBuilder();
			do {
				res.append((char) c);
				c = next();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public int nextInt() {
			int c = next();
			while (isSpaceChar(c))
				c = next();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = next();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c-'0';
				c = next();
			} while (!isSpaceChar(c));
			return res*sgn;
		}

		public long nextLong() {
			int c = next();
			while (isSpaceChar(c))
				c = next();
			long sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = next();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c-'0';
				c = next();
			} while (!isSpaceChar(c));
			return res*sgn;
		}

		public double nextDouble() {
			return Double.valueOf(nextToken());
		}

		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		//public interface SpaceCharFilter {
		//	public boolean isSpaceChar(int ch);
		//}
	}
	// template
	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r);  }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r);  }

	static <T> void swap(T[] x, int i, int j) { T t = x[i]; x[i] = x[j]; x[j] = t;  }
	static void swap(int[] x, int i, int j) { int t = x[i]; x[i] = x[j]; x[j] = t;  }
}
