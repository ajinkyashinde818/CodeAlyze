import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long nn = n;

        Map<Long, Integer> map = new HashMap<>();
        for (long p = 1; p <= Math.sqrt(nn) + 1; p++) {
            if (isPrime(p)) {
                map.put(p, 0);
                while (n > 0) {
                    if (n % p != 0) {
                        break;
                    }
                    map.compute(p, (k, old) -> old + 1);
                    n /= p;
                }
            }

            if (nn % p != 0) continue;

            long q = nn / p;
            if (isPrime(q)) {
                map.put(q, 0);
                while (n > 0) {
                    if (n % q != 0) {
                        break;
                    }
                    map.compute(q, (k, old) -> old + 1);
                    n /= q;
                }
            }
        }

        int total = 0;
        for (long key : map.keySet()) {
            int m = map.get(key);
            for (int i = 1; m - i >= 0; i++) {
                total++;
                m = m - i;
            }
        }

        System.out.println(total);

    }

    static boolean isPrime(long n) {
        if (n == 1) return false;
        if (n == 2) return true;
        for (long i = 2; i < Math.sqrt(n) + 1; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
