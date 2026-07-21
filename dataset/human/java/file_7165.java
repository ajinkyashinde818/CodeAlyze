import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws Exception {
		Scanner input =new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int k=input.nextInt();
		int n=input.nextInt();
		int[] arr=new int[n];
		for(int i =0 ;i<n ;i++) {
			arr[i]=input.nextInt();
		}
		int[] diff=new int[n];
		for(int i=0;i<n-1;i++) {
			diff[i]=arr[i+1]-arr[i];
		}
		diff[n-1]=arr[0]+(k-arr[n-1]);
		Arrays.sort(diff);
		pw.print(k-diff[n-1]);
		pw.close();
	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;
		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}
		public Scanner(String file) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(file));
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
		public boolean ready() throws IOException {
			return br.ready();
		}
	}

}
