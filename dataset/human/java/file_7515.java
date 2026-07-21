import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author GYSHGX868
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      char[] s = in.nextString().toCharArray();
      for (int i = 0; i < s.length; i++) {
        if (s[i] == 'e') {
          int e1 = judge(s, i, new char[]{'e', 'r', 'a', 's', 'e', 'r'});
          if (e1 != -1) {
            i = e1;
            continue;
          }
          int e2 = judge(s, i, new char[]{'e', 'r', 'a', 's', 'e'});
          if (e2 != -1) {
            i = e2;
          } else {
            out.printLine("NO");
            return;
          }
        } else if (s[i] == 'd') {
          int e1 = judge(s, i, new char[]{'d', 'r', 'e', 'a', 'm', 'e', 'r'});
          if (e1 != -1) {
            i = e1;
            continue;
          }
          int e2 = judge(s, i, new char[]{'d', 'r', 'e', 'a', 'm'});
          if (e2 != -1) {
            i = e2;
          } else {
            out.printLine("NO");
            return;
          }
        } else if (s[i] == 'a') {
          if (i - 3 >= 0 && s[i - 3] == 'm' && s[i - 2] == 'e' && s[i - 1] == 'r') {
            int e1 = judge(s, i, new char[]{'a', 's', 'e', 'r'});
            if (e1 != -1) {
              i = e1;
              continue;
            }
            int e2 = judge(s, i, new char[]{'a', 's', 'e'});
            if (e2 != -1) {
              i = e2;
            } else {
              out.printLine("NO");
              return;
            }
          } else {
            out.printLine("NO");
            return;
          }
        } else {
          out.printLine("NO");
          return;
        }
      }
      out.printLine("YES");
    }

    private int judge(char[] s, int from, char[] substring) {
      for (int i = 1; i < substring.length; i++) {
        if (from + i >= s.length || s[from + i] != substring[i]) {
          return -1;
        }
      }
      return from + substring.length - 1;
    }

  }

  static class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private InputReader.SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int read() {
      if (numChars == -1) {
        throw new InputMismatchException();
      }
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (numChars <= 0) {
          return -1;
        }
      }
      return buf[curChar++];
    }

    public String nextString() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      StringBuilder res = new StringBuilder();
      do {
        if (Character.isValidCodePoint(c)) {
          res.appendCodePoint(c);
        }
        c = read();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public boolean isSpaceChar(int c) {
      if (filter != null) {
        return filter.isSpaceChar(c);
      }
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
      boolean isSpaceChar(int ch);

    }

  }

  static class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
      for (int i = 0; i < objects.length; i++) {
        if (i != 0) {
          writer.print(' ');
        }
        writer.print(objects[i]);
      }
    }

    public void printLine(Object... objects) {
      print(objects);
      writer.println();
    }

    public void close() {
      writer.close();
    }

  }
}
