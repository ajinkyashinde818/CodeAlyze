import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    // TODO 自動生成されたメソッド・スタブ
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    int y = sc.nextInt();

    long a = Math.min(x, y);
    long b = Math.max(x, y);
    for (long i = 1; i <= 100000; i++) {
      if (a * i % b == 0) {
        System.out.println(a * i);
        break;
      }
    }
  }
}
