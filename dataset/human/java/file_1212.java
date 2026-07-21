import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author zhangyong
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n;
            n = in.nextInt();
            long[] arr = new long[n];
            long sum = 0;
            for (int i = 0; i < arr.length; i++) {
                arr[i] = in.nextLong();
                sum += arr[i];
            }
            long x = 0;
            long min = Long.MAX_VALUE;
            for (int i = 0; i < n - 1; i++) {
                x += arr[i];
                min = Math.min(min, Math.abs(sum - 2 * x));
            }
            out.println(min);
        }

    }
}
