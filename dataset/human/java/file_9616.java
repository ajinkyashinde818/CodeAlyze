import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int counts = 0;
    for (int i = 0; i < N; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      if (a == b) {
        counts += 1;
        if (counts == 3) {
          break;
        }
      } else {
        counts = 0;
      }
    }
    if (counts == 3) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
