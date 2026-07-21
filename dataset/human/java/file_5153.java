import java.io.*;
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
        String s = in.next();
        int q = in.nextInt();

        StringBuilder sbPrefix = new StringBuilder();
        StringBuilder sbSuffix = new StringBuilder();

        boolean flipped = false;
        for (int i = 0; i < q; i++) {
            int type = in.nextInt();
            if (type == 1) {
                flipped = !flipped;
            } else {
                int f = in.nextInt();
                if (f == 1) {
                    if (!flipped) {
                        sbPrefix.append(in.next());
                    } else {
                        sbSuffix.append(in.next());
                    }
                } else {
                    if (!flipped) {
                        sbSuffix.append(in.next());
                    } else {
                        sbPrefix.append(in.next());
                    }
                }
            }
        }

        String ans;
        if (!flipped) {
            ans = sbPrefix.reverse().append(s).append(sbSuffix).toString();
        } else {
            ans = sbSuffix.reverse().append(new StringBuilder(s).reverse()).append(sbPrefix).toString();
        }

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
