import java.util.Scanner;

public class Main {
    //Double Factorial
    //这是第一次做 E 吧废物, 这次 D 简单人均 20 分钟 6 道呵呵
    //先看看能不能看懂题目吧
    //又是整型溢出的情况, 如何计算可以算出多少个 0 呢
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long v = sc.nextLong();
        System.out.println(helper(v));
        sc.close();
    }

    static long helper(long v) {
        if (v % 2 == 1) return 0;
        long count = 0;
        for (long i = 10; i <= v; i *= 5) {
            count += v / i;
        }
        return count;
    }
}
