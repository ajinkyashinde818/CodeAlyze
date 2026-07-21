import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    long[] a = new long[N];
    for (int i = 0; i < N; i++) a[i] = scanner.nextInt();
    for (int i = 1; i < N; i++) a[i] += a[i - 1];
    long res = Long.MAX_VALUE;
    for (int i = 0; i < N - 1; i++) {
      long diff = Math.abs(a[N - 1] - a[i] - a[i]);
      res = Math.min(diff, res);
    }
    System.out.println(res);
  }
}
