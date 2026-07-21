import java.text.DecimalFormat;
import java.util.stream.LongStream;
import java.util.stream.IntStream;
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        AtCoder problem = new AtCoder(sc);
        problem.solve(out);

        out.flush();
    }

}

class AtCoder {

    final int N, M, X;
    int[] price;
    int[][] books;
    int[] skills;

    AtCoder(FastScanner sc) {
        N = sc.nextInt();
        M = sc.nextInt();
        X = sc.nextInt();
        price = new int[N];
        books = new int[N][M];
        for (int i = 0; i < N; i++) {
            price[i] = sc.nextInt();
            for (int j = 0; j < M; j++) {
                books[i][j] = sc.nextInt();
            }
        }
        skills = new int[M];
    }

    void solve(PrintWriter out) {
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < Math.pow(2, N); i++) {
            BitSet bitset = BitSet.valueOf(new long[]{i});
            Arrays.fill(skills, 0);
            long total_price = 0;
            for (int index = 0; index < N; index++) {
                if (bitset.get(index)) {
                    skillUp(index);
                    total_price += price[index];
                }
            }
            if (checkSkills()) ans = Math.min(total_price, ans);
        }
        out.println(ans == Long.MAX_VALUE ? "-1" : ans);
    }

    void skillUp(int index) {
        for (int i = 0; i < M; i++) {
            skills[i] += books[index][i];
        }
    }

    boolean checkSkills() {
        for (int i = 0; i < M; i++) {
            if (skills[i] < X) return false;
        }
        return true;
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
        } else {
            return -1;
        }
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
            ptr++;
        }
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

    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
            throw new NumberFormatException();
        }
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}
