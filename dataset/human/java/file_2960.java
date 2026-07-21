import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n;
    static int m;
    static int[] g;
    static int[] toN;
    static int[] from1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();//要素の数
        m = sc.nextInt();//編の数
        toN = new int[n+1];
        from1 = new int[n+1];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (a == 1) {
                from1[b] = 1;
            } else if (b == n) {
                toN[a] = 1;
            }
        }
        boolean ok = false;
        for (int i = 0; i < n+1; i++) {
            if (from1[i] != 0) {
                if (toN[i] != 0) {
                    ok = true;
                    break;
                }
            }
        }
//        g = new int[n+1];//グラフを表す配列
        //最初は全て親
//        Arrays.fill(g, -1);
//        for (int i = 0; i < m; i++) {
//            union(sc.nextInt(), sc.nextInt());
//        }
//        System.out.println(find(n) == find(1)?"POSSIBLE": "IMPOSSIBLE");
        System.out.println(ok?"POSSIBLE": "IMPOSSIBLE");
    }
//    //要素間の結合を行う。
//    static void union (int a, int b) {
//        int pa = find(a);
//        int pb = find(b);
//        //要素が小さい方に結合する。(負の数なので数が小さい方が大きい）
//        if (pa > pb) {
//            int tmp = pa;
//            pa = pb;
//            pb = tmp;
//        }
//        //pb を　pa に結合する。
//        //paの値にpbを足し、pb を paの要素に置き換える。
//        g[pa] += g[pb];
//        g[pb] = pa;
//    }
//    //要素の親をリターンする。親(0未満)が見つかるまで再帰
//    static int find (int a) {
//        if (g[a] < 0) return a;
//        return find(g[a]);
//    }
}
