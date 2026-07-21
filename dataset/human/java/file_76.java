import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        FlippingSigns solver = new FlippingSigns();
        solver.solve(1, in, out);
        out.close();
    }

    static class FlippingSigns {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
            long count = 0;
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
                if (a[i] < 0) {
                    count++;
                    a[i] = -a[i];
                }
            }

            long result = 0;
            for (int i = 0; i < n; i++) {
                result += Math.abs(a[i]);
            }
            if (count % 2 == 0) {
                out.println(result);
                return;
            }
            Arrays.sort(a);
            out.println(result - a[0] * 2);

        }

    }
}
