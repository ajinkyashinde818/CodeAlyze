import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        int s = Integer.parseInt(sc.next());
        sc.close();

        // 主処理
        String[] nums = new String[n];
        if (k <= n) {
            for (int i = 0; i < n; i++) {
                if (i < k) {
                    nums[i] = Integer.toString(s);
                } else {
                    nums[i] = s != 1000000000 ? Integer.toString(s + 1) : "1";
                }
            }
        }

        String result = String.join(" ", nums);

        // 出力
        System.out.println(result);
    }
}
