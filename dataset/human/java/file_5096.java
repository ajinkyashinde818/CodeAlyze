import java.io.*;
import java.util.*;

public class Main {
	static PrintWriter out;
	static StringBuilder sb;
	static long mod = 998244353;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
		String s = sc.nextLine();
		Stack<Character> st = new Stack<>();
		Stack<Character> en = new Stack<>();
		boolean rev = false;
		int q = sc.nextInt();
		while (q-- > 0) {
			int x = sc.nextInt();
			if (x == 1)
				rev = !rev;
			else {
				int f = sc.nextInt();
				char c = sc.nextChar();
				if (f == 1) {
					if (rev) {
						en.push(c);
					} else {
						st.push(c);
					}
				} else {
					if (rev) {
						st.push(c);
					} else {
						en.push(c);
					}
				}
			}
		//	System.out.println(rev+" "+st+" "+en);
		}
		if (rev) {
			sb=new StringBuilder();
			while (!en.isEmpty())
				out.print(en.pop());
			out.print(sb.append(s).reverse());
			for(char k: st)
				out.print(k);
		} else {
			while (!st.isEmpty())
				out.print(st.pop());
			out.print(s);
			for(char k: en)
				out.print(k);
		}
		out.flush();
	}

	static long modPow(long a, long e)

	{
		long res = 1;
		while (e > 0) {
			if ((e & 1) == 1)
				res = (res * a) % mod;
			a = (a * a) % mod;
			e >>= 1;
		}
		return res;
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}
