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
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 整数の入力
            long a = Long.parseLong(in.next());
            long b = Long.parseLong(in.next());
            long ans = 0;

            ans = lcm(a, b);

            // 出力
            out.println(ans);

        }

        static long lcm(long a, long b) {
            long temp;
            long c = a;
            c *= b;
            while ((temp = a % b) != 0) {
                a = b;
                b = temp;
            }
            return (long) (c / b);
        }

    }
}
