import java.io.IOException;
import java.util.InputMismatchException;

public class Main{
	void run() throws Exception{
		MyScanner sc = new MyScanner();
		//		System.setOut(new PrintStream(new File("output.txt")));

		while (true) {
			int n = sc.nextInt();
			if (n == 0) {
				break;
			}
			int max = 0;
			char[][] c = new char[n][];
			char[][] ans = new char[n][];
			for (int i = 0; i < n; i++) {
				c[i] = sc.next().toCharArray();
				ans[i] = new char[c[i].length];
				max = Math.max(max, c[i].length);
			}

			for (int j = 0; j < max; j++) {
				for (int i = 0; i < n; i++) {
					if (c[i].length <= j) continue;
					if (c[i][j] == '.') {
						ans[i][j] = ' ';
					} else {
						ans[i][j] = c[i][j];
					}
				}
			}

			for (int j = 0; j < max; j++) {
				for (int i = 0; i < n; i++) {
					if (c[i].length <= j) continue;
					if (ans[i][j] == ' ' && c[i][j + 1] != '.') {
						ans[i][j] = '+';
					}
				}
			}

			for (int j = 0; j < max; j++) {
				boolean f = false;
				for (int i = n - 1; 0 <= i; i--) {
					if (c[i].length <= j) continue;
					if (f) {
						if (ans[i][j] == ' ') {
							ans[i][j] = '|';
						} else {
							f = false;
						}
					}
					if (ans[i][j] == '+') {
						f = true;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < ans[i].length; j++) {
					System.out.print((char)ans[i][j]);
				}
				System.out.println();
			}
		}
	}

	public static void main(String[] args) throws Exception{
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
		System.out.println("----------------------------" + '\n');
	}

	class MyScanner {
		int read() {
			try {
				return System.in.read();
			} catch (IOException e) {
				throw new InputMismatchException();
			}
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
