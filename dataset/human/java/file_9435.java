import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    final Scanner scanner = new Scanner(System.in);
    final int N = scanner.nextInt();

    boolean[] isZoromeList = new boolean[N];
    for (int i = 0; i < N; i++) {
      int n1 = scanner.nextInt();
      int n2 = scanner.nextInt();

      if (n1 == n2) {
        isZoromeList[i] = true;
      } else {
        isZoromeList[i] = false;
      }
    }

    boolean is3TimesZorome = false;
    for (int i = 0; i < isZoromeList.length - 2; i++) {
      if (isZoromeList[i] && isZoromeList[i + 1] && isZoromeList[i + 2]) {
        is3TimesZorome = true;
      }
    }

    System.out.println(is3TimesZorome ? "Yes" : "No");
  }
}
