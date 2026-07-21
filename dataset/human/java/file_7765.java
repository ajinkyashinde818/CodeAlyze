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
        DTeleporter solver = new DTeleporter();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTeleporter {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int n = Integer.parseInt(in.next());
            long K = Long.parseLong(in.next());
            int[] a = new int[n];
            int ans = 0;

            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(in.next()) - 1;
            }

            int logK = 1;
            while ((1L << logK) < K) logK++;
            int[][] doubling = new int[logK][n];
            for (int i = 0; i < n; i++) {
                doubling[0][i] = a[i];
            }
            for (int k = 0; k < logK - 1; k++) {
                for (int i = 0; i < n; i++) {
                    doubling[k + 1][i] = doubling[k][doubling[k][i]];
                }
            }
            int now = 0;
            for (int k = 0; K > 0; k++) {
                if ((K & 1) == 1) now = doubling[k][now];
                K = K >> 1;
            }
            // 出力
            out.println(now + 1);

        }

    }
}
