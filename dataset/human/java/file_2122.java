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

    long N;

    AtCoder(FastScanner sc) {
        N = sc.nextLong();
    }

    void solve(PrintWriter out) {
        if (N == 1L) {
            out.println("0");
            return;
        }
        if (isPrime(N)) {
            out.println("1");
            return;
        }
        List<Long> list = divisor(N);
        List<Long> del_list = new ArrayList<>();
        for (long e : list) {
            if (isPrime(e)) continue;
            if (!isPrimePower(e)) del_list.add(e);
        }
        list.removeAll(del_list);
        Collections.sort(list);
//        out.println(list);
//        out.println("del: " + del_list);
        int cnt = 0;
        for (long z : list) {
            if (N % z != 0) continue;
            N /= z;
            cnt++;
        }
        out.println(cnt);
    }

    List<Long> divisor(long n) {
        List<Long> list = new ArrayList<>();
        int sqrt = (int) Math.sqrt(n);
        for (long i = 1; i <= sqrt; i++) {
            if (n % i == 0) {
                list.add(i);
                if (i * i != n) {
                    list.add(n / i);
                }
            }
        }
        return list;
    }

    boolean isPrime(long x) {
        if (x == 2) {
            return true;
        } else if (x < 2 || x % 2 == 0) {
            return false;
        }
        long i = 3;
        while (i <= Math.sqrt(x)) {
            if (x % i == 0) {
                return false;
            }
            i += 2;
        }
        return true;
    }

    boolean isPrimePower(long x) {
        for (int i = 2; i <= Math.sqrt(x); i++) {
            if (x % i != 0) continue;
            long ex = 0;
            long tmp = x;
            while (tmp % i == 0) {
                ++ex;
                tmp /= i;
            }
//            System.out.println(x + " " + i + " " + ex);
            if (isPrime(i) && x == Math.pow(i, ex)) return true;
        }
        return false;
    }

}

// https://qiita.com/p_shiki37/items/a0f6aac33bf60f5f65e4
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
