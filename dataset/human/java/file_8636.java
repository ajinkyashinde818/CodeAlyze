import java.util.*;

public class Main implements Runnable {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        // Run with 32MB stack
        Thread thread = new Thread(null, new Main(), "", 32 * 1024 * 1024);
        thread.start();
    }

    @Override
    public void run() {
        final Scanner scanner = new Scanner(System.in);
        solve(scanner);
    }

    static void solve(Scanner scanner) {
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        int k = scanner.nextInt();
        int n = (int) gcd(a, b);
        List<Integer> divs = getDivisors(n);
        Collections.reverse(divs);
        System.out.println(divs.get(k - 1));
    }

    static long gcd(long x, long y) {
        if (x < y) {
            return gcd(y, x);
        }
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }

    static List<Integer> getDivisors(int n) {
        List<Integer> divisors = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.add(i);
                if (i != n / i) {
                    tmp.add(n / i);
                }
            }
        }
        Collections.reverse(tmp);
        divisors.addAll(tmp);
        return divisors;
    }

}
