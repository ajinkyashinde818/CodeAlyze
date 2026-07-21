import java.util.*;

/**
 * B Main
 *
 * @date 2020.09.19
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */

public class Main {
  Scanner sc;

  public static void main(String[] args) {
    new Main().execute();
  }

  public void execute() {
    this.sc = new Scanner(System.in);
    int n = sc.nextInt();

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int d0 = sc.nextInt();
      int d1 = sc.nextInt();
      if (d0 == d1) {
        cnt++;
        if (cnt >= 3) {
          System.out.println("Yes");
          return;
        }
      } else {
        cnt = 0;
      }
    }
    System.out.println("No");
  }
}
