import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    private BufferedReader in;
    private StringTokenizer tok;
    private PrintWriter out;

    //------------------------------------------------------------------------------
    public static void main(String[] args) {
        new Main().run();
    }

    private void solve() throws IOException {
        int n = readInt();
        long c = readLong();
        long[] x = new long[n];
        long[] v = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = readLong();
            v[i] = readLong();
        }
        long[] prefV = new long[n];
        prefV[0] = v[0];
        for (int i = 1; i < n; i++) {
            prefV[i] = prefV[i - 1] + v[i];
        }
        long[] leftAns = new long[n + 1];
        long[] rightAns = new long[n + 1];
        long[] leftThenBack = new long[n + 1];
        long[] rightThenBack = new long[n + 1];
        for (int i = 0; i < n; i++) {
            leftAns[i + 1] = prefV[i] - x[i];
            leftThenBack[i + 1] = prefV[i] - 2 * x[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            rightAns[n - i] = (prefV[n - 1] - (i == 0 ? 0 : prefV[i - 1])) - (c - x[i]);
            rightThenBack[n - i] = (prefV[n - 1] - (i == 0 ? 0 : prefV[i - 1])) - 2 * (c - x[i]);
        }
        long[] leftMax = new long[n + 1];
        long[] rightMax = new long[n + 1];
        for (int i = 0; i < n; i++) {
            leftMax[i + 1] = Math.max(leftAns[i + 1], leftMax[i]);
        }
        for (int i = 0; i < n; i++) {
            rightMax[i + 1] = Math.max(rightAns[i + 1], rightMax[i]);
        }
        long ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = Math.max(ans, leftAns[i]);
            ans = Math.max(ans, rightAns[i]);
        }
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, leftThenBack[i] + rightMax[n - i]);
            ans = Math.max(ans, rightThenBack[i] + leftMax[n - i]);
        }
        out.println(ans);
    }

    private void run() {
        try {
            initIO();
            solve();
            in.close();
            out.close();
        } catch (Throwable e) {
            throw new RuntimeException(e);
        }
    }

    private void initIO() throws IOException {
        try {
            in = new BufferedReader(new FileReader(new File("input.txt")));
            out = new PrintWriter(new File("output.txt"));
        } catch (Exception e) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    private String readString() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    @SuppressWarnings("unused")
    private int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    @SuppressWarnings("unused")
    private long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    @SuppressWarnings("unused")
    private double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
}
