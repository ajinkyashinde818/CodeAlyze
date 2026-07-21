import java.util.*;
import java.io.*;
import java.text.*;

public class Main {

	public static int solve(int[] a, int[] b, int k) {
		int[] tempa = a.clone();
		for (int i = 0; i < tempa.length; i++) {
			tempa[i] %= 1 << (k + 1);
		}
		int[] tempb = b.clone();
		for (int i = 0; i < tempa.length; i++) {
			tempb[i] %= 1 << (k + 1);
		}
		Arrays.sort(tempb);
		int cnt = 0;
		for (int i = 0; i < tempa.length; i++) {
			int lowerb = (1 << k) - tempa[i];
			int upperb = (1 << (k + 1)) - tempa[i] - 1;
			int lb = bsLow(tempb, lowerb);
			int ub = bsHigh(tempb, upperb);
			if (lb <= ub)
				cnt += Math.max(ub - lb + 1, 0);
//			if(k==2)System.out.println(cnt+ " "+lb+" "+ub);
			lowerb = 3 * (1 << k) - tempa[i];
			upperb = (1 << (k + 2)) - tempa[i] - 1;
			lb = bsLow(tempb, lowerb);
			ub = bsHigh(tempb, upperb);
			if (lb <= ub)
				cnt += Math.max(ub - lb + 1, 0);
//			if(k==2)
//				System.out.println(cnt+" "+lb+" "+ub);
		}
		
		return (cnt & 1) << k;
	}

	public static int bsLow(int[] a, int key) {
		int lo = 0;
		int hi = a.length - 1;
		int ans = a.length;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (a[mid] >= key) {
				ans = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		return ans;
	}

	public static int bsHigh(int[] a, int key) {
		int lo = 0;
		int hi = a.length - 1;
		int ans = -1;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (a[mid] <= key) {
				ans = mid;
				lo = mid + 1;
			} else
				hi = mid - 1;
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < b.length; i++) {
			a[i] = sc.nextInt();
		}
		for (int i = 0; i < b.length; i++) {
			b[i] = sc.nextInt();
		}
		int ans = 0;
		for (int i = 0; i < 29; i++) {
			ans |= solve(a, b, i);
		}
		pw.println(ans);
		pw.close();

	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public int[] nextIntArr(int n) throws IOException {
			int[] arr = new int[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextInt();
			return arr;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}
}
