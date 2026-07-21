import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    if (a + b >= c - 1) {
      System.out.println(b + c);
    } else {
      System.out.println(a + 2 * b + 1);
    }
  }
}
