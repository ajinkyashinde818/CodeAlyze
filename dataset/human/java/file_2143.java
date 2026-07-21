import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {

    private static List<Long> primeFactors(long n) {
        List<Long> list = new ArrayList<>();
        while (n % 2 == 0) {
            list.add(2L);
            n /= 2;
        }
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                list.add(i);
                n /= i;
            }
        }
        if (n > 2) {
            list.add(n);
        }
        return list;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        List<Long> list = primeFactors(n);
        Collections.sort(list);
        Map<Long, Long> map = new HashMap<>();
        for (int i = 0; i < list.size(); i++) {
            map.put(list.get(i), map.getOrDefault(list.get(i), 0L) + 1);
        }
        long ans = 0;
        for (Entry<Long, Long> e : map.entrySet()) {
            long v = e.getValue();
            int cnt = 1;
            while (v - cnt >= 0) {
                ans++;
                v -= cnt;
                cnt++;
            }
        }
        System.out.println(ans);
    }

}
