import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(sc.next());
        }

        // 主処理
        long[] array = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            array[i] = sum;
        }

        long[] diff = new long[n - 1];
        for (int i = 0; i < n - 1; i++) {
            diff[i] = Math.abs(array[i] - (array[n - 1] - array[i]));
        }
        long result = Arrays.stream(diff).min().getAsLong();

        // 出力
        System.out.println(result);
        sc.close();
    }
}
