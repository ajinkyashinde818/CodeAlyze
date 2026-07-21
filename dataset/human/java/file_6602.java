import java.util.*;
import java.io.*;

public class Main {

	int[] dx = new int[] { 1, 0, -1, 0 };
	int[] dy = new int[] { 0, 1, 0, -1 };

	void solve() {
		char[] c = in.nextToken().toCharArray();
		int x = in.nextInt(), y = in.nextInt();

		int dir = 0;
		int i = 0;
		while (i < c.length && c[i] == 'F') {
			i++;
			x--;
		}
		if (i == c.length) {
			if (x == 0 && y == 0) {
				out.println("Yes");
			} else {
				out.println("No");
			}
			return;
		}

		List<Integer> lensX = new ArrayList<>();
		List<Integer> lensY = new ArrayList<>();

		while (i < c.length) {
			// c[i] == 'T'
			dir = (dir + 1) % 4;
			i++;
			int len = 0;
			while (i < c.length && c[i] == 'F') {
				i++;
				len++;
			}
			
			if (dir % 2 == 1) {
				lensY.add(len);
			} else {
				lensX.add(len);
			}
		}
		
		out.println(can(x, lensX) && can(y, lensY) ? "Yes" : "No");
	}

	private boolean can(int x, List<Integer> lens) {
		int MAX = 10000;
		boolean[] dp = new boolean[2 * MAX + 1];
		boolean[] newDp = new boolean[2 * MAX + 1];
		dp[MAX] = true;
		for (int t : lens) {
			for (int i = 0; i < dp.length; i++) {
				if (!dp[i]) {
					continue;
				}
				if (i - t >= 0) {
					newDp[i - t] = true;
				}
				if (i + t >= 0) {
					newDp[i + t] = true;
				}
			}
			System.arraycopy(newDp, 0, dp, 0, dp.length);
			Arrays.fill(newDp, false);
		}
		
		return dp[MAX + x];
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
