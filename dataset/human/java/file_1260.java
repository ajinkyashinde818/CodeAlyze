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
        SplittingPile solver = new SplittingPile();
        solver.solve(1, in, out);
        out.close();
    }

    static class SplittingPile {
        long[] a;
        long result;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            a = new long[n];
            result = Long.MAX_VALUE;

            long sum = 0;
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(in.next());
                sum += a[i];
            }
            long beer = 0;
            for (int i = 0; i < n - 1; i++) {
                sum -= a[i];
                beer += a[i];
                result = Math.min(result, Math.abs(sum - beer));
            }
            out.println(result);
        }

    }
}
