import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author sumit
 */
public class Main {
      public static void main(String[] args) {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            InputReader in = new InputReader(inputStream);
            OutputWriter out = new OutputWriter(outputStream);
            CSkillUp solver = new CSkillUp();
            solver.solve(1, in, out);
            out.close();
      }

      static class CSkillUp {
            long[][] dp;

            long rec(int[][] mat, int index, int curr, int k) {

                  String str = Integer.toBinaryString(curr);

                  int[] sum = new int[mat[0].length - 1];

                  int ii = 0;
                  for (int i = str.length() - 1; i >= 0; i--) {
                        if (str.charAt(i) == '1') {
                              for (int j = 1; j < mat[ii].length; j++) {
                                    sum[j - 1] += mat[ii][j];
                              }
                        }
                        ii++;
                  }
                  int min = sum[0];
                  for (int i = 0; i < mat[0].length - 1; i++) {
                        min = Math.min(sum[i], min);
                  }
                  if (min >= k) {
                        return 0;
                  }
                  if (index >= mat.length) {
                        return 100000000000L;
                  }
                  if (dp[curr][index] != -1) {
                        return dp[curr][index];
                  }


                  long a1 = rec(mat, index + 1, curr, k);
                  long a2 = (long) mat[index][0] + rec(mat, index + 1, curr + (1 << index), k);
                  dp[curr][index] = Math.min(a1, a2);
                  return Math.min(a1, a2);
            }

            public void solve(int testNumber, InputReader in, OutputWriter out) {
                  int n = in.nextInt();
                  int m = in.nextInt();
                  int x = in.nextInt();
                  int mat[][] = new int[n][m + 1];

                  for (int i = 0; i < n; i++) {
                        for (int j = 0; j <= m; j++) {
                              mat[i][j] = in.nextInt();
                        }
                  }
                  Arrays.sort(mat, new Comparator<int[]>() {

                        public int compare(int[] ints, int[] t1) {
                              return Integer.compare(ints[0], t1[0]);
                        }
                  });

                  dp = new long[9000][n];
                  for (int i = 0; i < 9000; i++) {
                        Arrays.fill(dp[i], -1);
                  }
                  long ans = rec(mat, 0, 0, x);
                  if (ans >= 100000000000L || ans < 0) {
                        out.printLine("-1");
                  } else {
                        out.printLine(ans);
                  }


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

            public void printLine(long i) {
                  writer.println(i);
            }

      }

      static class InputReader {
            private InputStream stream;
            private byte[] buf = new byte[1024];
            private int curChar;
            private int numChars;

            public InputReader(InputStream stream) {
                  this.stream = stream;
            }

            public int read() {
                  if (numChars == -1)
                        throw new InputMismatchException();

                  if (curChar >= numChars) {
                        curChar = 0;
                        try {
                              numChars = stream.read(buf);
                        } catch (IOException e) {
                              throw new InputMismatchException();
                        }
                        if (numChars <= 0)
                              return -1;
                  }

                  return buf[curChar++];
            }

            public int nextInt() {
                  int c = read();

                  while (isSpaceChar(c))
                        c = read();

                  int sgn = 1;

                  if (c == '-') {
                        sgn = -1;
                        c = read();
                  }

                  int res = 0;

                  do {
                        if (c < '0' || c > '9')
                              throw new InputMismatchException();

                        res *= 10;
                        res += c & 15;

                        c = read();
                  } while (!isSpaceChar(c));

                  return res * sgn;
            }

            public boolean isSpaceChar(int c) {
                  return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            }

      }
}
