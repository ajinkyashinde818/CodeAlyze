import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

import static java.util.Arrays.binarySearch;
import static java.util.Arrays.copyOfRange;
import static java.util.Arrays.sort;

public class Main {

    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
}

class Task {

    private static int mod = 998244353;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int x = in.nextInt();
        int[] c = new int[n];
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
            }
        }
        int ans = -1;
        for (int i = 0; i < (1 << n); i++) {
            int s = 0;
            int[] b = new int[m];
            for (int j = 0; j < n; j++) if (((i >> j) & 1) == 1) {
                s += c[j];
                for (int k = 0; k < m; k++) {
                    b[k] += a[j][k];
                }
            }
            if (ok(b, x)) {
                if (ans == -1 || ans > s) {
                    ans = s;
                }
            }
        }
        out.println(ans);

   }

    private boolean ok(int[] b, int x) {
        for (int i = 0; i < b.length; i++) {
            if (b[i] < x) {
                return false;
            }
        }
        return true;
    }

}

class InputReader {

    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

}
