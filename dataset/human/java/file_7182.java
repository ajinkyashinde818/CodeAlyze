import java.io.*;
import java.util.*;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.max;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws Exception {
        int k = nextInt(), n = nextInt(), mx = 0;
        int a[] = na(n);
        for (int i = 1; i < n; i++) mx = max(mx, abs(a[i] - a[i - 1]));
        mx = max(mx, k - a[n - 1] + a[0]);
        out.print(k - mx);
    }


    // call it like this: lower_bound(a, x + 1) ( /!\ + 1 )
    public static int lower_bound(int[] a, int v) {
        int low = -1, high = a.length;
        while (high - low > 1) {
            int h = high + low >>> 1;
            if (a[h] >= v) {
                high = h;
            } else {
                low = h;
            }
        }
        return high;
    }

    private String getFraction(int a, int b) {
        assert b != 0;
        String sign = (a > 0 && b > 0) || (a < 0) && (b < 0) ? "+" : "-";
        a = abs(a);
        b = abs(b);
        int gcd = gcd(a, b);
        return sign + (a / gcd) + "/" + (b / gcd);
    }

    private int gcd(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

    public static int[] radixSort(int[] f) {
        if (f.length < 100) {
            Arrays.sort(f);
            return f;
        }
        int[] to = new int[f.length];
        {
            int[] b = new int[65537];
            for (int i = 0; i < f.length; i++) b[1 + (f[i] & 0xffff)]++;
            for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
            for (int i = 0; i < f.length; i++) to[b[f[i] & 0xffff]++] = f[i];
            int[] d = f;
            f = to;
            to = d;
        }
        {
            int[] b = new int[65537];
            for (int i = 0; i < f.length; i++) b[1 + (f[i] >>> 16)]++;
            for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
            for (int i = 0; i < f.length; i++) to[b[f[i] >>> 16]++] = f[i];
            int[] d = f;
            f = to;
            to = d;
        }
        return f;
    }

    // return all subsets in range 0..n-1 [ {0}, {1,4}, {2, 5}, ..., {1,2,..,n}, {n} ]
    List<List<Integer>> gen_subsets(int n) {
        List<List<Integer>> h = new ArrayList<>();
        for (int mask = 0; mask < (1 << n); mask++) {
            List<Integer> tmp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    tmp.add(i);
                }
            }
            h.add(tmp);
        }
        return h;
    }

    public static long pow(long a, long n, long mod) {
        long ret = 1;
        int x = 63 - Long.numberOfLeadingZeros(n);
        for (; x >= 0; x--) {
            ret = ret * ret % mod;
            if (n << 63 - x < 0)
                ret = ret * a % mod;
        }
        return ret;
    }

    class BIT {
        int BITree[];

        public BIT(int n) {
            BITree = new int[n + 1];
            for (int i = 1; i <= n; i++)
                BITree[i] = 0;
        }

        // sum [l, r]
        int getSum(int l, int r) {
            return getSum(r) - getSum(l - 1);
        }

        // sum [0, index]
        int getSum(int index) {
            int sum = 0;
            index = index + 1;
            while (index > 0) {
                sum += BITree[index];
                index -= index & (-index);
            }
            return sum;
        }

        // add val to range [l, r]
        void updateRange(int n, int val, int l, int r) {
            updateBIT(n, l, val);
            updateBIT(n, r + 1, -val);
        }

        void updateBIT(int n, int index, int val) {
            index = index + 1;
            while (index <= n) {
                BITree[index] += val;
                index += index & (-index);
            }
        }
    }

    public static boolean nextPermutation(Integer[] a) {
        int n = a.length;
        int i;
        for (i = n - 2; i >= 0 && a[i] >= a[i + 1]; i--) ;
        if (i == -1)
            return false;
        int j;
        for (j = i + 1; j < n && a[i] < a[j]; j++) ;
        int d = a[i];
        a[i] = a[j - 1];
        a[j - 1] = d;
        for (int p = i + 1, q = n - 1; p < q; p++, q--) {
            d = a[p];
            a[p] = a[q];
            a[q] = d;
        }
        return true;
    }

    void print(Object x) {
        out.print(String.valueOf(x));
        out.flush();
    }

    void println(Object x) {
        out.println(String.valueOf(x));
        out.flush();
    }

    private class MapCount<K> {
        Map<K, Integer> map;

        MapCount() {
            map = new HashMap<>();
        }

        public void add(K key) {
            map.put(key, map.containsKey(key) ? map.get(key) + 1 : 1);
        }

        public Integer getCount(K key) {
            return map.getOrDefault(key, 0);
        }

        public Set<K> keySet() {
            return map.keySet();
        }
    }

    // for Map with custom key/value, override toString in your custom class
    void printMap(Map map) {
        if (map.keySet().size() == 0) return;
        Object firstValue = map.keySet().iterator().next();
        if (map.get(firstValue) instanceof Queue || map.get(firstValue) instanceof List) {
            for (Object key : map.keySet()) {
                out.print(String.valueOf(key) + ": ");
                Collection values = (Collection) map.get(key);
                for (Object value : values) out.print(String.valueOf(value) + " ");
                out.println();
            }
        } else if (map.get(firstValue).getClass().isArray()) {
            for (Object key : map.keySet()) {
                out.print(String.valueOf(key) + ": ");
                Object[] values = (Object[]) map.get(key);
                for (Object value : values) out.print(String.valueOf(value) + " ");
                out.println();
            }
        } else {
            for (Object key : map.keySet()) {
                out.println(String.valueOf(key) + ": " + map.get(key));
            }
        }
    }

    private int[] na(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    private long[] nal(int n) throws IOException {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nextLong();
        return a;
    }

    int nextInt() throws IOException {
        return parseInt(next());
    }

    long nextLong() throws IOException {
        return parseLong(next());
    }

    double nextDouble() throws IOException {
        return parseDouble(next());
    }

    String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) throws Exception {
        try {
            boolean isLocal = false;
            if (isLocal) {
                in = new BufferedReader(new FileReader("solution.in"));
                out = new PrintWriter(new BufferedWriter(new FileWriter("solution.out")));
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(new OutputStreamWriter(System.out));
            }

            //long lStartTime = System.currentTimeMillis();
            new Main().solve();
            //long lEndTime = System.currentTimeMillis();
            //out.println("Elapsed time in seconds: " + (double)(lEndTime - lStartTime) / 1000.0);
            in.close();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}
