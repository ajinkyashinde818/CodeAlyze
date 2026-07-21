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
        CTravelingSalesmanAroundLake solver = new CTravelingSalesmanAroundLake();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTravelingSalesmanAroundLake {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int k = Integer.parseInt(in.next());
            int n = Integer.parseInt(in.next());
            int[] a = new int[n];
            int dist = 0;
            int tmpDist;
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(in.next());
                if (i > 0) {
                    tmpDist = a[i] - a[i - 1];
                    if (tmpDist > dist) {
                        dist = tmpDist;
                    }
                }
            }
            tmpDist = a[0] + k - a[n - 1];
            if (tmpDist > dist) {
                dist = tmpDist;
            }
            out.println(k - dist);
        }

    }
}
