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

    int[] c, dep;
    int len, pos;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long k = in.nextLong();
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) a[i] = in.nextInt();
        dep = new int[n + 1];
        c = new int[n + 1];
        findCycle(a, 1, 1);
        if (k < pos) {
            out.println(c[(int)k + 1]);
        } else {
            long p = pos + (k + 1 - pos) % (len - pos + 1);
            out.println(c[(int)p]);
        }
   }

    private void findCycle(int[] a, int s, int d) {
        if (dep[s] > 0) {
            pos = dep[s];
            return;
        }
        dep[s] = d;
        c[++len] = s;
        findCycle(a, a[s], d + 1);
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
