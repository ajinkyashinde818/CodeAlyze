import java.util.Scanner;

// C - Snack
// https://atcoder.jp/contests/abc148/tasks/abc148_c
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = Integer.parseInt(scanner.next());
        int B = Integer.parseInt(scanner.next());
        scanner.close();

        long ans = lcm(A, B);

        System.out.println(ans);
    }

    private static long lcm(long m, long n) {
        return m * n / gcd(m, n);
    }

    private static long gcd(long m, long n) {
        if (m < n) return gcd(n, m);
        if (n == 0) return m;
        return gcd(n, m % n);
    }
}
