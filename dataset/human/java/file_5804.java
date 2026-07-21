import java.util.*;

class Main {
   public static void main(String[] args)
   {
      Scanner scan  = new Scanner(System.in);
      String  str   = scan.next();
      int     count = 0;

      for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
              char t = str.charAt(i);
              char u = str.charAt(j);
              if(t == u){
                 count++;
                 }
              }
          }
      if(count == 3){
         System.out.println("Yes");
         }
      else{
          System.out.println("No");
          }
   }
}
