import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    resolve(System.in, System.out);
  }

  static void resolve(InputStream is, PrintStream pw) {
    Scanner sc = new Scanner(is);
    int k = Integer.parseInt(sc.next());
    int n = Integer.parseInt(sc.next());
    int a[] = new int[n];
    int maxDistance = 0;
    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(sc.next());
    }
    for (int i = 0; i < n - 1; i++) {
      maxDistance = Math.max(a[i + 1] - a[i], maxDistance);
    }
    maxDistance = Math.max(a[0] + (k - a[n - 1]), maxDistance);
    pw.println(k - maxDistance);
  }
}
