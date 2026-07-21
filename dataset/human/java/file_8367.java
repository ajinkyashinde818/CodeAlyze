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
        ABC148_c solver = new ABC148_c();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC148_c {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long A = in.nextLong();
            long B = in.nextLong();

            out.println(A * B / gcd(A, B));

        }

        private long gcd(long m, long n) {
            if (m < n) return gcd(n, m);
            if (n == 0) return m;
            return gcd(n, m % n);
        }

    }
}
