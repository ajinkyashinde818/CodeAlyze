import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] a = new long[N];
    long sum = 0;
    for (int i = 0; i < N; i++) {
      a[i] = sc.nextLong();
      sum += a[i];
    }
    long sum2 = 0;
    long min = Long.MAX_VALUE;
    for (int i = 0; i < N - 1; i++) {
      sum2 += a[i];
      long tmp = Math.abs(2 * sum2 - sum);
      if (tmp < min) {
        min = tmp;
      }
    }
    System.out.println(min);
  }
}
