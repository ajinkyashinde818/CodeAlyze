import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Unionfind uf1 = new Unionfind(n);
        Unionfind uf2 = new Unionfind(n);
        int k = sc.nextInt();
        int l = sc.nextInt();
        int[] p = new int[k];
        int[] q = new int[k];
        for (int i = 0 ; i < k ; i++) {
            p[i] = sc.nextInt() - 1;
            q[i] = sc.nextInt() - 1;
            uf1.union(p[i], q[i]);
        }
        int[] r = new int[l];
        int[] s = new int[l];
        for (int i = 0 ; i < l ; i++) {
            r[i] = sc.nextInt() - 1;
            s[i] = sc.nextInt() - 1;
            uf2.union(r[i], s[i]);
        }
        Map<Long, Integer> map = new HashMap<>();
        List<Long> list = new ArrayList<>();
        for (int i = 0 ; i < n ; i++) {
            long key = (long) 1000000 * uf1.findRoot(i) + uf2.findRoot(i);
            list.add(key);
            if (map.containsKey(key)) {
                map.put(key, map.get(key) + 1);
            } else {
                map.put(key, 1);
            }
        }
        for (int i = 0 ; i < n ; i++) {
            System.out.print(map.get(list.get(i)));
            if (i < n - 1) {
                System.out.print(" ");
            } else {
                System.out.print("\n");
            }
        }



    }

}

class Unionfind {
    ArrayList<Integer> parent;

    public Unionfind(int n) {
        parent = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            parent.add(-1);
        }
    }

    public boolean union(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) {
            return false;
        }

        if (size(x) < size(y)) {
            int temp = x;
            x = y;
            y = temp;
        }

        parent.set(x, parent.get(x) + parent.get(y));
        parent.set(y, x);
        return true;
    }

    public int findRoot(int i) {
        if (parent.get(i) < 0) {
            return i;
        } else {
            int root = findRoot(parent.get(i));
            parent.set(i, root);
            return root;
        }
    }

    public int size(int x) {
        return -parent.get(findRoot(x));
    }

    public boolean same(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
}
