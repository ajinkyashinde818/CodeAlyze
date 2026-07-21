import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();

        int n = sc.nextInt();
        int[][] d = new int[n][2];

        for (int i = 0; i < n; i++) {
            d[i][0] = sc.nextInt();
            d[i][1] = sc.nextInt();
        }

        boolean isAns = false;
        for (int i = 0; i < n-2; i++) {
            boolean isTmp = true;

            for (int j = 0; j < 3; j++) {
                if (d[i+j][0] != d[i+j][1])
                    isTmp = false;
            }

            if (isTmp == true)
                isAns = true;
        }

        System.out.println(isAns ? "Yes" : "No");
    }

    static class MyScanner {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
        StringTokenizer tokenizer;

        String next() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
            } catch (IOException ignored) {
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
