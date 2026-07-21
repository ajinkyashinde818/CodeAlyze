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
    int count = 0;
    for (int i = 0; i < n; i++) {
      int d1 = Integer.parseInt(sc.next());
      int d2 = Integer.parseInt(sc.next());
      if (d1 == d2) {
        count++;
      } else {
        count = 0;
      }
      if (count == 3) {
        pw.println("Yes");
        return;
      }
    }
    pw.println("No");
  }
}
