import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int k = Integer.parseInt(sc.next());
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(sc.next());
        }

        // 主処理
        int[] diff = new int[n];
        for (int i = 0; i < n - 1; i++) {
            diff[i] = a[i + 1] - a[i];
        }
        diff[n - 1] = a[0] + (k - a[n - 1]);

        int sum = Arrays.stream(diff).sum();
        int max = Arrays.stream(diff).max().getAsInt();
        int result = sum - max;

        // 出力
        System.out.println(result);
        sc.close();
    }
}
