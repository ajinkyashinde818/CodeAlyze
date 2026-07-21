import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        Solver s = new Solver();
        for (int i = 1; i <= t; i++) {
            s.solve(i, in, out);
        }
        out.close();
    }

}

class Solver {

    void solve(int test, InputReader in, PrintWriter out) throws IOException {
        char[] s = in.next().toCharArray();
        char[] t = in.next().toCharArray();
        Arrays.sort(t);
        Arrays.sort(s);
        int n = t.length;
        for (int i = 0; i < n / 2; i++) {
            char ut = t[i];
            t[i] = t[n - i - 1];
            t[n - i - 1] = ut;
        }
//        out.println(s);
//        out.println(t);
        for (int i = 0; i < Math.min(t.length, s.length); i++) {
            if (s[i] < t[i]) {
                out.println("Yes");
                return;
            }
            if (t[i] < s[i]) {
                out.println("No");
                return;
            }
        }
        if (t.length > s.length) {
            out.println("Yes");
        } else {
            out.println("No");
        }
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = null;
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
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

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}
