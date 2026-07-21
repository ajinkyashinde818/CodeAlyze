import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        long N = scan.nextLong();
        HashMap<Long, Long> factorizations = new HashMap<>();
        long current = N;
        for (long i = 2; i * i <= current; i++) {
            while (current % i == 0) {
                factorizations.merge(i, 1L, Long::sum);
                current /= i;
            }
        }
        if (current != 1) {
            factorizations.merge(current, 1L, Long::sum);
        }
        long ans = 0;
        for (long prime : factorizations.keySet()) {
            long count = factorizations.get(prime);
            long left = 1;
            long right = count;
            while (left <= right) {
                long mid = (left + right) / 2;
                if (mid * (mid + 1) <= 2 * count) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans += right;
        }
        System.out.println(ans);
    }
}
