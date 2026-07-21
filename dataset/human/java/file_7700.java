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
    long k = Long.parseLong(sc.next());
    int a[] = new int[n + 1];
    for (int i = 0; i < n; i++) {
      a[i + 1] = Integer.parseInt(sc.next());
    }
    if (a[0] == 1) {
      pw.println(1);
      return;
    }
    int arrivedStep[] = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
      arrivedStep[i] = -1;
    }
    int current = 1;
    int loopStart = 0;
    int loopLength = 0;
    long remainK = k;
    for (int i = 0; i < k; i++) {
      if (arrivedStep[current] != -1) {
        // loop is detected
        loopStart = current;
        loopLength = i - arrivedStep[current];
        remainK -= i;
        break;
      }
      arrivedStep[current] = i;
      current = a[current];
      if (i == k - 1) {
        pw.println(current);
        return;
      }
    }
    remainK %= loopLength;
    current = loopStart;
    for (long i = 0; i < remainK; i++) {
      current = a[current];
    }
    pw.println(current);
  }
}
