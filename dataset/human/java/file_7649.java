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
import java.util.ArrayList;
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
            DTeleporter solver = new DTeleporter();
            solver.solve(1, in, out);
            out.close();
      }

      static class DTeleporter {
            ArrayList<Integer>[] list;
            int cycleNode;
            boolean[] vis;
            int dis;
            int height = -1;

            void dfs(int u, int h) {
                  if (vis[u]) {
                        cycleNode = u;
                        dis = h;
                        return;
                  }
                  vis[u] = true;
                  for (int v : list[u]) {
                        dfs(v, h + 1);
                  }
            }

            void getLen(int u, int h) {
                  if (vis[u]) {
                        height = h;
                        return;
                  }
                  vis[u] = true;
                  for (int v : list[u]) {
                        getLen(v, h + 1);
                  }
            }

            int getNode(int u, int h, int curr) {
                  if (curr == h) {
                        return u;
                  }
                  if (vis[u]) {
                        return -1;
                  }
                  vis[u] = true;

                  return getNode(list[u].get(0), h, curr + 1);

            }

            public void solve(int testNumber, InputReader in, OutputWriter out) {
                  int n = in.nextInt();
                  long k = in.nextLong();
                  int arr[] = in.nextIntArray(n);
                  list = new ArrayList[n + 1];
                  for (int i = 0; i <= n; i++) {
                        list[i] = new ArrayList();
                  }
                  for (int i = 0; i < n; i++) {
                        list[i + 1].add(arr[i]);
                  }

                  vis = new boolean[n + 1];
                  cycleNode = -1;
                  dfs(1, 0);
                  vis = new boolean[n + 1];
                  getLen(cycleNode, 0);

//        out.printLine(cycleNode+" "+dis+" "+height);
                  if (k < (long) dis - 1) {
                        vis = new boolean[n + 1];
                        out.printLine(getNode(1, (int) k, 0));
                  } else {
                        k = k - (long) dis;
                        k = k % (long) height;

                        vis = new boolean[n + 1];
                        out.printLine(getNode(cycleNode, (int) k, 0));
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

            public void close() {
                  writer.close();
            }

            public void printLine(int i) {
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

            public int[] nextIntArray(int arraySize) {
                  int array[] = new int[arraySize];

                  for (int i = 0; i < arraySize; i++)
                        array[i] = nextInt();

                  return array;
            }

            public long nextLong() {
                  int c = read();

                  while (isSpaceChar(c))
                        c = read();

                  int sign = 1;

                  if (c == '-') {
                        sign = -1;

                        c = read();
                  }

                  long result = 0;

                  do {
                        if (c < '0' || c > '9')
                              throw new InputMismatchException();

                        result *= 10;
                        result += c & 15;

                        c = read();
                  } while (!isSpaceChar(c));

                  return result * sign;
            }

            public boolean isSpaceChar(int c) {
                  return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            }

      }
}
