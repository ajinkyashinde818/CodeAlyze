import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;

 class Main {

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
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
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	public static void main(String[] args) {
		FastReader sc = new FastReader();
		String ss=sc.next();
		int a=0,b=0,c=0;
		if(ss.charAt(0)=='a'||ss.charAt(1)=='a'||ss.charAt(2)=='a')a++;
		if(ss.charAt(0)=='b'||ss.charAt(1)=='b'||ss.charAt(2)=='b')b++;
		if(ss.charAt(0)=='c'||ss.charAt(1)=='c'||ss.charAt(2)=='c')c++;
		System.out.println(a==1 && b==1 && c==1?"Yes":"No");
	}

}
