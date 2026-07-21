import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    int count = 0;
    boolean check = false;
    for (int i = 0; i < n; i++) {
      int d1 = sc.nextInt();
      int d2 = sc.nextInt();

      if (d1 == d2) {
        count++;
      } else {
        count = 0;
      }

      if (count > 2) {
        check = true;
      }
    }
    System.out.println(check ? "Yes" : "No");
  }
}
