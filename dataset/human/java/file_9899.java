/*
If you want to aim high, aim high
Don't let that studying and grades consume you
Just live life young
******************************
If I'm the sun, you're the moon
Because when I go up, you go down
*******************************
I'm working for the day I will surpass you
https://www.a2oj.com/Ladder16.html
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
         int N = Integer.parseInt(st.nextToken());
         int M = Integer.parseInt(st.nextToken());
         int X = Integer.parseInt(st.nextToken());
         StringBuilder sb = new StringBuilder();
         int[] cost = new int[N];
         int[][] grid = new int[N][M];
         for(int i=0; i < N; i++)
         {
            st = new StringTokenizer(infile.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            for(int a=0; a < M; a++)
               grid[i][a] = Integer.parseInt(st.nextToken());
         }
         long rest = Long.MAX_VALUE;
         for(int mask=0; mask < (1 << N); mask++)
         {
            int[] res = new int[M];
            long temp = 0L;
            for(int b=0; b < N; b++)
               if((mask&(1<<b)) > 0)
               {
                  temp += cost[b];
                  for(int i=0; i < M; i++)
                     res[i] += grid[b][i];
               }
            boolean works = true;
            for(int x: res)
               if(x < X)
                  works = false;
            if(works)
               rest = Math.min(rest, temp);
         }
         if(rest == Long.MAX_VALUE)
            rest = -1;
         System.out.println(rest);
      }
   }
