import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();

        long n = sc.nextLong();

        Vector<Long> vector = new Vector<>();
        long i = 2;
        while (i*i <= n) {
            if (n % i == 0) {
                vector.add(i);
                n /= i;
            } else {
                i++;
            }
        }
        if (n > 1)
            vector.add(n);
        vector.add(-1l);  // 番兵

        long ans = 0;
        long num = vector.get(0);
        int cnt = 1;
        for (int j = 1; j < vector.size(); j++) {
            long tmp = vector.get(j);
            if (num == tmp) {
                cnt++;
            } else {
                int cur = 1;
                while (cnt >= cur) {
                    cnt -= cur++;
                    ans++;
                }
                cnt = 1;
                num = tmp;
            }
        }

        System.out.println(ans);
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
