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
        ABeginner solver = new ABeginner();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABeginner {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            out.println(100 * Math.max(10 - in.nextInt(), 0) + in.nextInt());
        }

    }
}
