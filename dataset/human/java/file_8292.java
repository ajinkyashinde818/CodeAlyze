import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        System.out.println(calcLeastCommonMultiple(a, b));
        sc.close();
    }

    // aとbの最大公約数：ユークリッドの互除法
    private static long calcGreatestCommonDivisor(int a, int b) {
        int max = Math.max(a, b);
        int min = Math.min(a, b);
        // 大きい数を小さい数で割る。
        // 余りが0の場合は小さい数が最小公倍数になる
        if ((max % min) == 0) {
            return min;
        }
        // 割られる数に「小さい数」を、割る数に「余り」をセットして繰り返す
        return calcGreatestCommonDivisor(min, max % min);
    }

    // 最小公倍数：2つの数aとbの積を、aとbの最小公倍数で割った値が最小公倍数になる
    private static long calcLeastCommonMultiple(int a, int b) {
        return ((long) a * (long) b) / calcGreatestCommonDivisor(a, b);
    }

}
