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
      public static void main(String omkar[]) throws Exception
      {
         BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));  
         StringTokenizer st = new StringTokenizer(infile.readLine());
         long N = Long.parseLong(st.nextToken());
         HashMap<Long, Integer> map = new HashMap<Long, Integer>();
         long temp = N;
         if(temp%2 == 0)
         {
            int cnt = 0;
            while(temp%2 == 0)
            {
               temp /= 2;
               cnt++;
            }
            map.put(2L, cnt);
         }
         for(long i=3; i <= (long)(Math.sqrt(N)+0.000001); i+=2)
            if(temp%i == 0)
            {
               int cnt = 0;
               while(temp%i == 0)
               {
                  temp /= i;
                  cnt++;
               }
               map.put(i, cnt);
            }
         long res = 0L;
         if(temp > 2)
            res++;
         for(long key: map.keySet())
         {
            long low = 1L;
            long high = 40L;
            while(low != high)
            {
               long mid = (low+high+1)/2;
               if(mid*(mid+1)/2 > map.get(key))
                  high = mid-1;
               else
                  low = mid;
            }
            res += low;
         }
         System.out.println(res);
      }
   }
