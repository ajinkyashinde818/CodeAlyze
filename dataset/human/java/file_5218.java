import java.io.*;
import java.text.*;
import java.util.*;

public class Main {

    static InputReader sc = new InputReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        solver s = new solver();
        int t = 1;
        while (t > 0) {
            s.solve();
            t--;
        }
        out.close();
    }

    static class InputReader {

        public BufferedReader br;
        public StringTokenizer token;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream), 32768);
            token = null;
        }

        public String sn() {
            while (token == null || !token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return token.nextToken();
        }

        public int ni() {
            return Integer.parseInt(sn());
        }

        public String snl() throws IOException {
            return br.readLine();
        }

        public long nlo() {
            return Long.parseLong(sn());
        }

        public double nd() {
            return Double.parseDouble(sn());
        }

        public int[] na(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.ni();
            return a;
        }

        public long[] nal(int n) {
            long a[] = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nlo();
            return a;
        }
    }

    static int inf = 5000013;

    static class solver {
        DecimalFormat df = new DecimalFormat("0.00000000");
        long max = 1000000000000000l, min = -10000000000000000l;
        long mod = (long) 1e9 + 7;

        long pro(long a, long b) {
            return (a % mod * b % mod) % mod;
        }

        long add(long a, long b) {
            return (a + b) % mod;
        }

        long sub(long a, long b) {
            return ((a % mod - b % mod) + mod) % mod;
        }

        long ncr3(long n) {
            return (n * (n - 1) * (n - 2)) / 6l;
        }

        long ncr2(long n) {
            return n * (n - 1) / 2l;
        }

        int modPow(int x, int y) {
            int res = 1;
            while (y > 0) {
                if (y % 2 != 0)
                    res *= x;
                x = x * x;
                y = y >> 1;
            }
            return res;
        }

        int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        final int maxn = 1000005;

        void solve() {
            char s[] = sc.sn().toCharArray();
            int n = s.length;
            Deque<Character> cur = new LinkedList<>();
            Deque<Character> rev = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                cur.addLast(s[i]);
                rev.addFirst(s[i]);
            }
            int q = sc.ni();
            while (q-- > 0) {
                int t = sc.ni();
                if (t == 1) {
                    Deque<Character> d = cur;
                    cur = rev;
                    rev = d;
                } else {
                    int f = sc.ni();
                    char c = sc.sn().charAt(0);
                    if (f == 1) {
                        cur.addFirst(c);
                        rev.addLast(c);
                    } else {
                        cur.addLast(c);
                        rev.addFirst(c);
                    }
                }
            }
            while (!cur.isEmpty())
                out.print(cur.pollFirst());
        }
    }
}
