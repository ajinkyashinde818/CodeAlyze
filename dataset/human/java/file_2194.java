import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        Map<Long, Integer> map = new HashMap<Long, Integer>();
        for (int i = 2 ; i <= 1000000 ; i++) {
            while (n % (long) i ==  0) {
                if (map.containsKey((long)i)) {
                    map.put((long) i, map.get((long)i) + 1);
                } else {
                    map.put((long) i, 1);
                }
                n /= (long) i;
            }

        }
        if (n != 1) {
            map.put(n, 1);
        }

        int count = 0;
        for (java.util.Map.Entry<Long, Integer> entry : map.entrySet()) {
            int val = entry.getValue();
            int c = 1;
            while (val - c >= 0) {
                val -= c;
                count++;
                c++;
            }
        }

        System.out.println(count);
     }

}
