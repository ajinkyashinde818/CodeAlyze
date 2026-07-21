import static java.lang.Integer.*;
import static java.lang.Integer.max;
import static java.lang.Integer.min;
import static java.lang.Long.*;
import static java.lang.System.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static void solve() throws Exception {
        int k = scanInt(), n = scanInt();
        int load[] = new int[n];
        int mi = Integer.MAX_VALUE, ma = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            load[i] = scanInt();
            mi = min(mi, load[i]);
            ma = max(ma, load[i]);
        }
        int answer = ma - mi;
        Arrays.sort(load);
        for (int i = 0; i < n - 1; i++) {
            answer = min(answer, load[i] + k - load[i + 1]);
        }
        out.print(answer);
    }

    static int scanInt() throws IOException {
        return parseInt(scanString());
    }

    static long scanLong() throws IOException {
        return parseLong(scanString());
    }

    static String scanString() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    public static void main(String[] args) {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();
            in.close();
            out.close();
        }
        catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}
