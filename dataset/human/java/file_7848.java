import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        long k = Long.parseLong(sc.next());
        Integer[] a = new Integer[n];
        Arrays.setAll(a, i -> Integer.parseInt(sc.next()) - 1);
        sc.close();

        // 主処理
        boolean[] used = new boolean[n]; // List.containsが遅いためbooleanの配列でループ判定をする
        List<Integer> loopNum = new ArrayList<>();
        int now = 0;

        // ループするまでの移動の証跡をリストに格納する
        while (!used[now]) {
            used[now] = true;
            loopNum.add(now);
            now = a[now];
        }

        int size = loopNum.size(); // ループによる重複をなくした移動回数
        int primalyCount = loopNum.indexOf(now); // ループ外の部分の移動回数
        int loopCount = size - primalyCount; // ループ部分の移動回数

        long num = k; // ループ部分を排除した移動回数を求める
        if (primalyCount < num) {
            num = ((num - primalyCount) % loopCount) + primalyCount;
        }

        int result = loopNum.get((int) num) + 1;

        // 出力
        System.out.println(result);
    }
}
