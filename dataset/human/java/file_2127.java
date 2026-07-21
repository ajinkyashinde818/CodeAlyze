import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
	
	public static class FastReader {
		BufferedReader br;
		StringTokenizer root;
		
 
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while (root == null || !root.hasMoreTokens()) {
				try {
					root = new StringTokenizer(br.readLine());
				} catch (Exception addd) {
					addd.printStackTrace();
				}
			}
			return root.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (Exception addd) {
				addd.printStackTrace();
			}
			return str;
		}
	}
	
	public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
	
	public static FastReader sc = new FastReader();
 
	static long mod = (int) (1e9+7),MAX=(long)(1e18);
	static List<Integer>[] edges;
	public static int[][] parent;
	public static int col = 20;
	public static void main(String[] args) throws IOException{
		long n = sc.nextLong();
		Map<Long,Integer> map = new HashMap<>();
		fac(n,map);
		//out.print(map);
		long ans = 0;
		for(long key : map.keySet()) {
			long num = 1;
			long val = map.get(key);
			int cnt = 0;
			while(val >= 0) {
			     val-=num;
			     ++num;
			   //  out.println(val);
			     if(val >= 0)
				++cnt;
			}
			//out.println(cnt);
			ans+=cnt;
		}
		out.print(ans);
		out.close();
	}
	
    public static void fac(long n, Map<Long, Integer> map) 
    { 
        // Print the number of 2s that divide n 
        while (n%2==0) 
        {   map.put(2L, map.getOrDefault(2L,0)+1);
       // out.print(map);
            n /= 2; 
        } 
  
        // n must be odd at this point.  So we can 
        // skip one element (Note i = i +2) 
        for (long i = 3; i <= Math.sqrt(n); i+= 2) 
        { 
            // While i divides n, print i and divide n 
            while (n%i == 0) 
            { 
            	map.put(i, map.getOrDefault(i,0)+1);
                n /= i; 
            } 
        } 
  
        // This condition is to handle the case whien 
        // n is a prime number greater than 2 
        if (n > 2) 
        	map.put(n, map.getOrDefault(n,0)+1);
    } 
}
