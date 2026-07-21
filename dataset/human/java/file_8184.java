import java.io.*;
import java.util.*;
public class Main {
	public static class FS {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens()) {
				try { st = new StringTokenizer(br.readLine()); }
				catch (Exception e) {}
			} return st.nextToken();
		}
		int nextInt() { return Integer.parseInt(next()); }
		long nextLong() { return Long.parseLong(next()); }
	}

	public static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
	public static long lcm(long a, long b) { return a * b / gcd(a, b); }
	public static int abs(int x) { if (x < 0) return -x; return x; }

	public static void main(String[] args) {
		FS in = new FS();

		long a = in.nextLong();
		long b = in.nextLong();
	
		System.out.println(lcm(a, b));
	}
}
