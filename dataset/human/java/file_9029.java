import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author silviase
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CTypicalStairs solver = new CTypicalStairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTypicalStairs {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            ModInt[] res = new ModInt[n + 1];
            HashSet<Integer> hs = new HashSet<>();
            for (int i = 0; i < m; i++) {
                hs.add(in.nextInt());
            }

            res[0] = new ModInt(1);
            for (int i = 1; i <= n; i++) {
                if (hs.contains(i)) {
                    // broken
                    res[i] = new ModInt(0);
                } else {
                    res[i] = new ModInt(0);
                    try {
                        res[i] = res[i].add(res[i - 1]);
                    } catch (ArrayIndexOutOfBoundsException ignored) {
                    }
                    try {
                        res[i] = res[i].add(res[i - 2]);
                    } catch (ArrayIndexOutOfBoundsException ignored) {
                    }
                }
            }

            out.println(res[n].getVal());

        }

    }

    static class ModInt {
        public long val;
        final int MOD = (int) 1e9 + 7;

        public ModInt(long i) {
            this.val = (i + MOD) % MOD;
        }

        public ModInt add(ModInt m) {
            return new ModInt(this.val + m.val);
        }

        public long getVal() {
            return val;
        }

        public String toString() {
            return Long.toString(val);
        }

    }
}
