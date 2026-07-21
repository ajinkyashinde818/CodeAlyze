import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ZYCSwing
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            int l = 0, r = s.length() - 1;
            int res = 0;
            while (l < r) {
                if (s.charAt(l) == s.charAt(r)) {
                    ++l;
                    --r;
                } else if (s.charAt(l) == 'x') {
                    ++l;
                    ++res;
                } else if (s.charAt(r) == 'x') {
                    --r;
                    ++res;
                } else {
                    out.println(-1);
                    return;
                }
            }
            out.println(res);
        }

    }
}
