import java.io.*;
import java.util.*;

public class Main {

    private static FastReader in = new FastReader(System.in);
    private static PrintWriter out = new PrintWriter(System.out);

    private static final long MOD = (long) 1e9 + 7;

    public static void main(String[] args) {
        solve();
        out.flush();
    }

    private static void solve() {
        int n = in.nextInt();
        long k = in.nextLong();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }

        int[] towns = new int[n];
        Arrays.fill(towns, -1);
        int currentTown = 0;
        towns[0] = 0;
        int i = 0;
        while (true) {
            int next = a[currentTown];
            if (towns[next] != -1) {
                break;
            }

            i++;
            towns[next] = i;

            currentTown = next;
        }

        long cycle = Arrays.stream(towns).filter(num -> num != -1).count();
        int nextTown = a[currentTown];
        cycle -= towns[nextTown];

//        out.println("next town: " + nextTown);
//        out.println("cycle: " + cycle);
//        out.println("towns: " + Arrays.toString(towns));

        // hasn't looped once
        if (k < towns[nextTown] + cycle) {
            int ans = -1;
            for (int j = 0; j < n; j++) {
                if (towns[j] == k) {
                    ans = j + 1;
                    break;
                }
            }
            out.println(ans);
            return;
        }

        // has looped
        k -= towns[nextTown];
        k %= cycle;
        k += towns[nextTown];

        int ans = -1;
        for (int j = 0; j < n; j++) {
            if (towns[j] == k) {
                ans = j + 1;
                break;
            }
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
