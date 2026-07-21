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
        DoubleFactorial solver = new DoubleFactorial();
        solver.solve(1, in, out);
        out.close();
    }

    static class DoubleFactorial {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long n = in.nextLong();

            if (n % 2 == 1) {
                out.println(0);
                return;
            }

            long result = 0;
            n /= 2;
            while (0 < n) {
                n = n / 5;
                result += n;
            }
            out.println(result);

        }

    }
}
