import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;

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
            int a = Integer.parseInt(in.next());
            int b = Integer.parseInt(in.next());
            int k = Integer.parseInt(in.next());
            List<Integer> ans = new ArrayList<>();

            int i = 1;
            while (true) {
                if (i > a && i > b) break;

                if (a % i == 0 && b % i == 0) ans.add(i);

                i++;
            }

            Collections.sort(ans, Collections.reverseOrder());
            // 出力
            out.println(ans.get(k - 1));

        }

    }
}
