import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String a = sc.next();
    String b = sc.next();
    char[] x = a.toCharArray();
    char[] y = b.toCharArray();

    if (x[0] > y[0]) {
      System.out.println(">");
    } else if (x[0] < y[0]) {
      System.out.println("<");
    } else {
      System.out.println("=");
    }
  }

}
