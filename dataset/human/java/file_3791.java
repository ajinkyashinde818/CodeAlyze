import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		String s = sc.nextToken();
		int N = s.length();

		int ans = 0;
		int l = 0;
		int r = N-1;
		while (l < r) {
			char a = s.charAt(l);
			char b = s.charAt(r);
			
			if (a == b) {
				l++;
				r--;
			} else if (a == 'x' && b != 'x') {
				ans++;
				l++;
			} else if (a != 'x' && b == 'x') {
				ans++;
				r--;
			} else {
				System.out.println(-1);
				return;
			}
		}
		
		System.out.println(ans);
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}
}
