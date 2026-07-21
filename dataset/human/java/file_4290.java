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
    int[] a = new int[n];
    int[] b = new int[n];
    int[] c = new int[n - 1];
    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(sc.next());
    }
    for (int i = 0; i < n; i++) {
      b[i] = Integer.parseInt(sc.next());
    }
    for (int i = 0; i < n - 1; i++) {
      c[i] = Integer.parseInt(sc.next());
    }
    long ans = 0;
    int previous = -2;
    for (int i = 0; i < n; i++) {
      int an = a[i];
      ans += b[an - 1];
      if (previous + 1 == an) {
        ans += c[previous - 1];
      }
      previous = an;
    }
    pw.println(ans);
  }
}
