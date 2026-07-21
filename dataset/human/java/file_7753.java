import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        Long K = sc.nextLong();


        int[] graph = new int[N];


        for (int i = 0; i < N; i++) {
            graph[i] = sc.nextInt();
        }

//        for (int i : graph) {
//            System.out.println(i);
//        }

        //訪れた頂点
        List<Integer> s = new ArrayList<Integer>();

        //
        Integer[] ord = new Integer[N + 1];

        //初期化
        Arrays.fill(ord, -1);

        //周期, 例外部分の長さ
        int c = 1; int l;

        int v = 1;
        while (ord[v] == -1) {
            ord[v] = s.size();
            s.add(v);
            v = graph[v-1];
        }
        c = s.size() - ord[v];
        l = ord[v];

        if (K < l) System.out.println(s.get(Math.toIntExact(K)));
        else {
            K -= l;
            K %= c;
            System.out.println(s.get((int) (l + K)));
        }
    }


}
