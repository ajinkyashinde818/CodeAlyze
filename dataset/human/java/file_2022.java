import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();

        final Map<Long, Integer> pfs = new HashMap<>();
        for (long i = 2; i*i <= n; i++) {
            int x = 0;
            while (n % i == 0) {
                n /= i;
                x++;
            }
            pfs.put(i, x);
        }

        if (n != 1) {
            pfs.put(n, 1);
        }

        int ans = 0;

        for (Map.Entry<Long, Integer> entry : pfs.entrySet()) {
            int x = entry.getValue();
            int b = 1;
            while (b <= x) {
                x -= b;
                b++;
                ans++;
            }
        }

        System.out.println(ans);
    }
}
