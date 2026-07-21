import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CCatSnukeAndAVoyage solver = new CCatSnukeAndAVoyage();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCatSnukeAndAVoyage {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            Set<Integer> p = new HashSet<>(), q = new HashSet<>();
            int n = in.nextInt(), m = in.nextInt();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                if (a == 1) {
                    p.add(b);
                } else if (b == n) {
                    q.add(a);
                }
            }
            p.retainAll(q);
            out.println(p.isEmpty() ? "IMPOSSIBLE" : "POSSIBLE");
        }

    }
}
