import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * AtCoder Beginner Contest 104 C "All Green"
 *   https://abc104.contest.atcoder.jp/tasks/abc104_c/
 */
public class Main {

	public static void main(String[] args) {

		InputScanner in = new InputScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		Task task = new Task();
		task.run(in, out);

		in.close();
		out.close();
	}

	static class Task {

		public void run(InputScanner in, PrintWriter out) {

			int D = in.nextInt();
			int G = in.nextInt();

			int[] p = new int[D];
			int[] c = new int[D];
			int[] sum = new int[D];
			for (int i = 0; i < D; i++) {
				p[i] = in.nextInt();
				c[i] = in.nextInt();
				sum[i] = 100 * (i + 1) * p[i] + c[i];
			}

			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < Math.pow(2, D); i++) {

				int currentG = G;
				int count = 0;

				boolean[] isUsed = getUseComplete(i, D);
				for (int j = 0; j < D; j++) {
					if (isUsed[j]) {
						currentG -= sum[j];
						count += p[j];
					}
				}

				for (int j = D - 1; j >= 0; j--) {
					if (currentG <= 0) {
						break;
					}
					if (!isUsed[j]) {
						if (currentG >= 100 * (j + 1) * (p[j] - 1)) {
							currentG -= 100 * (j + 1) * (p[j] - 1);
							count += p[j] - 1;
						} else {
							int addCount = currentG / (100 * (j + 1));
							if (currentG % (100 * (j + 1)) != 0) {
								addCount++;
							}
							currentG -= 100 * (j + 1) * addCount;
							count += addCount;
							break;
						}
					}
				}

				if (currentG <= 0) {
					ans = Math.min(ans, count);
				}
			}


			out.println(ans);
		}
	}

	static boolean[] getUseComplete(int i, int D) {

		int index = i;
		boolean[] isUsed = new boolean[D];

		for (int j = 0; j < D; j++) {
			isUsed[j] = index % 2 == 1 ? true : false;
			index /= 2;
		}

		return isUsed;
	}

	/*
	 * extends java.util.Scanner
	 */
	static class InputScanner {

		Scanner scanner;

		public InputScanner(InputStream inputStream) {
			this.scanner = new Scanner(inputStream);
		}

		public boolean hasNext() {
			return scanner.hasNext();
		}

		public int nextInt() {
			return Integer.parseInt(scanner.next());
		}

		public long nextLong() {
			return Long.parseLong(scanner.next());
		}

		public double nextDouble() {
			return Double.parseDouble(scanner.next());
		}
		public String next() {
			return scanner.next();
		}

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.nextInt();
			}
			return ret;
		}

		public int[][] nextIntArray(int h, int w) {
			int[][] ret = new int[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.nextInt();
				}
			}
			return ret;
		}

		public long[] nextLongArray(int n) {
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.nextLong();
			}
			return ret;
		}

		public long[][] nextlongArray(int h, int w) {
			long[][] ret = new long[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.nextLong();
				}
			}
			return ret;
		}

		public double[] nextDoubleArray(int n) {
			double[] ret = new double[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.nextDouble();
			}
			return ret;
		}

		public double[][] nextDoubleArray(int h, int w) {
			double[][] ret = new double[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.nextLong();
				}
			}
			return ret;
		}

		public String[] nextStringArray(int n) {
			String[] ret = new String[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.next();
			}
			return ret;
		}

		public String[] nextStringArray(String split) {
			String[] ret = scanner.next().split(split);
			return ret;
		}

		public String[][] nextStringArray(int h, int w) {
			String[][] ret = new String[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.next();
				}
			}
			return ret;
		}

		public String[][] nextStringArray(int h, String split) {
			String[][] ret = new String[h][];
			for (int i = 0; i < h; i++) {
				ret[i] = scanner.next().split(split);
			}
			return ret;
		}

		public void close() {
			scanner.close();
		}

	}

}
