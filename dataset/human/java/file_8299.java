import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();

        int a = sc.nextInt();
        int b = sc.nextInt();

        long[] x = {a, 1};
        long[] y = {b, 1};
        while (x[0] != y[0]) {
            if (x[0] > y[0]) {
                y[0] = b * ++y[1];
            } else {
                x[0] = a * ++x[1];
            }
        }

        System.out.println(x[0]);
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
