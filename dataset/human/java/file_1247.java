import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        long[] as = new long[N];
        long sum = 0;

        for (int i = 0; i < N; i++) {
            as[i] = sc.nextLong();
            sum += as[i];
        }

        // calc cumulative sums
        long[] cumulativeSums = new long[N];
        cumulativeSums[0] = as[0];
        for (int i = 1; i < N; i++) {
            cumulativeSums[i] = as[i] + cumulativeSums[i - 1];
        }

        long diffMin = Long.MAX_VALUE;
        for (int i = 0; i < N - 1; i++) {
            long opponent = sum - cumulativeSums[i];
            long diff = Math.abs(opponent - cumulativeSums[i]);
            diffMin = Math.min(diffMin, diff);
        }
        System.out.println(diffMin);
    }

}
