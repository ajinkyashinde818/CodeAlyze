import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    long ans = (a * b) / gcd(a, b);
    System.out.println(ans);
  }

  public static long gcd(long x, long y) {
    if(y == 0) return x;
    return gcd(y, (x % y));
  }
}
