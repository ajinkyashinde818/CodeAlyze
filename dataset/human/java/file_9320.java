import java.util.*;
import java.io.*;

public class Main {
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

	

	public static void main(String[] args) throws FileNotFoundException {
	
	
 /*File file =new File("input.txt");
 Scanner scan=new Scanner(new FileInputStream(file));
 PrintWriter out=new PrintWriter("output.txt");
 */
FastReader scan=new FastReader();
 int n=scan.nextInt();
 int count=0;
 int max=0;
 while(n-->0){
	 int a=scan.nextInt();
	 int b=scan.nextInt();
	 if(a==b){
++count;
	 }
	 else{
		 count=0;
	 }
	 max=Math.max(count,max);
	 
 }

 if(max>=3){
	 System.out.println("Yes");
 }
 else
 System.out.println("No");

	}
}
