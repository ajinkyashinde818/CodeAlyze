import java.util.*;

public class Main {
  public static void main (String[] args) {
    Scanner sc = new Scanner(System.in);

    String S = "1" + sc.next();

    S = S.replaceAll("eraser", "");
    S = S.replaceAll("erase", "");
    S = S.replaceAll("dreamer", "");
    S = S.replaceAll("dream", "");
    
    System.out.println(S.equals("1") ? "YES": "NO");
  }
}
