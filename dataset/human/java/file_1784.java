import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int D;
    static int G;
    static int[] P;
    static int[] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        D = sc.nextInt();
        G = sc.nextInt();
        P = new int[D];
        C = new int[D];
        for (int i = 0; i < D; i++) {
            P[i] = sc.nextInt();
            C[i] = sc.nextInt();
        }

        System.out.println(solve());
    }

    static int solve() {
        int[] full = new int[D];
        for (int i = 0; i < D; i++) {
            full[i] = (i+1) * P[i] * 100 + C[i];
        }

        int ans = Integer.MAX_VALUE;
        for (int bit = 0; bit < 1 << D; bit++) {
            int prob = 0;
            int score = 0;
            for (int i = 0; i < D; i++) {
                int b = 1 << i;
                if( (bit & b) > 0 ) {
                    prob += P[i];
                    score += full[i];
                }
            }

            if( score < G ) {
                int plus = fill(score, bit);
                prob += plus;
            }
            ans = Math.min(prob, ans);
        }
        return ans;
    }

    static int fill(int score, int bit) {
        int last = G - score;
        int used = 0;
        for (int i = D-1; i >= 0; i--) {
            int b = 1 << i;
            if( (bit & b) > 0 ) continue;

            for (int j = 0; j < P[i]; j++) {
                last-= (i+1)*100;
                used++;

                if( last <= 0 ) return used;
            }
            last -= C[i];
            if( last <= 0 ) return used;
        }
        return used;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}
