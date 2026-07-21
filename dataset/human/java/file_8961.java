import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        InputReader.OutputWriter out = new InputReader.OutputWriter(outputStream);


        int n = in.nextInt();
        int m = in.nextInt();
        int mod = 1_000_000_000 + 7;
        int [] a = new int[n];
        for (int i = 0; i < m; i++) {
            a[in.nextInt() - 1] = 1;
        }
        if(n == 1) {
            out.println(1);
            out.flush();
            return;
        }
        int [] dp = new int[n];
        if(a[0] == 1) {
            if(a[1] != 1) {
                dp[1] = 1;
            }
        }
        else {
            if(a[1] == 1) dp[1] = 0;
            else {
                dp[0] = 1;
                dp[1] = 2;
            }
        }
        for (int i = 2; i < n; i++) {
            dp[i] = (dp[i-1] + dp[i-2])%mod;
            if (a[i] == 1) {
                dp[i] = 0;
            }
        }
        
        out.println(dp[n-1]);
        out.flush();
    }

}

class InputReader extends BufferedReader {
    StringTokenizer tokenizer;

    public InputReader(InputStream inputStream) {
        super(new InputStreamReader(inputStream), 32768);
    }

    public InputReader(String filename) {
        super(new InputStreamReader(Thread.currentThread().getContextClassLoader().getResourceAsStream(filename)));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(readLine());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        }
        return tokenizer.nextToken();
    }

    public Integer nextInt() {
        return Integer.valueOf(next());
    }
    public Long nextLong() {return  Long.valueOf(next());}

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream outputStream) {
            super(outputStream);
        }

        public OutputWriter(Writer writer) {
            super(writer);
        }

        public OutputWriter(String filename) throws FileNotFoundException {
            super(filename);
        }

        public void close() {
            super.close();
        }
    }
}
