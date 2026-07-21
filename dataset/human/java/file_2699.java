import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main implements Runnable { // クラス名はMain1

	PrintWriter out = new PrintWriter(System.out);
	InputReader sc = new InputReader(System.in);
	static int mod = (int) (1e9 + 7); //10^9+7
	int[] dx = { 1, 0, -1, 0 }, dy = { 0, 1, 0, -1 }; //4 directions

	public static void main(String[] args) {
		Thread.setDefaultUncaughtExceptionHandler((t, e) -> System.exit(1));
		new Thread(null, new Main(), "", 1024 * 1024 * 1024).start(); // 16MBスタックを確保して実行
	}

	public void run() {
		//自力で解けた(1回WA,20分かかった。)
		/* 正式回答も追加
		 */
		try {
			String s = sc.next().trim();
			String t = sc.next().trim();
			Character[] sc = new Character[s.length()];
			Character[] tc = new Character[t.length()];
			for (int i = 0; i < s.length(); i++) {
				sc[i] = s.charAt(i);
			}

			for (int i = 0; i < t.length(); i++) {
				tc[i] = t.charAt(i);
			}

			Arrays.sort(sc);
			Arrays.sort(tc, Collections.reverseOrder());

			String snext = "";
			for (int i = 0; i < s.length(); i++) {
				snext += sc[i];
			}
			String tnext = "";
			for (int i = 0; i < t.length(); i++) {
				tnext += tc[i];
			}
			int ans = snext.compareTo(tnext);
			if (ans < 0) {
				out.println("Yes");
			} else {
				out.println("No");
			}

		} catch (ArithmeticException ae) {
			//ae.printStackTrace();
			throw new RuntimeException();
		} catch (Exception e) {
			//e.printStackTrace();
			throw new RuntimeException();
		} finally {
			out.flush();
			out.close();
		}

		/* これが独自回答
		try {
			String s = sc.next().trim();
			String t = sc.next().trim();
			int[] cnts = new int[26];
			int[] cntt = new int[26];
			for (int i = 0; i < s.length(); i++) {
				int sc = s.charAt(i) - 97;
				cnts[sc]++;
			}
		
			for (int i = 0; i < t.length(); i++) {
				int tc = t.charAt(i) - 97;
				cntt[tc]++;
			}
			boolean ans = false;
			boolean sb = false;
			for (int i = 0; i < 26; i++) {
				char c = (char) (i + 97);
				//out.println(c + " " + cnts[i] + " " + cntt[i]);
		
				if (sb && cntt[i] >= 1) {
					ans = true;
				}
		
				if (!sb && cnts[i] >= 1) {
					sb = true;
					boolean next = true;
					if (cnts[i] < cntt[i]) {
						for (int j = i + 1; j < 26; j++) {
							if (cnts[j] != 0) {
								next = false;
							}
						}
						if (next) {
							ans = true;
						}
					}
				}
			}
			if (ans) {
				out.println("Yes");
			} else {
				out.println("No");
			}
		
		} catch (ArithmeticException ae) {
			//ae.printStackTrace();
			throw new RuntimeException();
		} catch (Exception e) {
			//e.printStackTrace();
			throw new RuntimeException();
		} finally {
			out.flush();
			out.close();
		}
		*/

	}

	class Info implements Comparable<Info> {
		public long a;
		public long b;

		public Info(long a, long b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Info o) {
			//return this.a - o.a;//昇順
			// return o.a - this.a;//降順
			//複数項目で並び替え。aの降順、aが同じならbの降順
			if (this.a == o.a) {
				return Long.compare(o.b, this.b);
			} else {
				return Long.compare(o.a, this.a);
			}
		}
	}

	//Arrays.sort(Sample,new Comp());
	class Comp implements Comparator<Info> {
		public int compare(Info be, Info af) {
			return Long.compare(af.a, be.a);
		}
	}

	/**
	 *
	 * @param n
	 * @param m
	 * @return Combinationの数を返す(mod無しなので、大きい値には使用できない桁溢れする)
	 */
	long calcCombination(int n, int m) {
		if (n < m || m < 0) {
			throw new IllegalArgumentException("引数の値が不正です ( n : " + n + ", m : " + m + ")");
		}
		long c = 1;
		m = (n - m < m ? n - m : m);
		for (int ns = n - m + 1, ms = 1; ms <= m; ns++, ms++) {
			c *= ns;
			c /= ms;
		}
		return c;
	}

	/*
	 * 使用するときはModに注意。Global変数を参照
	 */
	public static long comb(long a, long b) {
		if (a < b)
			return 0;
		long res = 1;
		long inv = pow(fact(Math.min(b, a - b)), mod - 2);
		for (long i = a; i > a - Math.min(b, a - b); i--) {
			res *= i;
			res %= mod;
		}
		res *= inv;
		res %= mod;
		return res;
	}

	public static long pow(long x, long n) {
		long res = 1;
		while (n > 0) {
			if ((n & 1) == 1) {
				res *= x;
				res %= mod;
			}
			x *= x;
			x %= mod;
			n >>= 1;
		}
		return res;
	}

	public static long fact(long n) {
		long res = 1;
		while (n > 0) {
			res *= n;
			res %= mod;
			n--;
		}
		return res;
	}

	// 高速なScanner
	static class InputReader {
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}
