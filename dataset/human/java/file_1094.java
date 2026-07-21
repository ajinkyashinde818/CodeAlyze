import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;

public class Main {
    static In in = new In();
    static Out out = new Out();
    static final long inf = 0x1fffffffffffffffL;
    static final int iinf = 0x3fffffff;
    static final double eps = 1e-9;
    static final long mod = 1000000007;

    void solve(boolean naive) {
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);
        int[] b = in.nextIntArray(n);
        int[] c = Arrays.copyOf(b, n);
        int[] count = new int[n + 1];
        TreeMap<Integer, Integer> countA = new TreeMap<>();
        TreeMap<Integer, Integer> countB = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            count[a[i]]++;
            count[b[i]]++;
            countA.merge(a[i], 1, Integer::sum);
            countB.merge(b[i], 1, Integer::sum);
        }
        int max = 0;
        for (int i = 0; i <= n; i++) {
            max = Math.max(max, count[i]);
        }
        if (max > n) {
            out.println("No");
        } else {
            out.println("Yes");
            Map<Integer, Integer> pos = new HashMap<>();
            Map<Integer, Integer> posRev = new HashMap<>();
            for (int i = 0; i < n; i++) {
                pos.put(i, i);
                posRev.put(i, i);
            }
            for (int i = 0; i < n; i++) {
                if (a[i] != c[i]) {
                    continue;
                }
                int select;
                if (countB.get(c[i]) * 2 <= n) {
                    int l = lowerBound(a, c[i]);
                    int r = upperBound(a, c[i]);
                    int other = n - (r - l);
                    while (true) {
                        int j = (int)(Math.random() * other);
                        if (j >= l) {
                            j += r - l;
                        }
                        if (i != j && a[j] != c[i] && a[i] != c[j]) {
                            select = j;
                            break;
                        }
                    }
                } else {
                    int l = lowerBound(b, c[i]);
                    int r = upperBound(b, c[i]);
                    int other = n - (r - l);
                    while (true) {
                        int j = (int)(Math.random() * other);
                        if (j >= l) {
                            j += r - l;
                        }
                        Integer v = pos.get(j);
                        if (v != null && i != v && a[v] != c[i] && a[i] != c[v]) {
                            select = v;
                            break;
                        }
                    }
                }
                int temp = c[i];
                c[i] = c[select];
                c[select] = temp;
                Integer fi = posRev.get(i);
                Integer fs = posRev.get(select);
                pos.put(fi, select);
                pos.put(fs, i);
                posRev.put(select, fi);
                posRev.put(i, fs);
            }
            out.println(c);
        }
    }

    int lowerBound(int[] array, int value) {
        int left = -1;
        int right = array.length;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (array[mid] < value) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    int upperBound(int[] array, int value) {
        int left = -1;
        int right = array.length;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (array[mid] <= value) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    public static void main(String[] args) {
        new Main().solve(args.length == 1 && args[0].equals("naive"));
        out.flush();
    }
}

class In {
    private BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 0x10000);
    private StringTokenizer tokenizer;

    String next() {
        try {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
        } catch (IOException ignored) {
        }
        return tokenizer.nextToken();
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

    char[] nextCharArray() {
        return next().toCharArray();
    }

    char[][] nextCharGrid(int n, int m) {
        char[][] a = new char[n][m];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        return a;
    }

    int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    int[] nextIntArray(int n, IntUnaryOperator op) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = op.applyAsInt(nextInt());
        }
        return a;
    }

    long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        return a;
    }

    long[] nextLongArray(int n, LongUnaryOperator op) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = op.applyAsLong(nextLong());
        }
        return a;
    }

    List<List<Integer>> nextEdges(int n, int m) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            res.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            res.get(u).add(v);
            res.get(v).add(u);
        }
        return res;
    }
}

class Out {
    private PrintWriter out = new PrintWriter(System.out);
    boolean autoFlush = false;

    void println(Object... a) {
        StringJoiner joiner = new StringJoiner(" ");
        for (Object obj : a) {
            joiner.add(String.valueOf(obj));
        }
        out.println(joiner);
        if (autoFlush) {
            out.flush();
        }
    }

    void println(char[] s) {
        out.println(String.valueOf(s));
        if (autoFlush) {
            out.flush();
        }
    }

    void println(int[] a) {
        StringJoiner joiner = new StringJoiner(" ");
        for (int i : a) {
            joiner.add(Integer.toString(i));
        }
        out.println(joiner);
        if (autoFlush) {
            out.flush();
        }
    }

    void println(long[] a) {
        StringJoiner joiner = new StringJoiner(" ");
        for (long i : a) {
            joiner.add(Long.toString(i));
        }
        out.println(joiner);
        if (autoFlush) {
            out.flush();
        }
    }

    void flush() {
        out.flush();
    }
}
