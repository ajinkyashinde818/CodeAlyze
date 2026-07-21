import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    char[] c = s.toCharArray();
    Arrays.sort(c);
    String k = new String(c);
    if (k.equals("abc")) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
