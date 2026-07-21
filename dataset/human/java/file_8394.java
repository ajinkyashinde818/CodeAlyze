import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    sc.close();

    long ans = lcm(A, B);
    System.out.println(ans);
  }

  private static long lcm(long a, long b) {
    return a / gcd_r(a, b) * b;
  }

  private static long gcd_r(long a, long b) {
    return a < b ? gcd_r(b, a) : b == 0 ? a : gcd_r(b, a % b);
  }
}
