import java.util.*;

public class Main{
      public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            String a = sc.next();
            if("abc".equals(a) || "acb".equals(a) || "bac".equals(a) || "bca".equals(a) || "cab".equals(a) || "cba".equals(a)){
              System.out.println("Yes");
            } else {
              System.out.println("No");
            }
            
            }
}
