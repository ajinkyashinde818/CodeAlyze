import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author silviase
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CSkillUp solver = new CSkillUp();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSkillUp {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int min = Integer.MAX_VALUE;
            int n = in.nextInt();
            int m = in.nextInt();
            int x = in.nextInt();
            int[] c = new int[n];
            int[][] book = new int[n][m];

            for (int i = 0; i < n; i++) {
                c[i] = in.nextInt();
                for (int j = 0; j < m; j++) {
                    book[i][j] = in.nextInt();
                }
            }

            for (int i = 0; i < 1 << n; i++) {
                int cmp = 0;
                int[] skill = new int[m];
                boolean f = true;
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        cmp += c[j];
                        for (int k = 0; k < m; k++) {
                            skill[k] += book[j][k];
                        }
                    }
                }

                for (int k = 0; k < m; k++) {
                    if (skill[k] < x) {
                        f = false;
                        break;
                    }
                }

                if (f) {
                    min = Math.min(min, cmp);
                }

            }

            out.println(min == Integer.MAX_VALUE ? -1 : min);
        }

    }
}
