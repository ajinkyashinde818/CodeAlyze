import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        Integer[] a = new Integer[n];
        int minusCount = 0;
        for (int i = 0; i < a.length; i++) {
            int num = Integer.parseInt(sc.next());
            if (num < 0) {
                minusCount++;
                num *= -1;
            }
            a[i] = num;
        }
        sc.close();

        // 主処理
        long sum = Arrays.stream(a).mapToLong(i -> i).sum();
        int min = Arrays.stream(a).mapToInt(i -> i).min().orElse(0);
        long result = minusCount % 2 == 0 ? sum : sum - min * 2;

        // 出力
        System.out.println(result);
    }
}
