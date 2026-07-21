import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author berat
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BeyzasVacation solver = new BeyzasVacation();
        solver.solve(1, in, out);
        out.close();
    }

    static class BeyzasVacation {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            boolean[] visited = new boolean[n];
            boolean found = false;

            for (int i = 0; i < m; i++) {
                int from = in.nextInt();
                int to = in.nextInt();
                if (from == 1) {
                    if (visited[to]) {
                        found = true;
                        break;
                    }
                    visited[to] = true;
                } else if (to == n) {
                    if (visited[from]) {
                        found = true;
                        break;
                    }
                    visited[from] = true;
                }
            }
            out.println(found ? "POSSIBLE" : "IMPOSSIBLE");
        }

    }
}
