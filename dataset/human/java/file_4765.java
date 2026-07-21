import java.util.Scanner;

// E - Double Factorial
// https://atcoder.jp/contests/abc148/tasks/abc148_e
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = Long.parseLong(scanner.next());
        scanner.close();

        long ans = Math.min(g2(N, 2), g2(N, 5));

        System.out.println(ans);
    }

    private static long g1(long n, int p) {
        if (n == 0) return 0;
        return n / p + g1(n / p, p);
    }

    private static long g2(long n, int p) {
        if (n % 2 == 1) {
            return g1(n, p) - g2(n - 1, p);
        }
        long res = g1(n / 2, p);
        if (p == 2) res += n / 2;
        return res;
    }
}
