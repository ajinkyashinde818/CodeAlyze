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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // 入力
            String S = in.next();
            int q = Integer.parseInt(in.next());

            int query_op = 0;
            boolean reverseFlg = false;
            StringBuilder sb = new StringBuilder(S);
            StringBuilder sb_rev = new StringBuilder();
            for (int i = 0; i < q; i++) {
                query_op = Integer.parseInt(in.next());
                if (reverseFlg == false && query_op == 1) {
                    reverseFlg = true;
                } else if (reverseFlg == true && query_op == 1) {
                    reverseFlg = false;
                } else if (reverseFlg == false && query_op == 2) {
                    int query_op2 = Integer.parseInt(in.next());
                    char query_ch = in.next().charAt(0);
                    if (query_op2 == 1) {
                        sb_rev.append(query_ch);
                    } else if (query_op2 == 2) {
                        sb.append(query_ch);
                    }

                } else if (reverseFlg == true && query_op == 2) {
                    int query_op2 = Integer.parseInt(in.next());
                    char query_ch = in.next().charAt(0);
                    if (query_op2 == 1) {
                        sb.append(query_ch);
                    } else if (query_op2 == 2) {
                        sb_rev.append(query_ch);
                    }
                }

            }
            if (reverseFlg == true) {
                out.println(sb.reverse().append(sb_rev));
            } else {
                out.println(sb_rev.reverse().append(sb));
            }


        }

    }
}
