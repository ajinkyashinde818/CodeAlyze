import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int k = Integer.parseInt(sc.next());
        int s = Integer.parseInt(sc.next());
        sc.close();

        // 主処理
        int result = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                int sum = i + j;
                if (sum <= s && s - sum <= k) {
                    result++;
                }
            }
        }

        // 出力
        System.out.println(result);
    }
}
