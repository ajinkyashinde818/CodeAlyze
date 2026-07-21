import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber , InputReader in , PrintWriter out){
            int n = in.nextInt();
            int m = in.nextInt();
            int[] arr = new int[n+1];
            for (int i = 0; i <m ; i++) {
                arr[in.nextInt()] = 1;
            }
           long[] dp = new long[n+1];
            dp[0] = 1;
            if (arr[1] == 0) dp[1] = 1;
            for (int i = 2 ; i <=n ; i++) {
                dp[i] = dp[i-1]+dp[i-2];
                dp[i]%=1000000000+7;
                if (arr[i] == 1) dp[i] = 0;
            }
            out.println(dp[n] %(1000000000+7));






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
