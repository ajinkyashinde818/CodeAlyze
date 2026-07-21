import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // 入力
    try (Scanner sc = new Scanner(System.in);) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();

      int bigger = b > a ? b : a;
      List<Integer> list = new ArrayList<>();
      for (int i = 1; i <= bigger; i++) {
        if (a % i == 0 && b % i == 0) {
          list.add(i);
        }
      }

      System.out.println(list.get(list.size() - c));
    }
  }
}
