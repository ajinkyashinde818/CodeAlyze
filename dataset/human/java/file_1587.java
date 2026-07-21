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
        B solver = new B();
        solver.solve(1, in, out);
        out.close();
    }

    static class B {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            int n = Integer.parseInt(in.next());
            int m = Integer.parseInt(in.next());

            char a[][] = new char[n][n];
            char b[][] = new char[m][m];

            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }
            for (int i = 0; i < m; i++) {
                b[i] = in.next().toCharArray();
            }

            boolean ok = false;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + m - 1) >= n || (j + m - 1) >= n) continue;
                    boolean match = true;
                    for (int k = 0; k < m; k++) {
                        for (int l = 0; l < m; l++) {
                            if (a[i + k][j + l] != b[k][l]) match = false;
                        }
                    }
                    if (match) ok = true;
                }
            }
            if (ok) {
                out.println("Yes");
            } else {
                out.println("No");
            }
        }

    }
}
