import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = Long.parseLong(sc.next());
        Map<Long, Long> map = getPf(n);
        long ans = 0;
        for (Map.Entry<Long, Long> e : map.entrySet()) {
            int temp = 1;
            long temp2 = e.getValue();
            while (temp <= temp2) {
                temp2 -= temp;
                temp++;
                ans++;
            }
        }
        System.out.println(ans);
    }

    private static Map<Long, Long> getPf(long n) {
        Map<Long, Long> map = new HashMap<>();
        for (long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                map.merge(i, 1L, Long::sum);
                n /= i;
            }
        }
        if (n != 1) {
            map.put(n, 1L);
        }
        return map;
    }
}
