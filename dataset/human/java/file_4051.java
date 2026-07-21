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
        B solver = new B();
        solver.solve(1, in, out);
        out.close();
    }

    static class B {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int n = Integer.parseInt(in.next());
            int a[] = new int[n];
            int b[] = new int[n];
            int c[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(in.next());
            }
            for (int i = 0; i < n; i++) {
                b[i] = Integer.parseInt(in.next());
            }
            for (int i = 0; i < n - 1; i++) {
                c[i] = Integer.parseInt(in.next());
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += b[a[i] - 1];
                if (i > 0 && (a[i] - a[i - 1]) == 1) ans += c[a[i - 1] - 1];
            }

            // 出力
            out.println(ans);

        }

    }
}
