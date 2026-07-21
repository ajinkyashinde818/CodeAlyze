import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.function.*;
import java.util.stream.Collectors;

public class Main {

    static MyScanner sc;
    private static PrintWriter out;
    static long M = 1000000007;

    public static void main(String[] s) throws Exception {
        StringBuilder stringBuilder = new StringBuilder();
//        stringBuilder.append("20");
//        for (int k = 1 ; k <= 20 ; k++) {
//            stringBuilder.append(" " + k + " 2 ");
//        }
        if (stringBuilder.length() == 0) {
            sc = new MyScanner(System.in);
        } else {
            sc = new MyScanner(new BufferedReader(new StringReader(stringBuilder.toString())));
        }

        out = new PrintWriter(new OutputStreamWriter(System.out));
        initData();
        solve();
        out.flush();
    }

    private static void initData() {

    }

    static int min(int l) {
        long x = 1 << (l - 1);
        char[] res = new char[l];
        int min = 400;
        for (int p = 0; p < x; p++) {
            for (int r = 0; r < l - 1; r++) {
                res[r] = (char) ('a' + ((p & (1 << r)) > 0 ? 1 : 0));
            }
            res[l - 1] = 'b';
            min = Math.min(min, cr(res));
            res[l - 1] = 'a';
            min = Math.min(min, cr(res));
        }
        return min;
    }

    private static int cr(char[] res) {
        int max = 1;
        for (int l = 0; l < res.length; l++) {
            int cur = 1;
            for (int k = 1; ; k++) {
                if (l + k >= res.length || l - k < 0 || res[l + k] != res[l - k]) break;
                cur += 2;
            }
            max = Math.max(cur, max);
            cur = 0;
            for (int k = 0; ; k++) {
                if (l + k >= res.length || l - k - 1 < 0 || res[l + k] != res[l - k - 1]) break;
                cur += 2;
            }
            max = Math.max(cur, max);
        }

        return max;
    }


    private static void solve() {
       String a = sc.next();
       String b = sc.next();
       if (a.compareTo(b) == 0 ) {
           out.println("=");
       }
        if (a.compareTo(b) > 0 ) {
            out.println(">");
        }
        if (a.compareTo(b) < 0 ) {
            out.println("<");
        }
    }


    private static boolean valid(char[] res) {
        int x = 0;
        for (char p : res) {
            if (p == 'a') x++;
        }
        return x > 0 && x != res.length;
    }


    private static class P {
        private boolean b;
        private final int ind;
        private final int parent;

        public P(int i, boolean b, int par) {
            this.ind = i;
            this.b = b;
            this.parent = par;

        }
    }

    private static void dfs(int start, int[][] neig, Consumer<int[]> onAdd, Consumer<int[]> onRemove) {
        ArrayList<P> toVisit = new ArrayList<P>(3000);
        toVisit.add(new P(start, true, -1));
        boolean[] vis = new boolean[neig.length];
        vis[start] = true;
        int[] level = new int[neig.length];
        while (toVisit.size() > 0) {
            P ppr = toVisit.remove(toVisit.size() - 1);
            if (!ppr.b) {
                onRemove.accept(new int[]{ppr.ind, level[ppr.ind], ppr.parent});
                continue;
            }
            ppr.b = false;
            int i = ppr.ind;
            toVisit.add(ppr);
            onAdd.accept(new int[]{ppr.ind, level[ppr.ind], ppr.parent});
            for (int kk : neig[i]) {
                if (!vis[kk]) {
                    vis[kk] = true;
                    level[kk] = level[i] + 1;
                    toVisit.add(new P(kk, true, i));
                }
            }
        }


    }


    private static int[][] tr(int n) {
        int[][] x = new int[2][n - 1];
        for (int i = 0; i < n - 1; i++) {
            x[0][i] = sc.nextInt() - 1;
            x[1][i] = sc.nextInt() - 1;
        }
        int[][] neig = pn(x, n);
        return neig;
    }

    private static int[][] pn(int[][] x, int n) {
        int[] ct = new int[n];
        int[][] res = new int[n][];
        for (int v : x[0]) {
            ct[v]++;
        }
        for (int v : x[1]) {
            ct[v]++;
        }
        for (int l = 0; l < n; l++) {
            res[l] = new int[ct[l]];
        }
        for (int i = 0; i < x[0].length; i++) {
            res[x[0][i]][--ct[x[0][i]]] = x[1][i];
            res[x[1][i]][--ct[x[1][i]]] = x[0][i];
        }
        return res;
    }


    private static void printa(long[] res) {
        for (long i : res) {
            out.print(i);
            out.print(' ');
        }
    }

    private static void solveT() {
        int t = sc.nextInt();
        while (t-- > 0) {
            solve();
            out.flush();
        }
    }


    private static int gcd(int l, int l1) {
        if (l > l1) return gcd(l1, l);
        if (l == 0) return l1;
        return gcd(l1 % l, l);
    }

    private static long pow(long a, long b, long m) {
        if (b == 0) return 1;
        if (b == 1) return a;
        long pp = pow(a, b / 2, m);
        pp *= pp;
        pp %= m;
        return (pp * (b % 2 == 0 ? 1 : a)) % m;
    }

    private static void sort(int[] t, IntUnaryOperator op1, IntUnaryOperator op2) {
        sort(t, (k1, k2) -> {
            int p1 = op1.applyAsInt(k1);
            int p2 = op1.applyAsInt(k2);
            if (p1 != p2) {
                return p1 - p2;
            } else {
                return op2.applyAsInt(k1) - op2.applyAsInt(k2);
            }
        });
    }

    private static void sort(int[] t, IntBinaryOperator op) {
        List<Integer> k = Arrays.stream(t).boxed().collect(Collectors.toList());
        k.sort(op::applyAsInt);
        for (int i = 0; i < t.length; i++) {
            t[i] = k.get(i);
        }
    }

    static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        MyScanner(BufferedReader br) {
            this.br = br;
        }

        public MyScanner(InputStream in) {
            this(new BufferedReader(new InputStreamReader(in)));
        }

        void findToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        String next() {
            findToken();
            return st.nextToken();
        }

        int[] na(int n) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextInt();
            }
            return k;
        }

        long[] nl(int n) {
            long[] k = new long[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextLong();
            }
            return k;
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
    }

}
