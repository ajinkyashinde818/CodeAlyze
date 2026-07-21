import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Indrajit Sinha
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		CSubarraySum solver = new CSubarraySum();
		solver.solve(1, in, out);
		out.close();
	}

	static class CSubarraySum {
		PrintWriter out;
		InputReader in;

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int t, i, j, tt, k;
			this.out = out;
			this.in = in;
			int n = in.nextInt();
			k = in.nextInt();
			int s = in.nextInt();
			int x = s + 1;
			if (x > 1000000000)
				x = s - 1;
			int a[] = new int[n];
			for (i = 0; i < k; i++) {
				a[i] = s;
			}
			for (i = k; i < n; i++) {
				a[i] = x;
			}
			for (i = 0; i < n; i++) {
				p(a[i]);
			}
			pn("");
		}

		void pn(String zx) {
			out.println(zx);
		}

		void p(int zx) {
			out.print(zx + " ");
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1) {
				throw new UnknownError();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new UnknownError();
				}
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public String next() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));

			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}
