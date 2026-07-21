import java.io.*;
import java.util.*;

public class Main {
	FastScanner in = new FastScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	
	public void run() {
		while (true) {
			int n = in.nextInt();
			if (n == 0) break;
			
			char[][] str = new char[n][2000];
			for (int i = 0; i < n; i++) {
				String s = in.next();
				for (int j = 0; j < s.length(); j++) {
					str[i][j] = s.charAt(j);
				}
				if (i == 0) continue;
				
				for (int j = 0; j < str[i].length - 1; j++) {
					if ('a' <= str[i][j+1] && str[i][j+1] <= 'z') {
						str[i][j] = '+';
						break;
					} else {
						str[i][j] = ' ';
					}
				}
			}
			
			for (int i = 1; i < n; i++) {
				int p = 0;
				for (int j = 0; j < str[i].length; j++) {
					if (str[i][j] == '+') {
						p = j;
						break;
					}
				}
				
				int lower = -1;
				for (int ii = i + 1; ii < n; ii++) {
					if (str[ii][p] == 0 || ('a' <= str[ii][p] && str[ii][p] <= 'z')) {
						break;
					}
					if (str[ii][p] == '+') {
						lower = ii;
						break;
					}
				}
				
				if (lower != -1) {
					for (int k = i + 1; k < lower; k++) {
						str[k][p] = '|';
					}
				}
			}
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 2000; j++) {
					if (str[i][j] == 0) break;
					System.out.print(str[i][j]);
				}
				System.out.println();
			}
		}
		out.close();
	}

	public static void main(String[] args) {
		new Main().run();
	}

	public void mapDebug(int[][] a) {
		System.out.println("--------map display---------");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}

		System.out.println("----------------------------");
		System.out.println();
	}

	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			//stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
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

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();

			return array;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		long[] nextLongArray(int n) {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();

			return array;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		double[] nextDoubleArray(int n) {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();

			return array;
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();

			return array;
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
}
