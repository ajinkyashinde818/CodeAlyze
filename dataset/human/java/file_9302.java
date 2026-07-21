import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int cnt = 0;
		boolean flg = false;
		for(int i = 0; i < n; i++){
		    int a = sc.nextInt();
		    int b = sc.nextInt();
		    if(a == b){
		        cnt++;
		    }else{
		        cnt = 0;
		    }
		    if(cnt >= 3) flg = true;
		}
		
		// 計算
		String result = "No";
		if(flg) result = "Yes";
		
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
