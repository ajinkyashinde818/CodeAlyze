import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.function.*;

public class Main {
    static In in = new In();
    static Out out = new Out();
    static final long inf = 0x1fffffffffffffffL;
    static final int iinf = 0x3fffffff;
    static final double eps = 1e-9;
    static final long mod = 1000000007;

    void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        Monoid<LongTuple> monoidNode = new Monoid<>(new LongTuple(0, 0, 0), (a, b) -> new LongTuple(a.a + b.a + a.b * b.c, a.b + b.b, a.c + b.c));
        Monoid<Integer> monoidLazy = new Monoid<>(0, (a, b) -> a ^ b);
        LazySegmentTree<LongTuple, Integer> segmentTree = new LazySegmentTree<>(monoidNode, monoidLazy, (node, a, length) -> a == 0 ? node : new LongTuple(node.b * node.c - node.a, node.c, node.b));
        List<LongTuple> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a = in.nextInt();
            list.add(new LongTuple(0, a, 1 - a));
        }
        segmentTree.build(list);
        for (int i = 0; i < q; i++) {
            int t = in.nextInt();
            int l = in.nextInt() - 1;
            int r = in.nextInt();
            if (t == 1) {
                segmentTree.update(l, r, 1);
            } else {
                out.println(segmentTree.get(l, r).a);
            }
        }
    }

    void naive() {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < q; i++) {
            int t = in.nextInt();
            int l = in.nextInt() - 1;
            int r = in.nextInt();
            if (t == 1) {
                for (int j = l; j < r; j++) {
                    a[j] = 1 - a[j];
                }
            } else {
                int ans = 0;
                for (int j = l; j < r; j++) {
                    for (int k = j + 1; k < r; k++) {
                        if (a[j] > a[k]) {
                            ans++;
                        }
                    }
                }
                out.println(ans);
            }
        }
    }

    public static void main(String[] args) {
        if (args.length == 1 && args[0].equals("naive")) {
            new Main().naive();
        } else {
            new Main().solve();
        }
        out.flush();
    }
}

class LongTuple implements Comparable<LongTuple> {
    long a, b, c;

    LongTuple(long a, long b, long c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof LongTuple)) {
            return false;
        }
        LongTuple that = (LongTuple)o;
        return a == that.a && b == that.b && c == that.c;
    }

    @Override
    public int hashCode() {
        return (Long.hashCode(a) * 31 + Long.hashCode(b)) * 31 + Long.hashCode(c);
    }

    @Override
    public int compareTo(LongTuple o) {
        return a == o.a ? b == o.b ? Long.compare(c, o.c) : Long.compare(b, o.b) : Long.compare(a, o.a);
    }

    @Override
    public String toString() {
        return String.format("[%d, %d, %d]", a, b, c);
    }
}

class LazySegmentTree<T, U> {
     List<T> node;
     List<U> lazy;
    private int n;
    private int m;
    private int height;
    private Monoid<T> monoidNode;
    private Monoid<U> monoidLazy;
    private Merge<T, U> mergeFunction;

    LazySegmentTree(Monoid<T> monoidNode, Monoid<U> monoidLazy, Merge<T, U> mergeFunction) {
        this.monoidNode = monoidNode;
        this.monoidLazy = monoidLazy;
        this.mergeFunction = mergeFunction;
    }

    void build(int m) {
        this.m = m;
        this.n = Integer.highestOneBit(m) * 2;
        this.height = Integer.bitCount(n - 1);
        node = new ArrayList<>(n * 2);
        lazy = new ArrayList<>(n * 2);
        for (int i = 0; i < n; i++) {
            node.add(null);
        }
        for (int i = 0; i < n; i++) {
            node.add(monoidNode.identity());
        }
        for (int i = n - 1; i > 0; i--) {
            node.set(i, monoidNode.merge(node.get(i * 2), node.get(i * 2 + 1)));
        }
        for (int i = 0; i < n * 2; i++) {
            lazy.add(monoidLazy.identity());
        }
    }

    void build(int m, T init) {
        this.m = m;
        this.n = Integer.highestOneBit(m) * 2;
        this.height = Integer.bitCount(n - 1);
        node = new ArrayList<>(n * 2);
        lazy = new ArrayList<>(n * 2);
        for (int i = 0; i < n; i++) {
            node.add(null);
        }
        for (int i = 0; i < n; i++) {
            node.add(i < m ? init : monoidNode.identity());
        }
        for (int i = n - 1; i > 0; i--) {
            node.set(i, monoidNode.merge(node.get(i * 2), node.get(i * 2 + 1)));
        }
        for (int i = 0; i < n * 2; i++) {
            lazy.add(monoidLazy.identity());
        }
    }

    void build(int m, Supplier<T> initSupplier) {
        this.m = m;
        this.n = Integer.highestOneBit(m) * 2;
        this.height = Integer.bitCount(n - 1);
        node = new ArrayList<>(n * 2);
        lazy = new ArrayList<>(n * 2);
        for (int i = 0; i < n; i++) {
            node.add(null);
        }
        for (int i = 0; i < n; i++) {
            node.add(i < m ? initSupplier.get() : monoidNode.identity());
        }
        for (int i = n - 1; i > 0; i--) {
            node.set(i, monoidNode.merge(node.get(i * 2), node.get(i * 2 + 1)));
        }
        for (int i = 0; i < n * 2; i++) {
            lazy.add(monoidLazy.identity());
        }
    }

    void build(List<T> data) {
        this.m = data.size();
        this.n = Integer.highestOneBit(m) * 2;
        this.height = Integer.bitCount(n - 1);
        node = new ArrayList<>(n * 2);
        lazy = new ArrayList<>(n * 2);
        for (int i = 0; i < n; i++) {
            node.add(null);
        }
        for (int i = 0; i < n; i++) {
            node.add(i < m ? data.get(i) : monoidNode.identity());
        }
        for (int i = n - 1; i > 0; i--) {
            node.set(i, monoidNode.merge(node.get(i * 2), node.get(i * 2 + 1)));
        }
        for (int i = 0; i < n * 2; i++) {
            lazy.add(monoidLazy.identity());
        }
    }

    void update(int i, U x) {
        update(i, i + 1, x);
    }

    void update(int l, int r, U x) {
        for (int i = height; i > 0; i--) {
            propagate((l + n) >> i);
            propagate((r + n - 1) >> i);
        }
        for (int ll = l + n, rr = r + n; ll < rr; ll /= 2, rr /= 2) {
            if (ll % 2 == 1) {
                lazy.set(ll, monoidLazy.merge(lazy.get(ll), x));
                propagate(ll);
                ll++;
            }
            if (rr % 2 == 1) {
                rr--;
                lazy.set(rr, monoidLazy.merge(lazy.get(rr), x));
                propagate(rr);
            }
        }
        for (int ll = (l + n) / 2, rr = (r + n - 1) / 2; ll > 0; ll /= 2, rr /= 2) {
            if (monoidLazy.equalsIdentity(lazy.get(ll))) {
                node.set(ll, monoidNode.merge(mergeFunction.merge(node.get(ll * 2), lazy.get(ll * 2), range(ll * 2)), mergeFunction.merge(node.get(ll * 2 + 1), lazy.get(ll * 2 + 1), range(ll * 2 + 1))));
            }
            if (monoidLazy.equalsIdentity(lazy.get(rr))) {
                node.set(rr, monoidNode.merge(mergeFunction.merge(node.get(rr * 2), lazy.get(rr * 2), range(rr * 2)), mergeFunction.merge(node.get(rr * 2 + 1), lazy.get(rr * 2 + 1), range(rr * 2 + 1))));
            }
        }
    }

    T get(int i) {
        return get(i, i + 1);
    }

    T get(int l, int r) {
        for (int i = height; i > 0; i--) {
            propagate((l + n) >> i);
            propagate((r + n - 1) >> i);
        }
        T vl = monoidNode.identity();
        T vr = monoidNode.identity();
        for (int ll = l + n, rr = r + n; ll < rr; ll /= 2, rr /= 2) {
            if (ll % 2 == 1) {
                vl = monoidNode.merge(vl, mergeFunction.merge(node.get(ll), lazy.get(ll), range(ll)));
                ll++;
            }
            if (rr % 2 == 1) {
                rr--;
                vr = monoidNode.merge(mergeFunction.merge(node.get(rr), lazy.get(rr), range(rr)), vr);
            }
        }
        return monoidNode.merge(vl, vr);
    }

    List<T> getAll() {
        for (int i = 0; i < n * 2; i++) {
            propagate(i);
        }
        List<T> all = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            all.add(get(i));
        }
        return all;
    }

    int binarySearch(Predicate<T> predicate) {
        return binarySearch(0, m, predicate);
    }

    int binarySearch(int l, int r, Predicate<T> predicate) {
        if (l < 0 || m < r || l >= r) {
            return -1;
        }
        for (int i = height; i > 0; i--) {
            propagate((l + n) >> i);
        }
        T res = monoidNode.identity();
        int offset = l;
        for (int i = l + n; i < n * 2 && offset < r; ) {
            T t = monoidNode.merge(res, mergeFunction.merge(node.get(i), lazy.get(i), range(i)));
            if (rangeRight(i) <= r && !predicate.test(t)) {
                res = t;
                offset = rangeRight(i++);
                if (i % 2 == 0) {
                    i /= 2;
                }
            } else {
                i *= 2;
            }
        }
        return offset;
    }

    private void propagate(int k) {
        if (monoidLazy.equalsIdentity(lazy.get(k))) {
            return;
        }
        node.set(k, mergeFunction.merge(node.get(k), lazy.get(k), range(k)));
        if (k < n) {
            lazy.set(k * 2, monoidLazy.merge(lazy.get(k * 2), lazy.get(k)));
            lazy.set(k * 2 + 1, monoidLazy.merge(lazy.get(k * 2 + 1), lazy.get(k)));
        }
        lazy.set(k, monoidLazy.identity());
    }

    private int rangeRight(int k) {
        return ((k ^ Integer.highestOneBit(k)) + 1) * range(k);
    }

    private int range(int k) {
        return 1 << (height - Integer.bitCount(Integer.highestOneBit(k) - 1));
    }

    @Override
    public String toString() {
        return getAll().toString();
    }

    interface Merge<T, U> {
        T merge(T t, U u, int length);
    }
}

class Monoid<T> {
    private T identity;
    private Supplier<T> identitySupplier;
    private BinaryOperator<T> operation;

    Monoid(BinaryOperator<T> operation) {
        this.operation = operation;
    }

    Monoid(T identity, BinaryOperator<T> operation) {
        this(operation);
        this.identity = identity;
    }

    Monoid(Supplier<T> identitySupplier, BinaryOperator<T> operation) {
        this(operation);
        this.identitySupplier = identitySupplier;
    }

    T merge(T x, T y) {
        T identity = identity();
        if (Objects.equals(x, identity)) {
            if (Objects.equals(y, identity)) {
                return identity;
            }
            return y;
        } else if (Objects.equals(y, identity)) {
            return x;
        } else {
            return operation.apply(x, y);
        }
    }

    public T identity() {
        return identitySupplier == null ? identity : identitySupplier.get();
    }

    public boolean equalsIdentity(T obj) {
        return Objects.equals(obj, identity());
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
