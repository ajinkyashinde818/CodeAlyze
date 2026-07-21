import java.io.*;
import java.util.*;
import java.util.Map.Entry;


public class  Main{
	static char[]in;
	static long [][]memo;
	static long dp(int i,int carry) {
		if(i<0) {
			return carry;
		}
		if(memo[i][carry]!=-1)return memo[i][carry];
		
		int x=(in[i]-'0');
		x+=carry;
		int newc=x/10;
		x=x%10;
		//System.out.println(x+" "+newc);
		return memo[i][carry]=Math.min(dp(i-1,newc)+x, x==0?(long)1e15:dp(i-1,newc+1)+10-x);
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		in=sc.nextLine().toCharArray();
		memo=new long[in.length][2];
		for(long[]i:memo)Arrays.fill(i, -1);
		for(int i=0;i<in.length;i++) {
			for(int carry=0;carry<2;carry++) {
				int x=(in[i]-'0');
				x+=carry;
				int newc=x/10;
				x=x%10;
				//System.out.println(x+" "+newc);
				long opt1=(i-1<0?newc:memo[i-1][newc])+x;
				long opt2=newc==1?(long)1e15:((i-1<0?newc+1:memo[i-1][newc+1])+10-x);
				memo[i][carry]=Math.min(opt1, opt2);
				
			}
		}
		
		pw.println(dp(in.length-1,0));
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
		public int[] takearr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] takearrl(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public Integer[] takearrobj(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] takearrlobj(int n) throws IOException {
	        Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
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
