import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int ans = 0;
    if (a + b >= c - 1) {
      System.out.println(b + c);
      return;
    } else {
      System.out.println(1 + b * 2 + a);
      return;
    }
  }

}
