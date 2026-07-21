/*
If you want to aim high, aim high
Don't let that studying and grades consume you
Just live life young
******************************
What do you think? What do you think?
1st on Billboard, what do you think of it
Next is a Grammy, what do you think of it
However you think, I’m sorry, but shit, I have no fucking interest
*******************************
Higher, higher, even higher, to the point you won’t even be able to see me
https://www.a2oj.com/Ladder16.html
*******************************
NEVER DO 300IQ CONTESTS EVER
300IQ AS WRITER = EXTRA NONO
*/
import java.util.*;
import java.io.*;
import java.math.*;

   public class Main
   {
      static long MOD = 1000000007L;
      public static void main(String omkar[]) throws Exception
      {
         BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));  
         StringTokenizer st = new StringTokenizer(infile.readLine());
         int N = Integer.parseInt(st.nextToken());
         int M = Integer.parseInt(st.nextToken());
         int[] arr = new int[M];
         for(int i=0; i < M; i++)
            arr[i] = Integer.parseInt(infile.readLine());
         HashSet<Integer> set = new HashSet<Integer>();
         for(int x: arr)
            set.add(x);
         long[] dp = new long[N+1];
         dp[0] = 1L;
         for(int i=1; i <= N; i++)
         {
            long sum = dp[i-1];
            if(i >= 2)
               sum += dp[i-2];
            sum %= MOD;
            dp[i] = sum;
            if(set.contains(i))
               dp[i] = 0L;
         }
         System.out.println(dp[N]);
      }
   }
