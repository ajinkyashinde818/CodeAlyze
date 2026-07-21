import java.util.*;
import java.io.*;

public class Main implements Runnable {
    int N;
    int M;
    // List<Integer> a = new ArrayList<Integer>();
    long[] a = new long[100001];
    long[] P = new long[100001];
    public static void main(String[] args) {
        // Thread.setDefaultUncaughtExceptionHandler((t,e)->System.exit(1));
        // keep stack
        new Thread(null, new Main(), "", 16 * 1024 * 1024).start();
    }
    public void run() {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        long mod = 1000000007;

        N = sc.nextInt();
        M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            // a.add(Integer.valueOf(sc.nextInt()));
            a[sc.nextInt()] = 1;
        }
        for (int i = 0; i <= N - 1; i++) {
            boolean result1 = false;
            boolean result2 = false;
            if (a[i + 1] == 0) {
                if (i == 0) {
                    P[i] += 1;
                } else {
                    P[i] += (P[i - 1] % mod);
                    
                }
                result1 = true;
            }
            if (i != (N - 1) && a[i + 2] == 0) {
                if (i == 0) {
                    P[i + 1] += 1;
                } else {
                    P[i + 1] += (P[i - 1] % mod);
                }
                result2 = true;
            }
            if (i == N - 1) {
                result2 = true;
            }
            // if (a.contains(i + 1) == false) {
            //     if (i == 0) {
            //         P[i] += 1;
            //     } else {
            //         P[i] += P[i-1];
            //     }
            //     result1 = true;
            // }
            // if (i != (N - 1) && a.contains(i + 2) == false) {
            //     if (i == 0) {
            //         P[i + 1] += 1;
            //     } else {
            //         P[i + 1] += P[i-1];
            //     }
            //     result2 = true;
            // }
            // if (result1 == false && result2 == false) {
            //     break;
            // }
        }

        out.printf("%d\n", (long)Math.abs(P[N - 1]) % mod);
        out.flush();
    }
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    private int readByte() {
        if (hasNextByte()) {
            return buffer[ptr++];
        }
        else {
            return -1;
        }
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
            ptr++;
        }
    }

    public boolean hasNext() {
        skipUnprintable();
        return hasNextByte();
    }

    public String next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public int nextInt() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        int n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public long nextLong() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}
