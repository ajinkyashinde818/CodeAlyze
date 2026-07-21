import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long A = sc.nextLong();
    long B = sc.nextLong();
    sc.close();

    System.out.println(lcm(A, B));
  }

  private static long lcm(long m, long n) {
    return m * n / gcd(m, n);
  }

  private static long gcd(long m, long n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
  }
}
