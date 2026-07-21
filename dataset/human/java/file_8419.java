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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int[] pos;
        int[] what;
        int count;
        int len;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            int left = 0;
            int right = n;
            pos = new int[4 * n + 10];
            what = new int[4 * n + 10];
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (enough(middle, a)) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            out.println(right);
        }

        private boolean enough(int alphabet, int[] a) {
            count = 0;
            len = 0;
            outer:
            for (int cur : a) {
                if (cur > len) {
                    len = cur;
                } else {
                    if (cur < len) {
                        while (count > 0 && pos[count - 1] >= cur) {
                            --count;
                        }
                        len = cur;
                    }
                    if (alphabet == 1) {
                        return false;
                    }
                    for (int at = cur - 1; at >= 0; --at) {
                        if (count == 0 || pos[count - 1] < at) {
                            pos[count] = at;
                            what[count] = 1;
                            ++count;
                            continue outer;
                        } else {
                            if (what[count - 1] + 1 < alphabet) {
                                ++what[count - 1];
                                continue outer;
                            }
                            --count;
                        }
                    }
                    return false;
                }
            }
            return true;
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
