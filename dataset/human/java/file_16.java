import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DCrossing solver = new DCrossing();
        solver.solve(1, in, out);
        out.close();
    }

    static class DCrossing {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            for (int k = 2; k <= 448; k++) {
                if (k * (k - 1) == 2 * n) {
                    out.println(YES);
                    out.println(k);
                    List<List<Integer>> sets = new ArrayList<>(k);
                    for (int i = 0; i < k; i++) {
                        sets.add(new ArrayList<>());
                    }

                    int m = 0;
                    for (int i = 0; i < k; i++) {
                        for (int j = i + 1; j < k; j++) {
                            m++;
                            sets.get(i).add(m);
                            sets.get(j).add(m);
                        }
                    }

                    for (int i = 0; i < k; i++) {
                        out.print(sets.get(i).size());
                        for (int j = 0; j < sets.get(i).size(); j++) {
                            out.print(' ');
                            out.print(sets.get(i).get(j));
                        }
                        out.println();
                    }
                    return;
                }
            }
            out.println(NO);
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

    }
}
