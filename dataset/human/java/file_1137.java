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
    ABC067CSplittingPile solver = new ABC067CSplittingPile();
    solver.solve(1, in, out);
    out.close();
  }

  static class ABC067CSplittingPile {

    public void solve(int testNumber, Scanner in, PrintWriter out) {
      int n = in.nextInt();
      int[] ar = new int[n];
      long[] ruiseki = new long[n + 1];
      long min = Long.MAX_VALUE;
      long sum = 0;

      for (int i = 0; i < n; i++) {
        ar[i] = in.nextInt();
        ruiseki[i + 1] = ruiseki[i] + (long) ar[i];
        sum += ar[i];
      }

      for (int i = 1; i < n; i++) {
        min = Math.min(min, Math.abs((sum - ruiseki[i]) - ruiseki[i]));
      }
      out.println(min);
    }

  }
}
