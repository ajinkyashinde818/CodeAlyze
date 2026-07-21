import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static final int MOD = (int)Math.pow(10, 9) + 7;
	public static void main(String[] args) {
		FastReader sc = new FastReader();
		int n = sc.nextInt();
		long[] dp = new long[n+1];
		int m = sc.nextInt();
		
		for (int i = 0; i< m; i++) {
			int a = sc.nextInt();
			dp[a] = -1;
		}
		
		dp[0] = (dp[0] == 0) ? 1 : -1;
		dp[1] = (dp[1] == 0) ? 1 : -1;
		
		for (int i = 2; i < dp.length;i++) {
			if (dp[i] != -1) {
				long step1 = (dp[i-1] == -1) ? 0 : dp[i-1];
				long step2 = (dp[i-2] == -1) ? 0 : dp[i-2];
				
				dp[i] = (step1 + step2) % MOD;
			}
			
		}
		
		System.out.println(dp[dp.length-1]);
	}

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
	        } catch (IOException  e) {
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
	        try{
	            str = br.readLine();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
	        return str;
	      }
	  }
}
