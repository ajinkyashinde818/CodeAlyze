import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		long n = sc.nextLong();
		
		// 計算
		long result = 0;
		
		HashMap<Long, Long> map = new HashMap<Long, Long>();
		for(long m = 2; m <= sqrt(n); m++){
		    if(n == 1) break;
		    if(n%m == 0){
		        while(n%m == 0){
		            n = n/m;
		            map.put(m, map.getOrDefault(m, 0L)+1);
		        }
		    }
		}
		if(n != 1) map.put(n, map.getOrDefault(n, 0L)+1);
    	for(Long l : map.values()){
    	    long temp = 0;
    	    for(int i = 1; i <= l; i++){
    	        temp += i;
    	        if(temp <= l) result++;
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
