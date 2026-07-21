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
        abc160_c solver = new abc160_c();
        solver.solve(1, in, out);
        out.close();
    }

    static class abc160_c {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int K = in.nextInt();
            int N = in.nextInt();
            long A[] = new long[N];
            long seg[] = new long[N];
            long max_far = 0;
            long max_far_seg = -1;
            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
            }
            max_far = (K - A[N - 1]) + A[0];
            max_far_seg = 0;
            seg[0] = max_far;
            for (int i = 1; i < N; i++) {
                long far = A[i] - A[i - 1];
                seg[i] = far;
                if (max_far < far) {
                    max_far = far;
                    max_far_seg = i;
                }
            }
            long ttldist = 0;
            for (int i = 0; i < N; i++) {
                if (max_far_seg != i) {
                    ttldist += seg[i];
                }
            }
            out.println(ttldist);
        }

    }
}
