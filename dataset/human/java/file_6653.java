import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    long[] A = new long[N + 1];
    long sum = 0;
    long single = 0;
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextLong();
      sum += A[i];
      single += i + 1;
    }
    if (sum % single != 0) {
      System.out.println("NO");
      return;
    }
    A[N] = A[0];
    long count = sum / single;
    long use = 0;
    boolean ok = true;
    for (int i = 0; i < N; i++) {
      long diff = A[i + 1] - A[i] - count;
      if (diff > 0 || -diff % N != 0) {
        ok = false;
        break;
      }
      use += -diff / N;
    }
    ok &= use == count;
    System.out.println(ok ? "YES" : "NO");
  }

}
