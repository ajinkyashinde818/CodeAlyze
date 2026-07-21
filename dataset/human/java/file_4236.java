import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Akash
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BBuffet solver = new BBuffet();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBuffet {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int a[] = ReadInput.readIntArray(n, in);
            int b[] = ReadInput.readIntArray(n, in);
            int c[] = ReadInput.readIntArray(n - 1, in);
            int prev = -1;
            long total = 0;
            for (int i = 0; i < n; i++) {
                int cur = a[i];
                total += b[cur - 1];
                if (cur - prev == 1) {
                    total += c[prev - 1];
                }
                prev = cur;
            }
            out.println(total);
        }

    }

    static class ReadInput {
        public static int[] readIntArray(int size, Scanner in) {
            int a[] = new int[size];
            for (int i = 0; i < size; i++) {
                a[i] = in.nextInt();
            }
            return a;
        }

    }
}
