import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String ans = "No";
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (sc.nextInt() == sc.nextInt()) {
        cnt++;
      } else {
        cnt = 0;
      }
      if (cnt >= 3) {
        ans = "Yes";
        break;
      }
    }
    System.out.println(ans);
  }
}
