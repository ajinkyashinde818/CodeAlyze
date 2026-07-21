import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

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
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int n = Integer.parseInt(in.next());
            int[] a = new int[n];
            long total = 0;
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(in.next());
                total += a[i];
            }
            long ans = Long.MAX_VALUE;

            long x = 0;
            for (int i = 0; i < n; i++) {
                x += a[i];
                if (i + 1 < n) ans = Math.min(ans, Math.abs(total - 2 * x));
            }
            // 出力
            out.println(ans);

        }

    }
}
