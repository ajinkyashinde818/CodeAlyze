import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int A = scanner.nextInt();
    int B = scanner.nextInt();
    long gcd = gcd(A, B);
    System.out.println(A / gcd * B);
  }

  static long gcd(long i, long j) {
    if (i > j) return gcd(j, i);
    while (i > 0) {
      long r = j % i;
      j = i;
      i = r;
    }
    return j;
  }
}
