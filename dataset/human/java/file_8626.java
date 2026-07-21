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
        ABC120_2 solver = new ABC120_2();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC120_2 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();
            int a = Math.max(A, B);
            int b = Math.min(A, B);
            int counter = b;
            while (true) {
                if ((a % counter == 0) && (b % counter == 0)) {
                    K--;
                    if (K == 0) {
                        out.println(counter);
                        return;
                    }
                }
                counter--;
            }
        }

    }
}
