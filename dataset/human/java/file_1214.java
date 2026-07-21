import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static final int MOD = (int)Math.pow(10, 9);
	public static void main(String[] args) {
		FastReader sc = new FastReader();
		int n = sc.nextInt();
		int[] nums = new int[n];
		long[] prefix = new long[n];
		long[] postfix = new long[n];
		/*
		1  2  3  4  5  6
		1  3  6 10 15 21
		20 18 15 11 6 0

		10 0
		-10*/
		for (int i = 0; i < n; i++) {
			nums[i] = sc.nextInt();
		}
		prefix[0] = nums[0];
		for (int i = 1; i < n; i++) {
			prefix[i] = nums[i] + prefix[i - 1];
		}
		
		for (int i = n - 2; i >=0; i--) {
			postfix[i] = nums[i + 1] + postfix[i + 1];
		}
		long res = Integer.MAX_VALUE;
		for (int i = 0; i < n - 1; i++) {
			res = Math.min(res, Math.abs(prefix[i] - postfix[i]));
		}
		System.out.println(res);
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
