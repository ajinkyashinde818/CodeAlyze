import java.io.*;
import java.util.*;

public class  Main{
	static long[]memo;
	static int mod=(int)1e9+7;
	static boolean[]broken;
	static long dp(int i) {
		if(i==memo.length)return 1l;
		if(i>memo.length)return 0;
		if(memo[i]!=-1)return memo[i];
		if(broken[i]) {
			return memo[i]=0;
		}
		return memo[i]=(dp(i+1)+dp(i+2))%mod;
	}
    public static void main(String[] args) throws Exception{
        //MScanner sc = new MScanner("chess.in");
        MScanner sc = new MScanner(System.in);
        PrintWriter pw=new PrintWriter(System.out);
        int n=sc.nextInt();
        int m=sc.nextInt();
        broken=new boolean[1000000];
        for(int i=0;i<m;i++)broken[sc.nextInt()]=true;
        memo=new long[n];Arrays.fill(memo, -1);
        pw.println(dp(0));
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
