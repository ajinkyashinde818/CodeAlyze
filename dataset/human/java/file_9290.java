import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            DTwinBinaryTrees solver = new DTwinBinaryTrees();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DTwinBinaryTrees {
        long sum = 0;
        ModBIT bit;
        Debug debug = new Debug(false);
        Modular mod = new Modular(1e9 + 7);
        int modVal = mod.getMod();
        ModPrimeInverseNumber inverseNumber = new ModPrimeInverseNumber((int) 3e5, mod);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int h = in.readInt();

            Node[] tree1 = create(h);
            Node[] tree2 = create(h);
            int[] perm = new int[1 << h - 1];
            in.populate(perm);

            bit = new ModBIT(1 << h, mod.getMod());
            for (int i = 0; i < perm.length; i++) {
                Node a = tree1[i + (1 << h - 1)];
                int delta = perm[i] - (i + 1);
                Node b = tree2[a.id + delta];
                a.perm = b;
                b.perm = a;
            }


            dfsForRecord(tree1[1]);
            dfs1(tree1[1]);
            sum = mod.valueOf(sum);
            sum = mod.mul(sum, inverseNumber.inverse(2));
            out.println(sum);
        }

        public void mul(int i, int x) {
            int old = bit.query(i, i);
            int next = mod.mul(old, x);
            bit.update(i, next - old);
        }

        public void dfsForRecord(Node root) {
            if (root.adj.isEmpty()) {
                bit.update(root.perm.id, 1);
                mul(root.perm.id, root.prod);
                mul(root.perm.id, root.perm.prod);
            }
            for (Node node : root.adj) {
                dfsForRecord(node);
            }
        }

        public void intervalMul(Node root, int mul) {
            if (root.adj.isEmpty()) {
                long cur = (long) root.prod * root.perm.prod % modVal
                        * mul % modVal;

                mul(root.perm.id, mul);
                return;
            }
            for (Node node : root.adj) {
                intervalMul(node, mul);
            }
        }

        public int pow2(int x) {
            return mod.mul(x, x);
        }

        public void dfs1(Node root) {
            if (root.p != null) {
                intervalMul(root, mod.mul(inverseNumber.inverse(root.id),
                        inverseNumber.inverse(root.p.id)));
            }

            if (root.adj.isEmpty()) {
                dfs2(root.perm.p, root.perm, mod.mul(root.prod, root.perm.prod));
            }

            //remove parent
            for (Node node : root.adj) {
                dfs1(node);
            }

            if (root.p != null) {

                intervalMul(root, mod.mul(root.id,
                        root.p.id));
            }
        }

        public void dfs2(Node root, Node child, int mul) {
            if (root == null) {
                return;
            }
            for (Node node : root.adj) {
                if (node == child) {
                    continue;
                }
                int val = bit.query(node.l, node.r);
                val = mod.mul(val, mul);
                val = mod.mul(val, pow2(root.invProd));
                val = mod.mul(val, root.id);
                sum += val;
                debug.debug("val", val);
            }
            dfs2(root.p, root, mul);
        }

        public Node[] create(int h) {
            Node[] nodes = new Node[1 << h];
            for (int i = 1; i < 1 << h; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 1; i < 1 << h; i++) {
                int l = i * 2;
                int r = l + 1;
                if (l >= 1 << h) {
                    continue;
                }

                nodes[i].adj.add(nodes[l]);
                nodes[i].adj.add(nodes[r]);
            }

            dfs(nodes[1], null, 1, 1);
            return nodes;
        }

        public void dfs(Node root, Node p, int ps, int inv) {
            root.p = p;
            root.prod = mod.mul(ps, root.id);
            root.invProd = mod.mul(inv, inverseNumber.inverse(root.id));

            if (root.adj.isEmpty()) {
                root.r = root.l = root.id;
            } else {
                root.l = (int) 1e9;
                root.r = -1;
                for (Node node : root.adj) {
                    dfs(node, root, root.prod, root.invProd);
                    root.l = Math.min(root.l, node.l);
                    root.r = Math.max(root.r, node.r);
                }
            }
        }

    }

    static interface InverseNumber {
    }

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int mul(long x, long y) {
            return valueOf(x * y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class ModBIT {
        private long[] data;
        private int n;
        private int mod;

        public ModBIT(int n, int mod) {
            this.n = n;
            data = new long[n + 1];
            this.mod = mod;
        }

        public int query(int i) {
            long sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return (int) (sum % mod);
        }

        public void update(int i, int x) {
            if (i <= 0) {
                return;
            }
            x = DigitUtils.mod(x, mod);
            for (; i <= n; i += i & -i) {
                data[i] = (data[i] + x) % mod;
            }
        }

        public int query(int l, int r) {
            int sum = query(r);
            if (l > 1) {
                sum = DigitUtils.mod(sum - query(l - 1), mod);
            }
            return sum;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
        }

    }

    static class Node {
        int id;
        int prod;
        int invProd;
        List<Node> adj = new ArrayList<>();
        int l;
        int r;
        Node p;
        Node perm;

        public String toString() {
            return "" + id;
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, int x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(int x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        public void populate(int[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readInt();
            }
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class ModPrimeInverseNumber implements InverseNumber {
        int[] inv;

        public ModPrimeInverseNumber(int[] inv, int limit, Modular modular) {
            this.inv = inv;
            inv[1] = 1;
            int p = modular.getMod();
            for (int i = 2; i <= limit; i++) {
                int k = p / i;
                int r = p % i;
                inv[i] = modular.mul(-k, inv[r]);
            }
        }

        public ModPrimeInverseNumber(int limit, Modular modular) {
            this(new int[limit + 1], limit, modular);
        }

        public int inverse(int x) {
            return inv[x];
        }

    }
}
