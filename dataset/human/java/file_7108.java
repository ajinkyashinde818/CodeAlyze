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
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int k = Integer.parseInt(in.next());
            int n = Integer.parseInt(in.next());
            int a[] = new int[n + 1];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(in.next());
            }
            a[n] = a[0] + k;
            int ans[] = new int[n + 1];
            for (int i = 0; i < n; i++) {
                if (a[i] > k) a[i] = a[i] - k;
//            if (a[i] < 20 && i == n - 1) {
//                ans[i] = a[i] - a[0];
//            } else {
                ans[i] = a[i + 1] - a[i];
//            }
            }

            Arrays.sort(ans);
            int tmp = 0;
            // 出力
            for (int i = 0; i < n; i++) {
                tmp += ans[i];
            }
            out.println(tmp);

        }

    }
}
