import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		new Solution().solve(in, out);
		out.close();
	}

	static class Solution {
		private long nextLong(InputReader in) {
			return Long.parseLong(in.next());
		}
		
		public void solve(InputReader in, PrintWriter out) {
			long n = nextLong(in);
			long ans = 0;
			for (long v = 2; v < n; ++v) {
				if (v * v > n) {
					break;
				}
				long e = 0;
				while (n % v == 0) {
					n /= v;
					++e;
				}
				if (e > 0) {
					for (long k = 1; k < 10; ++k) {
						if (e >= k) {
							e -= k;
							ans += 1;
						} else break;
					}
				}
			}
			if (n > 1) ans+=1;
			out.println(ans);
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException();
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
