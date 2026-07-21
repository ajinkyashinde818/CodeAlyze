import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    char[] c = s.toCharArray();
    Arrays.sort(c);
    String news = new String(c);

    if (news.equals("abc")) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }

  }
}
