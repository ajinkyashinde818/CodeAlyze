import java.io.*;
import java.util.*;
 
 
public class Main {
	public static void main(String[] args) throws Exception {
		MScanner sc=new MScanner(System.in);
		//MScanner sc=new MScanner("portals.in");
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		int[]a=new int[n],b=new int[n],c=new int[n-1];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt()-1;
		}
		for(int i=0;i<n;i++) {
			b[i]=sc.nextInt();
		}
		for(int i=0;i<n-1;i++) {
			c[i]=sc.nextInt();
		}
		int prev=-7;int sum=0;
		for(int i=0;i<n;i++) {
			sum+=b[a[i]];
			if(a[i]==prev+1) {
				sum+=c[prev];
			}
			prev=a[i];
		}
		pw.println(sum);
		pw.flush();
	}
    static class MScanner {
		StringTokenizer st;
		BufferedReader br;
 
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
 
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}
