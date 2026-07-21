import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      int l1 = sc.nextInt();
      int l2 = sc.nextInt();
      if (l1 == l2) {
        cnt++;
      } else {
        cnt = 0;
      }
      if (cnt == 3) {
        ans++;
        cnt = 0;
      }
    }

    if (ans > 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }

  }
}
