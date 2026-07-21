import java.util.Scanner;

class Main {
  static long gcd(long x, long y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
  }

  public static void main(String[] args) {
    Scanner stdIn = new Scanner(System.in);
    long a = Integer.parseInt(stdIn.next());
    long b = Integer.parseInt(stdIn.next());
    long ans = a * b / gcd(a, b);

    System.out.println(ans);
  }
}
