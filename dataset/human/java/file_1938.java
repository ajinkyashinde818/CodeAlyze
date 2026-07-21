import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private static final int INF = Integer.MAX_VALUE / 2;

    private static class Score {
        public int seq;
        public int p;
        public int c;
        public Score(int seq, int p, int c) {
            this.seq = seq;
            this.p = p;
            this.c = c;
        }
        public String toString() {
            return "[" + seq + ", " + p + ", " + c + "]";
        }
    }
    private int min = Integer.MAX_VALUE;
    private void solve(Scanner sc) {
        int D = sc.nextInt();
        // (1+2+..+10)*100+10*10^6 = 5500 + 10^7 < Integer.MAX_VALUE
        int G = sc.nextInt();
        List<Score> list = new ArrayList<>();
        for (int i = 0; i < D; ++i) {
            Score s = new Score(i + 1, sc.nextInt(), sc.nextInt());
            list.add(s);
        }
        search(G, list, 0);
        _out.println(min);
    }
    private Set<String> memo = new HashSet<>();
    private void search(int g, List<Score> list, int cnt) {
        String key = g + ":" + cnt;
        if (memo.contains(key)) {
            return;
        }
        memo.add(key);

        if (g <= 0) {
            if (cnt < min) {
                min = cnt;
            }
            return;
        }

        for (Score s : list) {
            if (s.p > 0) {
                int i = 0;
                while (s.p - i > 0 && g - s.seq * 100 * i > 0) {
                    ++i;
                }
                s.p -= i;
                if (s.p == 0) {
                    search(g - s.seq * 100 * i - s.c, list, cnt + i);
                } else {
                    search(g - s.seq * 100 * i, list, cnt + i);
                }
                s.p += i;
            }
        }
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}
