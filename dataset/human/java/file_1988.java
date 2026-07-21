import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        long n = Long.parseLong(sc.next());
        sc.close();

        // 主処理
        int result = 0;
        if (n != 1) {
            Map<Integer, Integer> map = primeFactorizationMap(n);

            int[] count = new int[40];
            for (int i = 1; i < count.length; i++) {
                count[i] = count[i - 1] + i;
            }

            for (int key : map.keySet()) {
                int val = map.get(key);
                for (int i = 0; i < count.length; i++) {
                    if (val < count[i]) {
                        result += i - 1;
                        break;
                    }
                }
            }
        }

        // 出力
        System.out.println(result);

    }

    public static Map<Integer, Integer> primeFactorizationMap(long num) {
        Map<Integer, Integer> map = new HashMap<>();
        int max = (int) Math.sqrt(num);
        int div = 2;
        while (div <= max) {
            if (num % div == 0) {
                num /= div;
                if (map.containsKey(div)) {
                    map.put(div, map.get(div) + 1);
                } else {
                    map.put(div, 1);
                }
            } else {
                div++;
            }
        }
        if (num != 1) {
            map.put((int) num, 1);
        }
        return map;
    }
}
