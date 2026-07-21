import java.util.*;
public class Main {
   public static void main(String[] args) {  
      Scanner sc = new Scanner(System.in);
      
      int a = sc.nextInt();
      int b = sc.nextInt();
      int k = sc.nextInt();
      
      ArrayList<Integer> list = new ArrayList<Integer>();
      for(int i = 1; i <= Math.min(a, b); i++) {
         if(a % i == 0 && b % i == 0) {
            list.add(i);
         }
      }
      System.out.println(list.get(list.size() - k));
   }
}
