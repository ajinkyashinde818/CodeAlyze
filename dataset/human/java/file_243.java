import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.function.Supplier;

public class Main {

    static void solve() {
        int n = nextInt();
        long[] a = new long[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
            if (a[i] < 0) {
                count++;
                a[i] *= -1;
            }
        }
        long min = Long.MAX_VALUE;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i];
            if (a[i] < min)
                min = a[i];
        }
        if (count % 2 == 1)
            ans -= min * 2;
        out.println(ans);
    }

    static final int MOD = 1_000_000_007;
    static long[] fac, finv, inv;

    // 階乗(n!)
    static long factorial(long n) {
        long ans = 1;
        for (long i = n; i > 0; i--) {
            ans = ans * i % MOD;
        }
        return ans;
    }

    // nCkの初期化
    static void comInit(int max) {
        fac = new long[max];
        finv = new long[max];
        inv = new long[max];
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;

        for (int i = 2; i < max; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    // nCkの計算
    static long com(int n, int k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    static Map<Integer, List<Integer>> primeFactors = new HashMap<>();

    // 素因数分解
    static List<Integer> primeFactorize(int n) {
        if (primeFactors.containsKey(n))
            return primeFactors.get(n);

        List<Integer> list = new ArrayList<>();
        if (n % 2 == 0) {
            list.addAll(primeFactorize(n / 2));
            list.add(2);
        } else {
            boolean ok = true;
            for (int j = 3; j * j <= n; j += 2) {
                if (n % j == 0) {
                    list.addAll(primeFactorize(n / j));
                    list.addAll(primeFactorize(j));
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (n != 1)
                    list.add(n);
            }
        }

        primeFactors.put(n, Collections.unmodifiableList(list));
        return list;
    }

    // 2〜nまでの数値を素因数分解したmapを返す.
    // map: 数値 -> (素因数)
    // ex)
    // 2 -> (2)
    // 4 -> (2,2)
    // 12 -> (2,2,3)
    @Deprecated // primeFactorizeを使うべき
    static Map<Integer, List<Integer>> primeFactorizeTo(int n) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 2; i <= n; i++) {
            List<Integer> list = new ArrayList<>();
            int tmp = i;
            for (int j = i - 1; j > 1; j--) {
                if (tmp % j == 0) {
                    if (map.containsKey(j)) {
                        list.addAll(map.get(j));
                    } else {
                        list.add(j);
                    }
                    tmp /= j;
                }
            }
            if (tmp != 1)
                list.add(tmp);
            map.put(i, list);
        }
        return map;
    }

    static PrintWriter out;
    static Scanner sc;
    static boolean debugEnabled;
    static long start;
    static long end;

    static int[][] newIntArray(int h, int w, int value) {
        int[][] ret = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ret[i][j] = value;
            }
        }
        return ret;
    }

    static int nextInt() {
        return Integer.parseInt(sc.next());
    }

    static long nextLong() {
        return Long.parseLong(sc.next());
    }

    static String nextString() {
        return sc.next();
    }

    static int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    static long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        return a;
    }

    static List<Integer> nextIntList(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(nextInt());
        }
        return list;
    }

    static List<Double> nextDoubleList(int n) {
        List<Double> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add((double) nextInt());
        }
        return list;
    }

    static List<Long> nextLongList(int n) {
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(nextLong());
        }
        return list;
    }

    static char[][] nextCharArray(int h, int w) {
        char[][] c = new char[h][w];
        for (int i = 0; i < h; i++) {
            String str = nextString();
            for (int j = 0; j < w; j++) {
                c[i][j] = str.charAt(j);
            }
        }
        return c;
    }

    // 昇順
    static <T extends Comparable<? super T>> List<T> sort(List<T> list) {
        return sortAsc(list);
    }

    // 昇順
    static <T extends Comparable<? super T>> List<T> sortAsc(List<T> list) {
        Collections.sort(list);
        return list;
    }

    // 降順
    static <T extends Comparable<? super T>> List<T> sortDesc(List<T> list) {
        Collections.sort(list, (e1, e2) -> e2.compareTo(e1));
        return list;
    }

    // greatest common divisor
    // 最大公約数
    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // least common multiple
    // 最小公倍数
    static long lcm(long a, long b) {
        if (a > b) {
            return (a / gcd(a, b)) * b;
        } else {
            return (b / gcd(a, b)) * a;
        }
    }

    // least common multiple
    // 最小公倍数
    // 素因数分解されたListを引数とした場合
    static List<Integer> lcm(List<Integer> a, List<Integer> b) {
        List<Integer> ret = new ArrayList<>(a);
        List<Integer> tmp = new ArrayList<>(b);
        for (Integer i : a) {
            if (tmp.contains(i))
                tmp.remove(i);
        }
        ret.addAll(tmp);
        return ret;
    }

    // baseのn乗を計算を返す
    static int pow(int base, int n) {
        int ret = 1;
        for (int i = 0; i < n; i++) {
            ret *= base;
        }
        return ret;
    }

    // return n^k mod m
    static long powMod(long n, long k, long m) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return powMod(n, k - 1, m) * n % m;
        } else {
            long tmp = powMod(n, k / 2, m);
            return tmp * tmp % m;
        }
    }

    // intをlength桁のbit文字列に変換
    static String toBitString(int length, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = length - 1; i >= 0; i--) {
            if ((n >> i) % 2 == 1) {
                sb.append("1");
            } else {
                sb.append("0");
            }
        }
        return sb.toString();
    }

    static void setDebugEnabled() {
        String className = new Object() {
        }.getClass().getEnclosingClass().getSimpleName();

        if (!className.equals("Main"))
            debugEnabled = true;
    }

    static void debug(String msg) {
        if (debugEnabled)
            System.err.println(msg);
    }

    static void debug(Supplier<String> msg) {
        if (debugEnabled)
            System.err.println(msg.get());
    }

    static class UnionFind {
        int[] parent;

        UnionFind(int n) {
            parent = new int[n];
            init();
        }

        void init() {
            for (int i = 0; i < parent.length; i++) {
                parent[i] = i;
            }
        }

        int getRoot(int i) {
            if (parent[i] == i) {
                return i;
            } else {
                return parent[i] = getRoot(parent[i]);
            }
        }

        boolean isSame(int x, int y) {
            return getRoot(x) == getRoot(y);
        }

        void unit(int x, int y) {
            x = getRoot(x);
            y = getRoot(y);
            if (x != y) {
                parent[x] = y;
            }

        }
    }

    public static void main(String[] args) {
        preProcess();
        // System.exit(0)で終了した場合も、解答を出力するためにはshutdown hookの設定が必要
        // しかし、これを有効化すると100[msec]程度処理時間が長くなる
        // Runtime.getRuntime().addShutdownHook(new Thread(() -> postProcess()));
        solve();
        postProcess();
    }

    static void preProcess() {
        start = System.nanoTime();
        setDebugEnabled();
        out = new PrintWriter(System.out);
        sc = new Scanner(System.in);
    }

    static void postProcess() {
        out.flush();
        sc.close();
        end = System.nanoTime();
        debug(() -> "elapsed time: " + (end - start) / 1_000_000 + "[msec]");
    }

}
