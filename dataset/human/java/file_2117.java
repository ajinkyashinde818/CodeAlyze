import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long val = scanner.nextLong();
        HashMap<Long, Integer> factors = new HashMap<>();
        for (long i = 2; i <= Math.sqrt(val); i++) {
            while (val % i == 0) {
                factors.compute(i, (k, v) -> v == null ? 1 : v + 1);
                val = val / i;
            }
        }
        if (val != 1) {
            factors.compute(val, (k, v) -> v == null ? 1 : v + 1);
        }

        int result = 0;
        for (Map.Entry<Long, Integer> entry : factors.entrySet()) {
            int current = entry.getValue();
            for (int i = 1; i <= current; i++) {
                current -= i;
                result++;
            }
        }
        System.out.println(result);
    }
}
