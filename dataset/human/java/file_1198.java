import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static ArrayList<String> s = new ArrayList<String>();
	public static void main(String[] args) throws IOException {
		FastScanner in = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n= in.nextInt();
		long [] c= new long[n];
		c[0]= in.nextLong();
		for (int i = 1; i < c.length; i++) {
			c[i]= in.nextInt()+c[i-1];
		}
		long best= Long.MAX_VALUE;
		for (int i = 0; i < n-1; i++) {
			long x= c[i];
			long y= c[n-1]- c[i];
			long dif= Math.abs(x-y);
			best= Math.min(best, dif);
		}
		System.out.println(best);
		
	}
	public static void combinations(String suffix,String prefix){
        if(prefix.length()<0)return;
        s.add(suffix);
        for(int i=0;i<prefix.length();i++)
         combinations(suffix+prefix.charAt(i),prefix.substring(i+1,prefix.length()));
    }
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
			st = new StringTokenizer("");
		}

		public double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		public String next() throws IOException {
			if (!st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
				return next();
			}
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
	}
}
