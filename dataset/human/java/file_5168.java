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
         String input = st.nextToken();
         int Q = Integer.parseInt(infile.readLine());
         ArrayList<Character> front = new ArrayList<Character>();
         ArrayList<Character> back = new ArrayList<Character>();
         boolean flip = false;
         while(Q-->0)
         {
            st = new StringTokenizer(infile.readLine());
            if(Integer.parseInt(st.nextToken()) == 1)
               flip = !flip;
            else
            {
               char a = st.nextToken().charAt(0);
               char b = st.nextToken().charAt(0);
               if(a == '1' && flip || a == '2' && !flip)
               {
                  back.add(b);
               }
               else
               {
                  front.add(b);
               }
            }
         }
         Collections.reverse(front);
         StringBuilder sb = new StringBuilder();
         StringBuilder lol = new StringBuilder(input);
         for(char c: front)
            sb.append(c);
         sb.append(input);
         for(char c: back)
            sb.append(c);
         if(flip)
            sb.reverse();
         System.out.println(sb);
      }
   }
