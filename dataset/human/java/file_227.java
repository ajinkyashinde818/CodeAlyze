import java.util.Scanner;

import java.lang.Math;

public class Main {
  private static final int MAX_A = 1000000000;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();

    int num_neg = 0;
    long sum_abs = 0;
    int min_abs = MAX_A;
    for (int i = 0; i < N; i++) {
      int A = scanner.nextInt();
      num_neg += A < 0 ? 1 : 0;
      sum_abs += Math.abs(A);
      min_abs = Math.min(min_abs, Math.abs(A));
    }

    long ans;
    if (num_neg % 2 == 0)
      ans = sum_abs;
    else
      ans = sum_abs - min_abs * 2;
    System.out.println(ans);
  }
}
