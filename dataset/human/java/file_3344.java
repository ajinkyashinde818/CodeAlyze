import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String first = s.substring(0,1);
    String last = s.substring(1,2);

    if (first.equals("9") || last.equals("9")) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }

  }

}
