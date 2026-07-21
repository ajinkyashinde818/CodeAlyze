import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 */
public class Main {

  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    ABC solver = new ABC();
    solver.solve(1, in, out);
    out.close();
  }

  static class ABC {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      char[] s = in.next().toCharArray();
      char[] t = "abc".toCharArray();
      Arrays.sort(s);
      do {
        if (Arrays.equals(s, t)) {
          out.println("Yes");
          return;
        }
      } while (ArrayUtils.nextPermutation(s));
      out.println("No");
    }

  }

  static class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1 << 13];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int read() {
      if (this.numChars == -1) {
        throw new UnknownError();
      } else {
        if (this.curChar >= this.numChars) {
          this.curChar = 0;

          try {
            this.numChars = this.stream.read(this.buf);
          } catch (IOException ex) {
            throw new InputMismatchException();
          }

          if (this.numChars <= 0) {
            return -1;
          }
        }

        return this.buf[this.curChar++];
      }
    }

    public String next() {
      int c;
      while (isSpaceChar(c = this.read())) {
      }

      StringBuilder result = new StringBuilder();
      result.appendCodePoint(c);

      while (!isSpaceChar(c = this.read())) {
        result.appendCodePoint(c);
      }

      return result.toString();
    }

    public static boolean isSpaceChar(int c) {
      return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
    }

  }

  static class ArrayUtils {

    public static boolean nextPermutation(char[] array) {
      int i = array.length - 1;
      while (i > 0 && array[i - 1] >= array[i]) {
        i--;
      }
      if (i <= 0) {
        return false;
      }
      int j = array.length - 1;
      while (array[j] <= array[i - 1]) {
        j--;
      }
      char temp = array[i - 1];
      array[i - 1] = array[j];
      array[j] = temp;
      j = array.length - 1;
      while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
      }
      return true;
    }

  }
}
