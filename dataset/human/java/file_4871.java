import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    long N = scanner.nextLong();
    if (N % 2 == 1) {
      System.out.println(0);
      return;
    }
    long res = 0;
    long a = 1;
    for (int i = 0; i < 25; i++) {
      a *= 5;
      res += N / a / 2;
    }
    System.out.println(res);
  }
}
