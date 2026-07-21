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
        BGoToJail solver = new BGoToJail();
        solver.solve(1, in, out);
        out.close();
    }

    static class BGoToJail {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int n = Integer.parseInt(in.next());
            int[] d1 = new int[n];
            int[] d2 = new int[n];
            for (int i = 0; i < n; i++) {
                d1[i] = Integer.parseInt(in.next());
                d2[i] = Integer.parseInt(in.next());
            }
            for (int i = 0; i < n - 2; i++) {
                if (d1[i] == d2[i] && d1[i + 1] == d2[i + 1] && d1[i + 2] == d2[i + 2]) {
                    out.println("Yes");
                    return;
                }
            }
            out.println("No");
            return;

        }

    }
}
