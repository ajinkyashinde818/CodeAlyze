import java.lang.*;
import java.io.*;
import java.util.*;


public class Main {

	public static void main(String[] args) throws java.lang.Exception {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(in, out);
		out.close();
	}
}

class TaskA {
	public final static int maxn = 55;
	char[][] sa = new char[maxn][maxn];
	char[][] sb = new char[maxn][maxn];

	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt(), m = in.nextInt();
		boolean flag = false;

		for (int i=0; i<n; ++i) {
			String s = in.next();
			sa[i] = s.toCharArray();
		}

		for (int i=0; i<m; ++i) {
			String s = in.next();
			sb[i] = s.toCharArray();
		}

		for (int i=0; !flag&&i+m<=n; ++i) {
			for (int j=0; !flag&&j+m<=n; ++j) {
				boolean f = true;
				for (int ii=0; f&&ii<m; ++ii) {
					for (int jj=0; f&&jj<m; ++jj) {
						if (sa[i+ii][j+jj] != sb[ii][jj])
							f = false;
					}
				}
				flag |= f;
			}
		}

		out.println(flag ? "Yes":"No");
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;


	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer==null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
