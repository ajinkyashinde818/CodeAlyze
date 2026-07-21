import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
            int N = in.nextInt(), M = in.nextInt(), X = in.nextInt();
            int total = 0;
            int cost[] = new int[N];
            int a[][] = new int[N][M];
            for (int i = 0; i < N; i++) {
                cost[i] = in.nextInt();
                for (int j = 0; j < M; j++) {
                    a[i][j] = in.nextInt();
                    total += a[i][j];
                }
            }
            int min = Integer.MAX_VALUE;
            for (int i = (1 << N) - 1; i >= 0; i--) {
                String s = Integer.toBinaryString(i);
                while (s.length() < N) {
                    s = "0" + s;
                }
                int current = 0;
                int knowledge[] = new int[M];
                for (int j = 0; j < N; j++) {
                    if (s.charAt(j) == '1') {
                        current += cost[j];
                        for (int k = 0; k < M; k++) {
                            knowledge[k] += a[j][k];
                        }
                    }
                }
                boolean possible = true;
                for (int j = 0; j < M; j++) {
                    if (knowledge[j] < X) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    min = Math.min(min, current);
                }
            }
            if (min == Integer.MAX_VALUE) {
                out.printLine(-1);
            } else {
                out.printLine(min);
            }
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tokenizer = null;

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(in.readLine());
                }
                return tokenizer.nextToken();
            } catch (IOException e) {
                return null;
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class OutputWriter {
        PrintWriter writer;

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
