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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CAllGreen solver = new CAllGreen();
        solver.solve(1, in, out);
        out.close();
    }

    static class CAllGreen {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int d = in.nextInt(), g = in.nextInt() / 100;
            int[] p = new int[d];
            int[] c = new int[d];
            for (int i = 0; i < d; i++) {
                p[i] = in.nextInt();
                c[i] = in.nextInt() / 100;
            }

            int answer = Integer.MAX_VALUE;
            for (int s = 0; s < (1 << d); s++) {
                int problems = 0;
                int points = 0;
                for (int i = 0; i < d; i++) {
                    if (((s >> i) & 1) > 0) {
                        problems += p[i];
                        points += p[i] * (i + 1);
                        points += c[i];
                    }
                }
                if (points >= g) {
                    answer = Math.min(answer, problems);
                    continue;
                }
                for (int i = d - 1; i >= 0; i--) {
                    if (((s >> i) & 1) == 0) {
                        if (p[i] * (i + 1) + points >= g) {
                            problems += (g - points + i) / (i + 1);
                            answer = Math.min(answer, problems);
                            break;
                        }
                    }
                }
            }

            out.println(answer);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
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

    }
}
