import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AHEX solver = new AHEX();
        solver.solve(1, in, out);
        out.close();
    }

    static class AHEX {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            char x = in.next().charAt(0), y = in.next().charAt(0);
            if (x == y) {
                out.println("=");
            } else if (x > y) {
                out.println(">");
            } else {
                out.println("<");
            }
        }

    }
}
