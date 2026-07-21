import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        BTwoAnagrams solver = new BTwoAnagrams();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTwoAnagrams {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            char[] s = in.string().toCharArray();
            char[] t = in.string().toCharArray();
            Arrays.sort(s);
            Arrays.sort(t);
            ArrayUtil.reverse(t, 0, t.length - 1);
            if (String.valueOf(s).compareTo(String.valueOf(t)) < 0) {
                out.println(YES);
            } else {
                out.println(NO);
            }
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static void reverse(char[] a, int left, int right) {
            while (left < right) {
                char temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
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

    }
}
