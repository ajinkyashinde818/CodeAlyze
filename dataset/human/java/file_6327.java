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
            int k = Integer.parseInt(in.next());
            int s = Integer.parseInt(in.next());
            int ans = 0;

            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    int z = s - j - i;
                    if (0 <= z && z <= k) {
                        ans++;
                    }
                }
            }

            // 出力
            out.println(ans);

        }

    }
}
