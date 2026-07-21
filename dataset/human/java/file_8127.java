import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {

		long mod=1000*1000*1000+7;
		
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);

		long A=sc.nextLong();
		long B=sc.nextLong();
		
		out.print(lcm(A,B));
		
		out.flush();
	}
	
	static long lcm (long a, long b) {
		long temp;
		long c = a;
		c *= b;
		while((temp = a%b)!=0) {
			a = b;
			b = temp;
		}
		return (long)(c/b);
	}
	
}

class FastScanner {
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

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
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
		long nl = nextLong();
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
			throw new NumberFormatException();
		return (int) nl;
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public int[] nextIntsN(int N) {
		int[] ints = new int[N];
		for (int i = 0; i < N; i++) {
			ints[i] = nextInt();
		}
		return ints;
	}

	public long[] nextLongsN(int N) {
		long[] longs = new long[N];
		for (int i = 0; i < N; i++) {
			longs[i] = nextLong();
		}
		return longs;
	}

	public char[] nextCharsN(int N) {
		char[] chars = new char[N];
		String msg = next();
		for (int i = 0; i < N; i++) {
			chars[i] = msg.charAt(i);
		}
		return chars;
	}

	public char[][] nextCharsHW(int H, int W) {
		char[][] chars = new char[H][W];
		for (int i = 0; i < H; i++) {
			String str = next();
			for (int j = 0; j < W; j++) {
				chars[i][j] = str.charAt(j);
			}
		}
		return chars;
	}

	public int[][] nextIntsNM(int N, int M) {
		int[][] ints = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				ints[i][j] = nextInt();
			}
		}
		return ints;
	}

	public List<Integer> nextArrayIntsN(int N) {
		ArrayList<Integer> array = new ArrayList<>(N);
		for (int i = 0; i < N; i++) {
			array.add(nextInt());
		}
		return array;
	}

	public List<Long> nextArrayLongsN(int N) {
		ArrayList<Long> array = new ArrayList<>(N);
		for (int i = 0; i < N; i++) {
			array.add(nextLong());
		}
		return array;
	}

	public List<List<Long>> nextArrayLongsNM(int N, int M) {

		List<List<Long>> arrays = new ArrayList<List<Long>>(M);
		for (int i = 0; i < M; i++) {
			List<Long> array = nextArrayLongsN(N);
			arrays.add(array);
		}
		return arrays;
	}

}
