import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		String s = sc.next();
		
		// 計算
		String result = "YES";
		boolean flg = true;
		int to = s.length();
		while(flg){
		    if(to-5 >= 0){
		        String t = s.substring(to-5, to);
		        if(t.equals("dream") || t.equals("erase")){
		            to -= 5;
		            continue;
		        }
		    }
		    if(to-6 >= 0){
		        String t = s.substring(to-6, to);
		        if(t.equals("eraser")){
		            to -= 6;
		            continue;
		        }
		    }
		    if(to-7 >= 0){
		        String t = s.substring(to-7, to);
		        if(t.equals("dreamer")){
		            to -= 7;
		            continue;
		        }
		    }
		    flg = false;
		    if(to != 0) result = "NO";
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
