import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main {

    static PrintWriter out;
    static InputReader sc;

    static void solve() {
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        List<Integer> nums = new ArrayList<Integer>();
        for (int i = 1; i <= Math.min(A, B); i++) {
            if (A % i == 0 && B % i == 0) {
                nums.add(i);
            }
        }
        Collections.sort(nums, Collections.reverseOrder());
        out.println(nums.get(K - 1));
    }

    public static void main(String[] args) {
        sc = new InputReader(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.flush();
    }

    public static boolean ok(int x, int y, int X, int Y) {
        return 0 <= x && x < X && 0 <= y && y < Y;
    }

    public static long gcd(long a, long b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        long r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }

    public static int upper_bound(long x, long[] arr) {
        int ok = arr.length;
        int ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (arr[mid] <= x) {
                ng = mid;
            } else {
                ok = mid;
            }
        }
        return ok;
    }

    public static int lower_bound(long x, long[] arr) {
        int ok = -1;
        int ng = arr.length;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (arr[mid] < x) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;

    }

    public static int binary_search(int x, int[] arr) {
        int low = 0;
        int high = arr.length;
        while (high - low > 0) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return -1;
    }

    public static void reverse(int[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            int tmp = arr[i];
            arr[i] = arr[arr.length - i - 1];
            arr[arr.length - i - 1] = tmp;
        }
    }

    public static class UnionFind {

        private int[] parent;

        public UnionFind(int n) {
            // 親の番号を格納する。
            // 自分自身が親だった場合は-(その集合のサイズ)を格納する。
            this.parent = new int[n];

            for (int i = 0; i < n; i++) {
                // 最初の時点では親は自分自身
                // 集合のサイズは１
                this.parent[i] = -1;
            }
        }

        // aがどのグループに属しているか調べる。
        public int root(int a) {
            if (this.parent[a] < 0) {
                return a;
            } else {
                // 再帰的に親をたどる。
                return this.parent[a] = this.root(this.parent[a]);
            }
        }

        // aの集合のサイズを返す
        public int size(int a) {
            return -this.parent[this.root(a)];
        }

        // aとbをつなぐ。
        // 大きい方(a)に小さい方(b)をつなぐ感じ。
        public boolean connect(int a, int b) {
            // 親同士をつなぐ。
            a = this.root(a);
            b = this.root(b);

            // すでにくっついている場合
            if (a == b) {
                return false;
            }

            if (this.size(a) < this.size(b)) {
                int r = a;
                a = b;
                b = r;
            }

            this.parent[a] += this.parent[b];
            this.parent[b] = a;

            return true;
        }
    }

    public static class Dijkstra {
        private static final long INF = Long.MAX_VALUE / 4;
        Vertex[] g;
        PriorityQueue<Pair> que;
        long[] d;

        public Dijkstra(int n) {
            this.g = new Vertex[n];
            this.d = new long[n];
            this.que = new PriorityQueue<>();

            for (int i = 0; i < n; i++) {
                this.g[i] = new Vertex(i);
            }
        }

        public void set(int i, int j, long cost) {
            Vertex u = this.g[i];
            Vertex v = this.g[j];
            u.adj.add(new Edge(cost, v));
            v.adj.add(new Edge(cost, u));
        }

        public void calc(int s) {
            Arrays.fill(this.d, INF);
            this.d[s] = 0;
            this.que.add(new Pair(0, this.g[s]));

            while (this.que.size() > 0) {
                Pair t = this.que.poll();
                int from = t.now.name;
                List<Edge> toes = t.now.adj;
                if (this.d[from] < t.value) {
                    continue;
                }
                for (Edge e : toes) {
                    int to = e.to.name;
                    long cost = e.w;
                    if (this.d[to] > this.d[from] + cost) {
                        this.d[to] = this.d[from] + cost;
                        this.que.add(new Pair(this.d[to], e.to));
                    }
                }
            }
        }

        public long distance(int g) {
            if (this.d[g] == INF) {
                return -1;
            }
            return this.d[g];
        }
    }

    public static class Edge {
        long w;
        Vertex to;

        public Edge(long w, Vertex to) {
            this.w = w;
            this.to = to;
        }

    }

    public static class Vertex {
        int name;
        List<Edge> adj;

        public Vertex(int name) {
            this.name = name;
            this.adj = new ArrayList<>();
        }

    }

    public static class Pair implements Comparable<Pair> {
        long value;
        Vertex now;

        public Pair(long value, Vertex now) {
            this.value = value;
            this.now = now;
        }

        @Override
        public int compareTo(Pair o) {

            return Long.compare(this.value, o.value);
        }

    }

    public static class ArraysFillEx {

        public static void fill(Object array, Object value) {

            // 第一引数が配列か判定
            Class<?> type = array.getClass();
            if (!type.isArray()) {
                throw new IllegalArgumentException("not array");
            }

            // クラスの型を判定
            String arrayClassName = array.getClass().getSimpleName().replace("[]", "").toLowerCase();
            String valueClassName = value.getClass().getSimpleName().toLowerCase().replace("character", "char")
                    .replace("integer", "int");
            if (!arrayClassName.equals(valueClassName)) {
                throw new IllegalArgumentException("does not match");
            }

            // 処理
            if (type.getComponentType().isArray()) {
                for (Object o : (Object[]) array) {
                    fill(o, value);
                }
            } else if (array instanceof boolean[]) {
                Arrays.fill((boolean[]) array, (boolean) value);
            } else if (array instanceof char[]) {
                Arrays.fill((char[]) array, (char) value);
            } else if (array instanceof byte[]) {
                Arrays.fill((byte[]) array, (byte) value);
            } else if (array instanceof short[]) {
                Arrays.fill((short[]) array, (short) value);
            } else if (array instanceof int[]) {
                Arrays.fill((int[]) array, (int) value);
            } else if (array instanceof long[]) {
                Arrays.fill((long[]) array, (long) value);
            } else if (array instanceof float[]) {
                Arrays.fill((float[]) array, (float) value);
            } else if (array instanceof double[]) {
                Arrays.fill((double[]) array, (double) value);
            } else {
                Arrays.fill((Object[]) array, value);
            }
        }

    }

    static class InputReader {

        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int curbuf;
        private int lenbuf;

        public InputReader(InputStream in) {
            this.in = in;
            this.curbuf = this.lenbuf = 0;
        }

        public boolean hasNextByte() {
            if (this.curbuf >= this.lenbuf) {
                this.curbuf = 0;
                try {
                    this.lenbuf = this.in.read(this.buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (this.lenbuf <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (this.hasNextByte()) {
                return this.buffer[this.curbuf++];
            } else {
                return -1;
            }
        }

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private void skip() {
            while (this.hasNextByte() && this.isSpaceChar(this.buffer[this.curbuf])) {
                this.curbuf++;
            }
        }

        public boolean hasNext() {
            this.skip();
            return this.hasNextByte();
        }

        public String next() {
            if (!this.hasNext()) {
                throw new NoSuchElementException();
            }
            StringBuilder sb = new StringBuilder();
            int b = this.readByte();
            while (!this.isSpaceChar(b)) {
                sb.appendCodePoint(b);
                b = this.readByte();
            }
            return sb.toString();
        }

        public int nextInt() {
            if (!this.hasNext()) {
                throw new NoSuchElementException();
            }
            int c = this.readByte();
            while (this.isSpaceChar(c)) {
                c = this.readByte();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = this.readByte();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = this.readByte();
            } while (!this.isSpaceChar(c));
            return minus ? -res : res;
        }

        public long nextLong() {
            if (!this.hasNext()) {
                throw new NoSuchElementException();
            }
            int c = this.readByte();
            while (this.isSpaceChar(c)) {
                c = this.readByte();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = this.readByte();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = this.readByte();
            } while (!this.isSpaceChar(c));
            return minus ? -res : res;
        }

        public double nextDouble() {
            return Double.parseDouble(this.next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = this.nextInt();
            }
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = this.nextLong();
            }
            return a;
        }

        public char[][] nextCharMap(int n, int m) {
            char[][] map = new char[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = this.next().toCharArray();
            }
            return map;
        }
    }

    static void tr(Object... o) {
        out.println(Arrays.deepToString(o));
    }
}
