import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    int count = 0;
    boolean hit = false;
    for (int i = 0; i < n; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();

      if (a == b && hit) {
        count++;
      } else if (a == b) {
        hit = true;
        count++;
      } else {
        hit = false;
        count = 0;
      }

      if (count >= 3) {
        System.out.println("Yes");
        return;
      }
    }

    System.out.println("No");
  }
}
