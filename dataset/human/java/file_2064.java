import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    static Map<Long, Long> fact(long N) {
        Map<Long, Long> ret = new HashMap<>();
        long i = 2;
        while (i <= Math.sqrt(N)) {
            long cnt = 0;
            while (N > 0 && N % i == 0) {
                cnt++;
                N /= i;
            }
            if (cnt > 0) {
                ret.put(i, cnt);
            }
            i++;
        }
        if (N > 2) ret.put(N, 1L);

        return ret;
    }

    static long solve(long N) {
        Map<Long, Long> factor = fact(N);
        long ret = 0;
        for (long k : factor.keySet()) {
            long cnt = factor.get(k);
            int i = 1;
            while (i * (i + 1) / 2 <= cnt) i++;
            ret += i - 1;
        }

        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long N = in.nextLong();
        System.out.println(solve(N));
    }
}
