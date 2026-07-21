import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		FastScanner in = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		char[] a = in.next().toCharArray();
		Arrays.sort(a);
		System.out.println((a[0] == 'a' && a[1] == 'b' && a[2] == 'c') ? "Yes" : "No");
	}

	static class Query {
		int i, l, x;

		public Query(int ii, int ll, int xx) {
			i = ii;
			l = ll;
			x = xx;
		}
	}

	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(InputStream i) {
			br = new BufferedReader(new InputStreamReader(i));
			st = new StringTokenizer("");
		}

		public String next() throws IOException {
			if (st.hasMoreTokens())
				return st.nextToken();
			else
				st = new StringTokenizer(br.readLine());
			return next();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
}
