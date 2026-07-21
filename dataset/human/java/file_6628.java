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
         char[] arr = infile.readLine().toCharArray();
         int N = arr.length;
         StringTokenizer st = new StringTokenizer(infile.readLine());
         int X = Integer.parseInt(st.nextToken());
         int Y = Integer.parseInt(st.nextToken());
         ArrayList<Integer> ls = new ArrayList<Integer>();
         char curr = arr[0];
         int size = 1;
         for(int i=1; i < N; i++)
         {
            if(curr == arr[i])
               size++;
            else
            {
               ls.add(size);
               size = 1;
               curr = arr[i];
            }
         }
         ls.add(size);
         if(arr[0] == 'F')
         {
            X -= ls.get(0);
            ls.remove(0);
         }
         if(ls.size() == 0)
         {
            if(X != 0 || Y != 0)
               System.out.println("No");
            else
               System.out.println("Yes");
            return;
         }
         int par = 0;
         ArrayList<Integer> hort = new ArrayList<Integer>();
         ArrayList<Integer> vert = new ArrayList<Integer>();
         for(int i=0; i < ls.size(); i++)
         {
            if(i%2 == 0)
            {
               par += ls.get(i);
               par = (par&1);
            }
            else
            {
               if(par == 0)
                  hort.add(ls.get(i));
               else
                  vert.add(ls.get(i));
            }
         }
         //solve
         if(!found(X, hort) || !found(Y, vert))
            System.out.println("No");
         else
            System.out.println("Yes");
      }
      public static boolean found(int target, ArrayList<Integer> ls)
      {
         HashSet<Integer> set = new HashSet<Integer>();
         set.add(0);
         for(int x: ls)
         {
            HashSet<Integer> temp = new HashSet<Integer>();
            for(int v: set)
            {
               temp.add(v+x);
               temp.add(v-x);
            }
            set = temp;
         }
         return set.contains(target);
      }
   }
