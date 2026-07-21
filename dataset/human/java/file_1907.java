import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {
        public void solve(InputReader in, PrintWriter out) {
            int D = in.nextInt();
            int G = in.nextInt() / 100;
            int p[] = new int[D];
            int c[] = new int[D];
            for (int i = 0; i < D; i++) {
                p[i] = in.nextInt();
                c[i] = in.nextInt() / 100;
            }

            int ans = Integer.MAX_VALUE;
            for (int mask = 0; mask < 1 << D; mask++) {
                int sum = 0; int cnt = 0; int rest_max = -1;
                for (int i = 0; i < D; i++) {
                    if ((mask >> i & 1) == 1) {
                        sum += p[i]*(i + 1) + c[i];
                        cnt += p[i];
                    } else {
                        rest_max = i;
                    }
                }
                if (rest_max >= 0) {
                    for (int i = 1; i < p[rest_max]; i++) {
                        if (sum >= G) {
                            break;
                        } else {
                            sum += rest_max + 1;
                            cnt += 1;
                        }
                    }
                }
                if (sum >= G) {
                    ans = Math.min(cnt, ans);
                }
            }

            out.println(ans);
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
