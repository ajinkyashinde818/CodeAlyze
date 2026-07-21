import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    // TODO 自動生成されたメソッド・スタブ
    Scanner scanner = new Scanner(System.in);
    String n = scanner.next();

    if (n.charAt(0) == '9' || n.charAt(1) == '9') {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }

  }

}
