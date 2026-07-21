import java.util.*;
import java.*;


class Main{
   public static void main(String[] args)
   {
      Scanner scan = new Scanner(System.in);
      String  s = scan.next();
      int     ns = 0, nt = 0;

      char[] sss = new char[s.length()];

      for(int i = 0; i < s.length(); i++){
          sss[i] = s.charAt(i);
          ns++;
          }
      Arrays.sort(sss);

      /* int Mins = sss[0];
       * for(int i = 0; i < s.length; i++){
       *    Mins = Math.min(Mins, sss[0]);
       *  }*/
      String t   = scan.next();
      char[] ttt = new char[t.length()];
      for(int j = 0; j < t.length(); j++){
          ttt[j] = t.charAt(j);
          nt++;
          }

      int array = s.length() <= t.length() ? s.length() : t.length();
      Arrays.sort(ttt);
      if(sss[0] > ttt[t.length() - 1]){
         System.out.println("No");
         }
      else if(sss[0] == ttt[t.length() - 1]){
              for(int i = 1; i < array; i++){
                  if(sss[i] < ttt[t.length() - 1 - i]){
                     System.out.println("Yes");
                     return;
                     }
                  else if(sss[i] > ttt[t.length() - 1 - i]){
                          System.out.println("No");
                          return;
                          }
                  }
              if(s.length() < t.length()){
                 System.out.println("Yes");
                 }
              else{
                  System.out.println("No");
                  }
              }
      else{
          System.out.println("Yes");
          }
   }
}
