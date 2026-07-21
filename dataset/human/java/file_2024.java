import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.util.Scanner;
import java.util.Set;

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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            long N = Long.parseLong(in.next());

            MultiSet ms = Factrization(N);
            // 出力
            long ans = 0;
            for (long k : ms.keyset()) {
                long num = 1;
                long val = ms.set.get(k);
                int cnt = 0;
                while (val >= 0) {
                    val -= num;
                    ++num;
                    if (val >= 0) {
                        ++cnt;
                    }
                }
                ans += cnt;
            }
            out.println(ans);


        }

        public MultiSet Factrization(long e) {
            MultiSet ret = new MultiSet();
            for (long i = 2; i * i <= e; i++) {
                while (e % i == 0) {
                    ret.add(i);
                    e /= i;
                }
            }
            if (e != 1) ret.add(e);
            return ret;
        }

        class MultiSet {
            TreeMap<Long, Long> set;
            long size;
            long sum;

            MultiSet() {
                set = new TreeMap<Long, Long>();
                size = 0;
                sum = 0;
            }

            void add(long e) {
                if (set.containsKey(e)) set.put(e, set.get(e) + 1);
                else set.put(e, 1L);
                size++;
                sum += e;
            }

            Set<Long> keyset() {
                return set.keySet();
            }

        }

    }
}
