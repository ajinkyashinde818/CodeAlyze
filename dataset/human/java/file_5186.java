import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayDeque;

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
        DStringFormation solver = new DStringFormation();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStringFormation {
        public void solve(int testNumber, Scanner in, PrintWriter out) {

            String s = in.next();

            ArrayDeque<String> ad = new ArrayDeque<>();

            boolean isFirst = true;

            ad.addLast(s);

            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                int num = in.nextInt();
                if (num == 1) {
                    isFirst = !isFirst;
                } else {
                    boolean fir = in.nextInt() == 1;
                    String t = in.next();
                    if (fir ^ isFirst) {
                        // 末尾
                        ad.addLast(t);
                    } else {
                        ad.addFirst(t);
                    }
                }
            }

            StringBuffer sb = new StringBuffer();
            while (!ad.isEmpty()) {
                sb.append(ad.pollFirst());
            }

            if (isFirst) {
                out.println(sb.toString());
            } else {
                out.println(sb.reverse().toString());
            }


        }

    }
}
