import java.io.InputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    resolve(System.in, System.out);
  }

  static void resolve(InputStream is, PrintStream pw) {
    Scanner sc = new Scanner(is);
    long a = Integer.parseInt(sc.next());
    long b = Integer.parseInt(sc.next());
    pw.println(a * b / BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).longValue());
  }
}
