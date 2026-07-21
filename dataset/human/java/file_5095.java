import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

	static long sx = 0, sy = 0, m = (long) (1e9 + 7);

	static ArrayList<Integer>[] a;
	static int[] dp;
	static long[] fa;
	static boolean b = true;
	static HashMap<Long, Integer> hm = new HashMap<>();
	// static ArrayList<Integer> p = new ArrayList<>();
	public static PrintWriter out;
	static ArrayList<pair> ans = new ArrayList<>();
	static int[] tan;
	static ArrayList<Integer>[] p;
	static StringBuilder sb = new StringBuilder();
	static boolean cycle = false;

	public static void main(String[] args) throws IOException {

		Scanner scn = new Scanner(System.in);

		LinkedList<Character> l = new LinkedList<>();

		String s = scn.next();

		for (char ch : s.toCharArray())
			l.add(ch);

		int q = scn.nextInt();
		int c = 0;

		while (q-- != 0) {

			int t = scn.nextInt();

			if (t == 1)
				c = 1 - c;

			else {

				int f = scn.nextInt();
				char ch = scn.next().charAt(0);

				if (f == 1) {

					if (c == 0)
						l.addFirst(ch);

					else
						l.add(ch);

				}

				else {
					if (c == 1)
						l.addFirst(ch);

					else
						l.add(ch);
				}
			}

		}
		StringBuilder sb = new StringBuilder();

		while (l.size() != 0)
			sb.append(l.removeFirst());

		if (c == 1)
			sb.reverse();

		System.out.println(sb);

	}

	// _________________________TEMPLATE_____________________________________________________________

	// private static int gcd(int a, int b) {
	// if (a == 0)
	// return b;
	//
	// return gcd(b % a, a);
	// }

	// static class comp implements Comparator<Integer> {
	//
	// @Override
	// public int compare(Integer o1, Integer o2) {
	//
	// return (int) (o2 - o1);
	// }
	//
	// }

	private static class pair implements Comparable<pair> {

		int a, b;

		pair(int c, int d) {

			a = c;
			b = d;
		}

		@Override
		public int compareTo(pair o) {

			return 1;
		}

	}

	public static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[1000000 + 1]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}

		public int[] nextIntArray(int n) throws IOException {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) throws IOException {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextLong();
			}
			return arr;
		}

		public int[][] nextInt2DArray(int m, int n) throws IOException {
			int[][] arr = new int[m][n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++)
					arr[i][j] = nextInt();
			}
			return arr;
		}
		// kickstart - Solution
		// atcoder - Main
	}

}
