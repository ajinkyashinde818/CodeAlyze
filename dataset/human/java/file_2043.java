import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class Main {
    long N;

    private Map<Long, Integer> primeFactors(long n) {
        Map<Long, Integer> primeFactors = new HashMap<>();
        long tmp = n;
        for(long i = 2;i * i <= n && i <= tmp;i++) {
            int cnt = 0;
            while(tmp % i == 0) {
                tmp /= i;
                cnt++;
            }
            if (cnt > 0) {
                primeFactors.put(i, cnt);
            }
        }
        if (tmp > 1) {
            primeFactors.put(tmp, 1);
        }
        return primeFactors;
    }

    private void solve() {
        N = nextLong();
        Map<Long, Integer> map = primeFactors(N);
        int ans = 0;
        for(int i : map.values()) {
            int j = 1;
            while(j <= i) {
                ans++;
                i -= j;
                j++;
            }
        }
        out.println(ans);
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

    public int[] nextIntArray(int n) {
        int[] x = new int[n];
        for(int i = 0;i < n;i++) {
            x[i] = nextInt();
        }
        return x;
    }

    public long[] nextLongArray(int n) {
        long[] x = new long[n];
        for(int i = 0;i < n;i++) {
            x[i] = nextLong();
        }
        return x;
    }

    public double[] nextDoubleArray(int n) {
        double[] x = new double[n];
        for(int i = 0;i < n;i++) {
            x[i] = nextDouble();
        }
        return x;
    }
}
