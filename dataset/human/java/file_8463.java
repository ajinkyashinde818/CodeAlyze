import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by jaga on 9/22/16.
 */
public class Main{
    public static void solve(PrintWriter out, FastScanner in) {
        int N = in.nextInt();
        int K = in.nextInt();
        int L = in.nextInt();

        UnionFindTree tree1 = new UnionFindTree(N);
        UnionFindTree tree2 = new UnionFindTree(N);

        for (int i = 0; i < K; i++) {
            int p = in.nextInt();
            int q = in.nextInt();
            tree1.unite(p - 1, q - 1);
        }

        for (int i = 0; i < L; i++) {
            int r = in.nextInt();
            int s = in.nextInt();
            tree2.unite(r - 1, s - 1);
        }

        /**stringのキーにした場合**/

//        HashMap<String, Integer> map = new HashMap<>();
//
//        String txt[] = new String[N];
//
//        for(int i = 0;i < N ;i ++) {
//            txt[i] = tree1.par[i] + "+" + tree2.par[i];
//            if (map.containsKey(txt[i])) {
//                map.replace(txt[i], map.get(txt[i]) + 1);
//            } else {
//                map.put(txt[i], 1);
//            }
//        }
//
//        for(int i = 0;i < N - 1;i ++) {
//            out.print( map.get(txt[i]) + " ");
//        }
//        out.println(map.get(txt[N - 1]));
        TreeMap<Long, Integer> count = new TreeMap<>();
        for (int i = 0; i < N; i++) {
            long key = (long) tree1.find(i) * N + tree2.find(i);
            Integer cnt = count.get(key);
            if (cnt == null) count.put(key, 1);
            else count.put(key, cnt + 1);
        }

        for (int i = 0; i < N; i++) {
            if (i > 0) out.print(" ");
            long key = (long) tree1.find(i) * N + tree2.find(i);
            out.print(count.get(key));
        }
        out.println("");
    }

    static class Pair implements Comparable {
        int first, second;

        Pair(int a, int b) {
            first = a;
            second = b;
        }

        public int compareTo(Object other) {
            Pair p1 = (Pair) other;
            return this.first - ((Pair) other).first; // IDの値に従い昇順で並び替えたい場合
//         return -(this.first - ((Pair) other).first); // IDの値に従い降順で並び替えたい場合
        }
    }

    /*以下はテンプレ*/
    public static void main(String args[]) {
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        FastScanner in = new FastScanner();
        solve(out, in);
        out.close();

    }

    public static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int bufferLength = 0;

        private boolean hasNextByte() {
            if (ptr < bufferLength) {
                return true;
            } else {
                ptr = 0;
                try {
                    bufferLength = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (bufferLength <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        private void skipUnprintable() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        }

        boolean hasNext() {
            skipUnprintable();
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextDouble();
            }
            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][];
            for (int i = 0; i < n; i++) {
                map[i] = nextDoubleArray(m);
            }
            return map;
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++) array[i] = nextInt();
            return array;
        }

        public long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++) array[i] = nextLong();
            return array;
        }

        public String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++) array[i] = next();
            return array;
        }

        public char[][] nextCharMap(int n) {
            char[][] array = new char[n][];
            for (int i = 0; i < n; i++) array[i] = next().toCharArray();
            return array;
        }

        public int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][];
            for (int i = 0; i < n; i++) {
                map[i] = nextIntArray(m);
            }
            return map;
        }
    }

}

class UnionFindTree {
    int par[];//親ノード
    int rank[];//木の根のランク
    int num[];//木に含まれるノードの数 根以外の数は0

    //n要素で初期化
    UnionFindTree(int n) {
        par = new int[n]; //初期値では自分自身が親
        rank = new int[n]; //初期値0]
        num = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            num[i] = 1;
        }
    }

    //木の根を求める
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    //xとyの属する集合を併合
    void unite(int x, int y) {
        //根を求める
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }

        //ランクが大きい方の木に併合
        if (rank[x] < rank[y]) {
            par[x] = y;
            num[y] += num[x];
            num[x] = 0;
        } else {
            par[y] = x;
            num[x] += num[y];
            num[y] = 0;
            if (rank[x] == rank[y]) {
                //ランクが同じ場合はxに併合してランクを増やす
                rank[x]++;
            }
        }
    }

    //xとyが同じ木に属するかどうか
    boolean same(int x, int y) {
        return find(x) == find(y);
    }

    int getNum(int x) {
        return num[x];
    }

    //xと親ノードが同じノードの数を求める
}
