import java.awt.Point;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringJoiner;

public class Main {

    static class UnionFind {
        private int[] parent;

        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        private int root(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = root(parent[x]);
        }

        private void unite(int x, int y) {
            int rx = root(x);
            int ry = root(y);
            if (rx == ry) {
                return;
            }
            parent[rx] = ry;
        }

        private boolean same(int x, int y) {
            int rx = root(x);
            int ry = root(y);
            return rx == ry;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int l = sc.nextInt();
        int[] p = new int[k];
        int[] q = new int[k];
        int[] r = new int[l];
        int[] s = new int[l];
        UnionFind uf1 = new UnionFind(n + 1);
        UnionFind uf2 = new UnionFind(n + 1);
        for (int i = 0; i < k; i++) {
            p[i] = sc.nextInt() - 1;
            q[i] = sc.nextInt() - 1;
            uf1.unite(p[i], q[i]);
        }
        for (int i = 0; i < l; i++) {
            r[i] = sc.nextInt() - 1;
            s[i] = sc.nextInt() - 1;
            uf2.unite(r[i], s[i]);
        }
        Map<Point, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Point point = new Point(uf1.root(i), uf2.root(i));
            map.put(point, map.getOrDefault(point, 0) + 1);
        }
        StringJoiner sj = new StringJoiner(" ");
        for (int i = 0; i < n; i++) {
            sj.add(String.valueOf(map.get(new Point(uf1.root(i), uf2.root(i)))));
        }
        System.out.println(sj);
    }

}
