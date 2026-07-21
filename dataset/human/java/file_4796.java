import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    resolve(System.in, System.out);
  }

  static void resolve(InputStream is, PrintStream pw) {
    Scanner sc = new Scanner(is);
    long n = Long.parseLong(sc.next());
    if (n < 2) {
      pw.println(0);
      return;
    }
    if (n % 2 == 1) {
      pw.println(0);
      return;
    }
    long ans = 0;
    long divider = 10;
    while (n >= divider) {
      ans += (n / divider);
      divider *= 5;
    }
    pw.println(ans);
  }
}
