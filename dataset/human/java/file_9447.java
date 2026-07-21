import java.util.*;
import java.io.*;

public class Main {
	static FastReader f = new FastReader();
	static PrintWriter out = new PrintWriter(System.out);
	

	public static void main(String[] args) {
		//int t = f.nextInt();
		//while(t-- > 0)
			solve();
		out.close();
	}

	static void solve() {
		int n = f.nextInt();
		int max = 0, cur = 0;
		while(n-- > 0) {
			int a = f.nextInt(), b = f.nextInt();
			if(a == b) {
				cur++;
			} else {
				cur = 0;
			}
			max = Math.max(cur, max);
		}

		out.println(max >= 3 ? "Yes" : "No");
	}

	static class FastReader {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(IOException ioe) {
					ioe.printStackTrace();
				}
			}
			return st.nextToken();
		}

		String nextLine() {
			String s = "";
			try {
				s = br.readLine();
			} catch(IOException ioe) {
				ioe.printStackTrace();
			}

			return s;
		}

		int  nextInt() {
			return Integer.parseInt(next());
		}
	}
}
