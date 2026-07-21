import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Twinkle Twinkle Little Star
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
            int a = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();
            ArrayList<Integer> array = new ArrayList<>();
            int gcd = 1;
            int index = 0;
            for (int i = 1; i <= a && i <= b; ++i) {
                if (a % i == 0 && b % i == 0) {
                    gcd = i;
                    array.add(gcd);
                    index++;
                    // out.println(gcd);
                }
            }
            Collections.sort(array);
            ArrayList<Integer> crray = new ArrayList<>();
            for (int i = array.size() - 1; i >= 0; i--) {
                int x = array.get(i);
                crray.add(x);
            }
            out.println(crray.get(k - 1));

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
