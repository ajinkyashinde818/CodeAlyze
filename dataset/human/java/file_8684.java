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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BKThCommonDivisor solver = new BKThCommonDivisor();
        solver.solve(1, in, out);
        out.close();
    }

    static class BKThCommonDivisor {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a = in.nextInt(), b = in.nextInt();
            int k = in.nextInt();

            int answer = -1;
            for (int i = NumberTheory.gcd(a, b); i >= 1; i--) {
                if (a % i == 0 && b % i == 0) {
                    k--;
                }
                if (k == 0) {
                    answer = i;
                    break;
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

    static class NumberTheory {
        public static int gcd(int a, int b) {
            int c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
        }

    }
}
