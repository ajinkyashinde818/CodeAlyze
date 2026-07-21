import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(final String[] args) {
        final FastScanner scanner = new FastScanner();
        try (final FastWriter writer = new FastWriter()) {
            String N = scanner.next();
            int[] n = new int[N.length()];
            for (int i = N.length() - 1; i >= 0; i--) {
                n[i] = N.charAt(i) - '0';
            }
            int[] dp1 = new int[n.length], dp2 = new int[n.length];
            dp1[n.length - 1] = n[n.length - 1];
            dp2[n.length - 1] = 10 - n[n.length - 1];
            for (int i = n.length - 2; i >= 0; i--) {
                dp1[i] = Math.min(dp1[i + 1] + n[i], dp2[i + 1] + n[i] + 1);
                if (n[i] + 1 <= 10)
                    dp2[i] = Math.min(dp1[i + 1] + 10 - n[i], dp2[i + 1] + 10 - n[i] - 1);
                else dp2[i] = dp1[i + 1] + 10 - n[i];
            }
            writer.println(Math.min(dp1[0], dp2[0] + 1));
        }
    }
}

class FastScanner {
    private final BufferedReader br;
    private StringTokenizer st;

    public FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (final IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
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

    public String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (final IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

class FastWriter extends PrintWriter {
    public FastWriter() {
        super(new BufferedOutputStream(System.out));
    }

    public static void main(final String[] args) {
        try (final FastWriter w = new FastWriter()) {
            w.println(32);
        }
    }
}
