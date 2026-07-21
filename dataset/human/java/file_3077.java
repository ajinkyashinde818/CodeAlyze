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
        A2 solver = new A2();
        solver.solve(1, in, out);
        out.close();
    }

    static class A2 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int n = Integer.parseInt(in.next());
            int m = Integer.parseInt(in.next());
            int[] start = new int[n];
            int[] goal = new int[n];
            for (int i = 0; i < m; i++) {
                int a = Integer.parseInt(in.next()) - 1;
                int b = Integer.parseInt(in.next()) - 1;
                if (a == 0) {
                    start[b] = 1;
                } else if (b == (n - 1)) {
                    goal[a] = 1;
                }
            }
            boolean ok = false;
            for (int i = 0; i < n; i++) {
                if (start[i] >= 1 && goal[i] >= 1) ok = true;
            }
            out.println(ok ? "POSSIBLE" : "IMPOSSIBLE");

        }

    }
}
