import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
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
        BSumOfThreeIntegers solver = new BSumOfThreeIntegers();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSumOfThreeIntegers {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int k = in.nextInt(), s = in.nextInt();
            out.println(IntStream.rangeClosed(Math.max(0, s - 2 * k), Math.min(k, s))
                    .map(x -> Math.min(k, s - x) - Math.max(0, s - x - k) + 1)
                    .filter(v -> v > 0)
                    .sum());
        }

    }
}
