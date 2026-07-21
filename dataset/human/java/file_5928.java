import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String abc = sc.next();
    if (abc.contains("a") && abc.contains("b") && abc.contains("c")) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
