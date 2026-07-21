// Submitted By Subhash Yadav
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) throws IOException {

		FastScanner sc = new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=sc.nextInt();
		boolean ok=false;
		int a[][]=new int[n][2];
		for(int i=0;i<n;i++) {
			a[i][0]=sc.nextInt();
			a[i][1]=sc.nextInt();
			if(i>1&&a[i][0]==a[i][1]&&a[i-1][0]==a[i-1][1]&&a[i-2][0]==a[i-2][1]) {
				ok=true;
			}
		}

		System.out.println(ok?"Yes":"No");
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}
