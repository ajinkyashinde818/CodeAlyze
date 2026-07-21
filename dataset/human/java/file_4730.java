import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static FastReader in = new FastReader(System.in);
    private static PrintWriter out = new PrintWriter(System.out);

    private static final long MOD = (long) 1e9 + 7;

    public static void main(String[] args) {
        solve();
        out.flush();
    }

    private static void solve() {
        solveForN(in.next());
    }

    private static void solveForN(String n) {
        String s = "0" + n;
        char[] ch = s.toCharArray();
        int[] a = new int[ch.length];
        for (int i = 0; i < ch.length; i++) {
            a[i] = ch[i] - '0';
        }

        int ans = 0;
        // 下から見るんかーい
        for (int i = a.length - 1; i > 0; i--) {
            if (a[i] == 5 && a[i - 1] >= 5) {
                a[i - 1]++;
                a[i] -= 10;
            } else if (a[i] > 5) {
                a[i - 1]++;
                a[i] -= 10;
            }
            ans += Math.abs(a[i]);
        }
        ans += Math.abs(a[0]);

        // out.println(Arrays.toString(a));

        out.println(ans);
    }

    // https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        FastReader(InputStream inputStream) {
            br = new BufferedReader(new
                    InputStreamReader(inputStream));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException  e) {
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

        // https://qiita.com/masakinpo/items/5f77f2a879578a85a0bb
        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}
