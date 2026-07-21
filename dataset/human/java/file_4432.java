import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author dyominov
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    APoisonousCookies solver = new APoisonousCookies();
    solver.solve(1, in, out);
    out.close();
  }

  static class APoisonousCookies {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int a = in.nextInt();
      int b = in.nextInt();
      int c = in.nextInt();
      long d = c - a > 0 ? c - a : 0;
      long f = d - b > 0 ? d - b : 0;
      long res = Math.min(a, c) + Math.min(d, b) + Math.min(f, 1) + b;
      out.println(res);
    }

  }

  static class InputReader implements AutoCloseable {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      //reader = new BufferedReader(new FileReader(stream), 32768);
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public void close() {
    }

  }
}
