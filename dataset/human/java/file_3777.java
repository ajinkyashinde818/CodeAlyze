import java.util.*;

class Main{
   public static void main(String[] args)
   {
      Scanner scan = new Scanner(System.in);
      String  X    = scan.next();
      String  Y    = scan.next();

      if(X.charAt(0) > Y.charAt(0)){
         System.out.println(">");
         }
      else if(X.charAt(0) == Y.charAt(0)){
              System.out.println("=");
              }
      else{
          System.out.println("<");
          }
   }
}
