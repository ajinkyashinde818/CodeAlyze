import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Eric
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskCC solver = new TaskCC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskCC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long a = in.nextInt();
            long b = in.nextInt();

            long pgcd = pgcd(a, b);
            out.println((a / pgcd) * b);
        }

        private long pgcd(long a, long b) {
            if (b == 0)
                return a;
            if (a < b)
                return pgcd(b, a);
            else {
                long div = a / b;
                return pgcd(b, a - div * b);
            }
        }

    }
}
