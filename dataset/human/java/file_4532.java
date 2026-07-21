import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author hakamada
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AGC30_1 solver = new AGC30_1();
        solver.solve(1, in, out);
        out.close();
    }

    static class AGC30_1 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int A = in.nextInt();
            int B = in.nextInt();
            int C = in.nextInt();
            int geta = 0;

            if (A + B < C) {
                geta = 1;
            }

            if (B > C) {
                out.println(B + C + geta);
                return;
            } else {
                int diff = C - B;
                if (A > diff) {
                    out.println(B + B + diff + geta);
                } else {
                    out.println(B + B + A + geta);
                }
            }

        }

    }
}
