import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    resolve(System.in, System.out);
  }

  static void resolve(InputStream is, PrintStream pw) {
    Scanner sc = new Scanner(is);
    int n = Integer.parseInt(sc.next());
    int r = Integer.parseInt(sc.next());
    if (n >= 10) {
      pw.println(r);
    } else {
      pw.println(r + (100 * (10 - n)));
    }
  }
}
