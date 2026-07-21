import java.util.*;
	
	
	import java.io.*;
	
	public class Main {
	
		static int n;
		static long memo[][];
		static int p;
		static int pl[][];
		static pair[] a;
		static int k;
	
		public static long dp(int msk, int idx) {
			if (idx == n)
				return 0;
			if (memo[msk][idx] != -1)
				return memo[msk][idx];
			long max = k - (idx - Integer.bitCount(msk)) > 0 ? dp(msk, idx + 1) + a[idx].x : dp(msk, idx + 1);
	
			for (int i = 0; i < p; i++) {
				if (((msk >> i) & 1) == 0) {
					max = Math.max(max, pl[a[idx].y][i] + dp(msk | 1 << i, idx + 1));
				}
			}
			return memo[msk][idx] = max;
	
		}
	
		public static void main(String[] args) throws NumberFormatException, IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			PrintWriter pw = new PrintWriter(System.out);
			String s = br.readLine();
			int n = Integer.parseInt(br.readLine());
			int a[] = new int[n + 1];
			String[] b = new String[n];
			for (int i = 0; i < n; i++) {
				String w = br.readLine();
				int x = w.length();
				if (x == 1) {
					a[i + 1]++;
				}
				b[i] = w;
			}
			a[n] = a[n] % 2;
			for (int i = n - 1; i >= 0; i--) {
				a[i] += a[i + 1];
				a[i] = a[i] % 2;
			}
			if (a[0] == 1)
				s = new StringBuilder(s).reverse().toString();
			StringBuilder sb = new StringBuilder(s);
			Stack<String> v = new Stack<>();
			for (int i = 0; i < b.length; i++) {
				if (b[i].length() == 1)
					continue;
				int t = Integer.parseInt(b[i].charAt(0) + "");
				int w = (Integer.parseInt(b[i].charAt(2) + "") + a[i + 1]) % 2;
				String r = b[i].charAt(4) + "";
				if (w == 0)
					sb.append(r);
				else
					v.add(r);
			}
			while (!v.isEmpty())
				System.out.print(v.pop());
			System.out.println(sb.toString());
		}
	
		static int gcd(int a, int b) {
			if (b == 0)
				return a;
			return gcd(b, a % b);
		}
	
		static class pair {
			int x;
			int y;
	
			pair(int r, int t) {
				x = r;
				y = t;
			}
	
			public String toString() {
				return "(" + x + "," + y + ")";
			}
	
		}
	}
