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
            String S = in.next();
            S = S.replaceAll("eraser", "-");
            S = S.replaceAll("erase", "-");
            S = S.replaceAll("dreamer", "-");
            S = S.replaceAll("dream", "-");
            S = S.replaceAll("-", "");
            if (S.length() == 0)
                out.println("YES");
            else
                out.println("NO");
        }

    }
}
