import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    s = s.replace("eraser", "").replace("erase", "").replace("dreamer", "").replace("dream", "");
    if (s.equals("")) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}
