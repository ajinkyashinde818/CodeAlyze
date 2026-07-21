import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author bcools
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long[] xs = new long[n];
            long sum = 0;
            for (int i = 0; i < n; ++i) {
                int tmp = in.nextInt();
                sum += tmp;
                xs[i] = tmp + ((i > 0) ? xs[i - 1] : 0);
            }

            long minDiff = Long.MAX_VALUE;
            for (int i = 0; i < n - 1; ++i) {
                minDiff = Math.min(minDiff, Math.abs(xs[i] - (sum - xs[i])));
            }
            out.println(minDiff);
        }

    }
}
