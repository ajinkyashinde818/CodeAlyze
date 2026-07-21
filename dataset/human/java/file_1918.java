import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author <>
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CAllGreen solver = new CAllGreen();
        solver.solve(1, in, out);
        out.close();
    }

    static class CAllGreen {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int d = in.nextInt();
            int g = in.nextInt() / 100;
            int[] p = new int[d];
            int[] c = new int[d];
            for (int i = 0; i < d; i++) {
                p[i] = in.nextInt();
                c[i] = in.nextInt() / 100;
            }
            int min = Integer.MAX_VALUE;
            TreeSet<Integer> ts = new TreeSet<>(Comparator.reverseOrder());
            for (int i = 1; i <= d; i++) {
                ts.add(i);
            }
            for (int i = 1; i <= (1 << d); i++) {
                int temp = g;
                int res = 0;
                TreeSet<Integer> tsCopy = new TreeSet<>(ts);
                for (int j = 0; j < d; j++) {
                    if ((i & (1 << j)) != 0) {
                        temp -= ((j + 1) * p[j] + c[j]);
                        res += p[j];
                        tsCopy.remove(j + 1);
                    }
                }
                if (temp > 0) {
                    int highest = tsCopy.pollFirst();
                    int plus = (int) Math.ceil((double) temp / highest);
                    if (plus > p[highest - 1]) {
                        continue;
                    }
                    res += plus;
                }
                min = Math.min(min, res);
//            out.println(i + " " + res);
            }
            out.println(min);
        }

    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
