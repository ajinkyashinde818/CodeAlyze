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
        ABC051_B solver = new ABC051_B();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC051_B {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int k = in.nextInt();
            int s = in.nextInt();

            int counter = 0;
            for (int i = 0; i <= k; ++i) {
                for (int j = 0; j <= k; ++j) {
                    int l = s - (i + j);
                    if (l >= 0 && l <= k) ++counter;
                    else continue;
                    ;
                }
            }

            out.println(counter);
        }

    }
}
