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
        B solver = new B();
        solver.solve(1, in, out);
        out.close();
    }

    static class B {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();

            Arrays.sort(s);
            Arrays.sort(t);

            int ans = new String(s).compareTo(new StringBuilder(new String(t)).reverse().toString());

            // 出力
            out.println(ans < 0 ? "Yes" : "No");

        }

    }
}
