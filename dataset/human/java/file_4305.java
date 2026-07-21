import java.util.ArrayList;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    ArrayList<Integer> as = new ArrayList<>();
    ArrayList<Integer> bs = new ArrayList<>();
    ArrayList<Integer> cs = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      as.add(sc.nextInt());
    }
    for (int i = 0; i < n; i++) {
      bs.add(sc.nextInt());
    }
    for (int i = 0; i < n -1 ; i++) {
      cs.add(sc.nextInt());
    }

    int ans = 0;
    int prev = -1;
    for (int a : as) {
      ans += bs.get(a -1);
      if (a - prev == 1) {
        ans += cs.get(a - 2);
      }
      prev = a;
    }
    System.out.println(ans);
  }
}
