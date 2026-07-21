import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class Main {
    private static final int MOD = (int) 1e9 + 7;
    int N,M;
    int[] a;
    private void solve() {
        N = nextInt();
        M = nextInt();
        a = new int[M];
        for(int i = 0;i < M;i++) {
            a[i] = nextInt();
        }

        boolean[] ng = new boolean[N + 1];
        for(int i = 0;i < M;i++) {
            ng[a[i]] = true;
        }

        long[] dp = new long[N + 1];
        dp[0] = 1;
        for(int i = 0;i < N;i++) {
            if (ng[i]) continue;
            if (!ng[i + 1]){
                dp[i + 1] += dp[i];
                dp[i + 1] %= MOD;
            }
            if (i + 2 <= N && !ng[i + 2]) {
                dp[i + 2] += dp[i];
                dp[i + 2] %= MOD;
            }
        }

        out.println(dp[N]);
    }

    public static void main(String[] args) {
        out.flush();
        new Main().solve();
        out.close();
    }

    /* Input */
    private static final InputStream in = System.in;
    private static final PrintWriter out = new PrintWriter(System.out);
    private final byte[] buffer = new byte[4096];
    private int p = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (p < buflen)
            return true;
        p = 0;
        try {
            buflen = in.read(buffer);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (buflen <= 0)
            return false;
        return true;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrint(buffer[p])) {
            p++;
        }
        return hasNextByte();
    }

    private boolean isPrint(int ch) {
        if (ch >= '!' && ch <= '~')
            return true;
        return false;
    }

    private int nextByte() {
        if (!hasNextByte())
            return -1;
        return buffer[p++];
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = -1;
        while (isPrint((b = nextByte()))) {
            sb.appendCodePoint(b);
        }
        return sb.toString();
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
