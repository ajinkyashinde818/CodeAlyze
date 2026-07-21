import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static int toori = 0;

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        boolean[] broken = new boolean[n + 1];

        for (int i = 0; i < m; i++) {
            broken[sc.nextInt()] = true;
        }

        long[] dp = new long[n + 2];
        dp[n + 1] = 0;
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (broken[i]) {
                continue;
            }
            dp[i] = (dp[i + 1] + dp[i + 2]) % 1000000007;
        }

        out.println(dp[0]);

        out.flush();

    }

    static class Toi {
        public int x;
        public int y;

        public Toi(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (this == obj) {
                return true;
            }

            if (this.getClass() != obj.getClass()) {
                return false;
            }

            Toi toi = (Toi) obj;
            return x == toi.x && y == toi.y;
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
