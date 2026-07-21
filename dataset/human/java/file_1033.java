import java.io.*;
import java.util.*;

class Main {
    static Scanner scanner = new Scanner();
    static long mod = 1000000007;

    public static void main(String[]$) throws IOException {
        int n = scanner.nextInt();
        char[] s = scanner.next().toCharArray();
        int m = 2 * n;

        boolean[] b = new boolean[m];
        long c = 0, d = 0;
        for (int i = 0; i < m; i++) {
            if ((s[i] == 'B') == (c % 2 == 0)) {
                b[i] = true;
                c++;
                d++;
            } else {
                c--;
            }
        }
        if (d != n) {
            System.out.println(0);
            return;
        }
        c = 0;
        long ans = 1;
        for (int i = m - 1; i >= 0; i--) {
            if (b[i]) {
                ans = ans * c % mod;
                c--;
            } else {
                c++;
            }
        }
        long fac = 1;
        for (int i = 2; i <= n; i++) {
            fac = fac * i % mod;
        }
        System.out.println(ans * fac % mod);
    }

    static class Scanner {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
        StringTokenizer tokenizer;

        String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}
