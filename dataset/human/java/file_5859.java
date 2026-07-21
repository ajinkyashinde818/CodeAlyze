import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String S = sc.nextLine();
    System.out.println(S.contains("a")&&S.contains("b")&&S.contains("c")?"Yes":"No");
  }
}
