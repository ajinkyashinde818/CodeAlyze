import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.HashMap;

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
        Teleporter solver = new Teleporter();
        solver.solve(1, in, out);
        out.close();
    }

    static class Teleporter {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long k = in.nextLong();

            HashMap<Integer, Integer> map = new HashMap<>();
            int[] circle = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                int t = in.nextInt();
                map.put(i, t);
            }

            Integer next = 1;
            circle[1]++;

            int close_start;
            while (true) {
                next = map.get(next);
                if (circle[next] == 3) {
                    close_start = next;
                    break;
                }
                circle[next]++;
            }

            int closed_step = 1;
            int tmp_close = map.get(close_start);
            while (tmp_close != close_start) {
                tmp_close = map.get(tmp_close);
                closed_step++;
            }

            long up_steps = 1;
            next = map.get(1);

            while (true) {
                if (next == close_start || up_steps >= k) {
                    break;
                }
                next = map.get(next);
                up_steps++;
            }

            long loop_num = (k - up_steps) % closed_step;
            for (int i = 0; i < loop_num; i++) {
                next = map.get(next);
            }
            out.append(String.valueOf(next));
        }

    }
}
