import java.util.*;

public class Main{
      public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            String str1 = sc.next();
            String[] str2 = str1.split("");
            if("9".equals(str2[0]) || "9".equals(str2[1])){
              System.out.println("Yes");
            } else {
              System.out.println("No");
            }
          }
}
