import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        CTravelingSalesmanAroundLake solver = new CTravelingSalesmanAroundLake();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTravelingSalesmanAroundLake {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int k = in.nextInt();
            int n = in.nextInt();
            int[] a = new int[n];
            int max = -1;
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 0; i < n - 1; i++) {
                max = Math.max(max, a[i + 1] - a[i]);
            }
            max = Math.max(max, k - (a[n - 1] - a[0]));
            out.println(k - max);


        }

    }
}
