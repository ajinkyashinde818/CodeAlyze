import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.TreeMap;
import java.util.*;

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
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr]))
            ptr++;
        return hasNextByte();
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext())
            throw new NoSuchElementException();
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
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}

public class Main {
    static int[] w = new int[100010];
    static int[] v = new int[100010];
    static int[][] dp = new int[110][100010];
    static int k;

    static int chmin(int a, int b) {
        if (a > b) {
            a = b;
            return a;
        }
        return a;
    }

    static int chmax(int a, int b) {
        if (a < b) {
            a = b;
            return a;
        }
        return a;
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        TreeMap<String, Integer> map1 = new TreeMap<>();
        TreeMap<String, Integer> map2 = new TreeMap<>();
        String s = fs.next();
        String t = fs.next();

        for (int i = 0; i < s.length(); i++) {
            if (map1.containsKey(s.substring(i, i + 1)))
                map1.put(s.substring(i, i + 1), map1.get(s.substring(i, i + 1)) + 1);
            else
                map1.put(s.substring(i, i + 1), 1);
        }
        for (int i = 0; i < t.length(); i++) {
            if (map2.containsKey(t.substring(i, i + 1)))
                map2.put(t.substring(i, i + 1), map2.get(t.substring(i, i + 1)) + 1);
            else
                map2.put(t.substring(i, i + 1), 1);
        }

        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        List<String> tl = new ArrayList<>();
        for (String sk : map1.keySet()) {
            if (map1.get(sk) == 0)
                sb1.append(sk);
            else {
                for (int i = 0; i < map1.get(sk); i++) {
                    sb1.append(sk);
                }
            }
        }
        for (String tk : map2.keySet()) {
            if (map2.get(tk) == 0)
                tl.add(tk);
            else {
                for (int i = 0; i < map2.get(tk); i++) {
                    tl.add(tk);
                }
            }
        }
        for (int i = tl.size() - 1; i >= 0; i--) {
            sb2.append(tl.get(i));
        }
        String ans1 = sb1.toString();
        String ans2 = sb2.toString();

        if (ans1.compareTo(ans2) < 0)
            System.out.println("Yes");
        else
            System.out.println("No");

    }

}
