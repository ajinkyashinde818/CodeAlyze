import static java.lang.System.out;
import java.util.Scanner;
import java.util.Arrays;

public class Main{
   static Scanner sc = new Scanner(System.in);
   public static void main(String[] args){
      char[] s = sc.next().toCharArray();
      char[] t = sc.next().toCharArray();
      boolean flag = false;
      int tlength = t.length-1;
      Arrays.sort(s);
      Arrays.sort(t);

      int loop = Math.min(s.length,t.length);
      for(int i=0;i<loop;i++){
         if(s[i] == t[tlength]){
            tlength--;
            if(s.length < t.length && i == loop-1){
               flag = true;
               break;
            }
            continue;
         }else if(s[i] > t[tlength]){
            break;
         }else{
            flag = true;
            break;
         }
         
      }

      /**
       * パターン
       * 数値以下 break
       * 数値以上 break
       * 同じ     continue
       * 
       */
      String result = flag ? "Yes":"No"; 
      System.out.println(result);
   }
}
