/*
Stay innocent, be naive. 
But still dream big. 
Dream big to the point that it is beyond your ability and endeavour to achieve it. 
So dream big and don’t lose your innocence.
*/
import java.util.*;
import java.io.*;

   public class Main
   {
      public static void main(String args[]) throws Exception
      {
         BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));  
         StringTokenizer st = new StringTokenizer(infile.readLine());
         int N = Integer.parseInt(st.nextToken());
         int[] arr = new int[N];
         st = new StringTokenizer(infile.readLine());
         for(int i=0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
         int[] brr = new int[N];
         st = new StringTokenizer(infile.readLine());
         for(int i=0; i < N; i++)
            brr[i] = Integer.parseInt(st.nextToken());
         int[] crr = new int[N-1];
         st = new StringTokenizer(infile.readLine());
         for(int i=0; i < N-1; i++)
            crr[i] = Integer.parseInt(st.nextToken());
         //
         int res = 0;
         for(int i=0; i < N; i++)
         {
            res += brr[arr[i]-1];
            if(i > 0 && arr[i-1]+1 == arr[i])
               res += crr[arr[i-1]-1];
         }
         System.out.println(res);
      }
   }
