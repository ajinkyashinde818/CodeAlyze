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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();

            Arrays.sort(s);
            Arrays.sort(t);

            for (int i = 0; i < Math.min(s.length, t.length); i++) {
                char c = s[i];
                char c2 = t[t.length - 1 - i];
                if (c < c2) {
                    out.print("Yes");
                    return;
                } else if (c2 < c) {
                    out.print("No");
                    return;
                } else {
                    continue;
                }
            }
            if (s.length < t.length) {
                out.print("Yes");
            } else {
                out.print("No");
            }
        }

    }
}
