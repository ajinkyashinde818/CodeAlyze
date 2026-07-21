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
        ABC049C solver = new ABC049C();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC049C {
        static String[] strs = {
                "dream",
                "dreamer",
                "erase",
                "eraser"
        };

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();

            s = s.replaceAll(strs[3], "-");
            s = s.replaceAll(strs[2], "-");
            s = s.replaceAll(strs[1], "-");
            s = s.replaceAll(strs[0], "-");
            s = s.replaceAll("-", "");

            if (s.length() == 0) {
                out.println("YES");
            } else {
                out.println("NO");
            }

        }

    }
}
