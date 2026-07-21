import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in Actual solution is at the top
 *
 * @author Silviase
 */
public class Main {

  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    Scanner in = new Scanner(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    KEYENCE2020C solver = new KEYENCE2020C();
    solver.solve(1, in, out);
    out.close();
  }

  static class KEYENCE2020C {

    public void solve(int testNumber, Scanner in, PrintWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int s = in.nextInt();
      int[] ar = new int[n];
      StringBuilder sb = new StringBuilder();
      if (s == 1000000000) {
        for (int i = 0; i < n; i++) {
          if (i < k) {
            ar[i] = s;
          } else {
            ar[i] = s - 1;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (i < k) {
            ar[i] = s;
          } else {
            ar[i] = s + 1;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        sb.append(ar[i]);
        sb.append(" ");
      }
      out.println(new String(sb));

    }

  }
}
