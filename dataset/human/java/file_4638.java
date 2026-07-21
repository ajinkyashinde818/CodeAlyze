import java.awt.Point;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	InputStream is;

	boolean __FILE_DEBUG_FLAG__ = false;
	String __DEBUG_FILE_NAME__ = "src/T";

	FastScanner in;
	PrintWriter out;
	
	boolean isAdjacentToZero;
	int[] vx = {-1, -1, 1, 1, -2, 2};
	int[] vy = {-1, 1, -1, 1, 0, 0};
	boolean[][] vis;
	
	boolean inside(int x, int y, int M, int N) {
		return x >= 0 && y >= 0 && x < M && y < N;
	}
	
	int dfs(int[][] board, int y, int x, int id) {
		vis[y][x] = true;
//		System.out.println("dfs : " + y + " " + x);
		int size = board.length;
		int res = 0;
		for (int d = 0; d < vx.length; d++) {
			int nx = x + vx[d], ny = y + vy[d];
			if (inside(nx, ny, size, size) && !vis[ny][nx] && board[ny][nx] != -1) {
				if (board[ny][nx] == 0) isAdjacentToZero = true;
				if (board[ny][nx] != id) continue;
				
				int val = dfs(board, ny, nx, id);
				res += val;
			}
		}
		return res + 1;
	}
	
	int simulate(int[][] _board, int minusId) {
		int size = _board.length;
		int center = size / 2;
		int[][] board = new int[size][];
		for (int i = 0; i < size; i++) {
			board[i] = Arrays.copyOf(_board[i], size);
		}
		
		int res = 0;
		vis = new boolean[size][size];
//		mapDebug(board);
		for (int i = 0; i < center; i++) {
			for (int j = center - i; j <= center + i; j += 2) {
				if (vis[i][j] || board[i][j] == 0) continue;
				
				isAdjacentToZero = false;
				int val = dfs(board, i, j, board[i][j]);
				if (!isAdjacentToZero) {
					res += board[i][j] == minusId ? -val : val;
//					System.out.println("add : " + i + " " + j + " " + val + " " + res);
				}
			}
		}

//		System.out.println("result : " + res);
		return res;
	}
	
	public void solve() {	
		while (true) {
			int N = in.nextInt();
			int C = in.nextInt();
			if (N == 0) break;
			
			int size = N * 2 + 1;
			int center = N;
			
			int[][] board = new int[size][size];
			for (int i = 0; i < size; i++) {
				Arrays.fill(board[i], -1);
			}
			
			for (int i = 0; i < N; i++) {
				for (int j = center - i; j <= center + i; j += 2) {
					board[i][j] = in.nextInt();
				}
			}
			
			int res = Integer.MIN_VALUE;
			for (int i = 0; i < N; i++) {
				for (int j = center - i; j <= center + i; j += 2) {
					if (board[i][j] != 0) continue;
					
					board[i][j] = C;
					res = Math.max(res, simulate(board, C));
					board[i][j] = 0;
				}
			}
			System.out.println(res);
		}
		
	}

	
	public void run() {
		if (__FILE_DEBUG_FLAG__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			System.out.println("FILE_INPUT!!");
		} else {
			is = System.in;
		}
		in = new FastScanner(is);
		out = new PrintWriter(System.out);

		solve();
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

		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
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

		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
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

		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
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
