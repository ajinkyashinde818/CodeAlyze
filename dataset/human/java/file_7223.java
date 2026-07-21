import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int[] deg;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int k=fs.nextInt(), n=fs.nextInt();
		int[] a=fs.readArray(n);
		int max=0;
		Arrays.sort(a);
		for (int i=0; i<n; i++) {
			int i2=(i+1)%n;
			int cur=a[i], next=a[i2];
			if (next<cur) {
				next+=k;
			}
			max=Math.max(max, next-cur);
		}
		System.out.println(k-max);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
}
