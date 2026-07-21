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
    AColorfulSubsequence solver = new AColorfulSubsequence();
    solver.solve(1, in, out);
    out.close();
  }

  static class AColorfulSubsequence {

    public void solve(int testNumber, Scanner in, PrintWriter out) {

      int n = in.nextInt();
      int[] alp = new int[26];
      String s = in.next();
      long l = 1;
      for (int i = 0; i < s.length(); i++) {
        alp[(int) s.charAt(i) - (int) 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        l *= (alp[i] + 1);
        l = l % 1000000007;
      }
      out.println(l - 1);

    }

  }
}
