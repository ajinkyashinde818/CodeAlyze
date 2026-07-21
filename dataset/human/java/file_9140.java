import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        Integer[] a = new Integer[m];
        Arrays.setAll(a, i -> Integer.parseInt(sc.next()));
        sc.close();

        // 主処理
        List<Integer> list = new ArrayList<>(); // 壊れていない連続する階段の段数のリスト
        int index = 0;
        for (int i = 0; i < a.length; i++) {
            int num = a[i] - index;
            index = a[i] + 1;
            list.add(num);
        }
        list.add(n - index + 1);

        // 連続した階段の段数の上り方はフィボナッチ数列で求められる
        long[] fibonacci = new long[100001];
        final long MOD = 1000000007;
        fibonacci[0] = 1;
        fibonacci[1] = 1;
        for (int i = 2; i < 100001; i++) {
            fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % MOD; // オーバーフローするためMODで除算
        }

        // 連続した階段の段数に上り方を求めて乗算する
        long result = 1;
        if (list.contains(0)) {
            result = 0;
        } else {
            for (int num : list) {
                result *= fibonacci[num - 1];
                result %= MOD;
            }
        }

        // 出力
        System.out.println(result);
    }
}
