import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		for(int i = 0; i < n; i++){
		    a[i] = sc.next();
		}
		for(int i = 0; i < m; i++){
		    b[i] = sc.next();
		}
		
		// 計算
		String result = "No";
		for(int i = 0; i < n-m+1; i++){
		    for(int j = 0; j < n-m+1; j++){
		        boolean flg = true;
		        for(int k = 0; k < m; k++){
		            for(int l = 0; l < m; l++){
		                if(a[i+k].charAt(j+l) != b[k].charAt(l)){
		                    flg = false;
		                    break;
		                }
		            }
		            if(!flg) break;
		        }
		        if(flg) result = "Yes";
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
