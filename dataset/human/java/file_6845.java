/*
 *created by Kraken on 28-03-2020 at 17:05
 */
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		FastReader sc = new FastReader();
		int k = sc.nextInt(), n = sc.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; i++) x[i] = sc.nextInt();
		long maxdiff = (k - x[n - 1]) + x[0];
		for (int i = 1; i < n; i++) maxdiff = Math.max(maxdiff, x[i] - x[i - 1]);
		System.out.println(k - maxdiff);
	}

	static class FastReader {

		BufferedReader br;

		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				}
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}
