import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Silviase
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CCatSnukeandaVoyage solver = new CCatSnukeandaVoyage();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCatSnukeandaVoyage {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            boolean f = false;
            boolean[] ichi = new boolean[n + 1];
            boolean[] enu = new boolean[n + 1];
            for (int i = 0; i < n + 1; i++) {
                ichi[i] = false;
                enu[i] = false;
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                if (a == 1) {
                    ichi[b] = true;
                }
                if (b == n) {
                    enu[a] = true;
                }
            }

            for (int i = 2; i <= n-1; i++) {
                if (ichi[i] && enu[i]) {
                    f = true;
                    break;
                }
            }
            out.println(f ? "POSSIBLE" : "IMPOSSIBLE");

        }

    }
}
