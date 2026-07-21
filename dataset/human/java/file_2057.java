import java.util.*;
import java.io.*;
public class Main{
	static ArrayList<Integer> primes = new ArrayList<Integer>();
   public static void main(String[] main) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      PrintWriter out = new PrintWriter(System.out);
      long n = Long.parseLong(st.nextToken());
      sieve((int)Math.sqrt(n));
      int[] triangle = new int[] {1, 3, 6, 10, 15, 21, 28, 36, 45};
      int ans = 0;
      for(int p: primes) {
    	  int pow = 0;
    	  while(n%p == 0) {
    		  n /= p;
    		  pow++;
    	  }
    	  int i = 0;
    	  for(; i < 10; i++)
    		  if(triangle[i] > pow)
    			  break;
    	  ans += i;
    	  if(n == 1)
    		  break;
      }
      if(n != 1)
    	  ans++;
      out.println(ans);
      out.close();
   }
   static void sieve(int n) {
	   boolean[] dp = new boolean[n+1];
	   for(int i = 2; i < n; i++)
		   dp[i] = true;
	   for(int p = 2; p*p <= n; p++) {
		   for(int i = p*p; i <= n; i+= p) {
			   dp[i] = false;
		   }
	   }
	   for(int i = 2; i < n; i++)
		   if(dp[i])
			   primes.add(i);
   }
}
