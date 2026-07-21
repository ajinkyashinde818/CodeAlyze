import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    int i = S.length();
    while (i > 0) {
      if (i-7 >= 0 && S.substring(i-7, i).equals("dreamer")) {
        i -= 7;
      } else if (i-6 >= 0 && S.substring(i-6, i).equals("eraser")) {
        i -= 6;
      } else if (i-5 >= 0
                 && (S.substring(i-5, i).equals("erase")
                     || S.substring(i-5, i).equals("dream"))) {
        i -= 5;
      } else {
        break;
      }
    }
    System.out.println(i == 0 ? "YES" : "NO");
  }
}
