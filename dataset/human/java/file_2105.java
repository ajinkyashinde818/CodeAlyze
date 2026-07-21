import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.HashMap;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DivGame solver = new DivGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DivGame {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long num = in.nextLong();

            int ans = 0;
            HashMap<Long, Long> map = primeFactorize(num);
            if (map.isEmpty()) {
                out.append("0\n");
                return;
            }
            for (Long key : map.keySet()) {
                long v = map.get(key);
                for (long j = 1; j <= v; j++) {
                    if (v > 0) {
                        ans++;
                    }
                    v -= j;
                }
            }

            out.append(String.valueOf(ans));
        }

        static HashMap<Long, Long> primeFactorize(long x) {
            HashMap<Long, Long> result = new HashMap<>();
            for (long i = 2; i * i <= x; i++) {
                if (x % i != 0) {
                    continue;
                }
                long ex = 0;
                while (x % i == 0) {
                    ex++;
                    x /= i;
                }
                result.put(i, ex);
            }
            if (x != 1) {
                result.put(x, 1L);
            }
            return result;
        }

    }
}
