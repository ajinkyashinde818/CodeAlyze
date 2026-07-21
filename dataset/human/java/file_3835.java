import java.util.*;
import java.io.*;

public class Main {

	void solve() {
		String s = "A" + in.nextToken() + "A";
		StringBuilder wox = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != 'x') {
				wox.append(s.charAt(i));
			}
		}

		if (!wox.toString().equals(wox.reverse().toString())) {
			out.println(-1);
			return;
		}
		List<Integer> cnt = new ArrayList<>();
		for (int i = 1; i < s.length();) {
			int j = i;
			while (s.charAt(j) == 'x') {
				j++;
			}
			cnt.add(j - i);
			i = j + 1;
		}
		int result = 0;
		for (int i = 0; i < cnt.size() / 2; i++) {
			result += Math.abs(cnt.get(i) - cnt.get(cnt.size() - i - 1));
		}
		out.println(result);
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
