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
        A solver = new A();
        solver.solve(1, in, out);
        out.close();
    }

    static class A {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            String S = in.next();
            boolean[] flg = new boolean[3];
            flg[S.charAt(0) - 'a'] = true;
            flg[S.charAt(1) - 'a'] = true;
            flg[S.charAt(2) - 'a'] = true;
            out.println(flg[0] && flg[1] && flg[2] ? "Yes" : "No");

        }

    }
}
