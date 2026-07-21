import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] a = new int[n];
		for(int i = 0; i < n; i++){
		    a[i] = sc.nextInt()-1;
		}
		
		// 計算
		int result = 0;
		int[] cnt = new int[n];
		Arrays.fill(cnt, Integer.MAX_VALUE);
		int now = 0;
		int loop = 0;
		int start = 0;
		for(int i = 0; i <= n; i++){
		    if(cnt[a[now]] == Integer.MAX_VALUE){
		        cnt[a[now]] = i+1;
		        now = a[now];
		    }else{
		        loop = a[now];
		        start = i+1;
		        break;
		    }
		}
		//System.out.println(loop);
		//System.out.println(start);
		
		int[] cntL = new int[n];
		Arrays.fill(cntL, Integer.MAX_VALUE);
		cntL[loop] = 0;
		int nowL = loop;
		int cycle = 0;
		for(int i = 0; i < n; i++){
		    if(cntL[a[nowL]] == Integer.MAX_VALUE){
		        cntL[a[nowL]] = i+1;
		        nowL = a[nowL];
		    }else{
		        cycle = i+1;
		        break;
		    }
		}
		
		//System.out.println(Arrays.toString(cnt));
		//System.out.println(Arrays.toString(cntL));
		
		if(k < start){
		    for(int i = 0; i < n; i++){
		        if(cnt[i] == k) result = i+1;
		    }
		}else{
		    for(int i = 0; i < n; i++){
		        if(cntL[i] == (k-start)%cycle) result = i+1;
		    }
		}
		
		
		// 出力
		System.out.println(result);
	}
	
	public static class Scanner {
		private BufferedReader br; private StringTokenizer tok;
		public Scanner(InputStream is) throws IOException { br = new BufferedReader(new InputStreamReader(is));}
		private void getLine() throws IOException { while(!hasNext()) tok = new StringTokenizer(br.readLine());}
		private boolean hasNext() { return tok != null && tok.hasMoreTokens();}
		public String next() throws IOException { getLine(); return tok.nextToken();}
		public int nextInt() throws IOException { return Integer.parseInt(next());}
		public long nextLong() throws IOException { return Long.parseLong(next());}
		public double nextDouble() throws IOException { return Double.parseDouble(next());}
	}
}
