import java.util.PriorityQueue;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.HashSet;
import java.util.ArrayDeque;
import java.io.FileNotFoundException;
import java.util.Set;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.Queue;

public class Main {
    InputStream is;

    int __t__ = 1;
    int __f__ = 0;
    int __FILE_DEBUG_FLAG__ = __f__;
    static String __DEBUG_FILE_NAME__ = "src/main/java/test/sample-4.in";

    FastScanner in;
    PrintWriter out;

    class State {
        final int v;
        final int ac;
        final int bc;

        public State(int v, int ac, int bc) {
            this.v = v;
            this.ac = ac;
            this.bc = bc;
        }

        int calc() {
            return ac - bc;
        }
    }

    public void solve() {
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);
        int[] b = in.nextIntArray(n);

        PriorityQueue<State> pq = new PriorityQueue<>((s1, s2) -> {
            if (s1.calc() == s2.calc()) {
                return s2.ac - s1.ac;
            } else {
                return s1.calc() - s2.calc();
            }
        });

        Queue<State> trash = new ArrayDeque<>();
        HashSet<Integer> as = new HashSet<>();
        for (int i = 0; i < n; i++) {
            as.add(a[i]);
        }
        int MAX = 200000;
        int[] ac = new int[n+1];
        int[] bc = new int[n+1];
        for (int i = 0; i < n; i++) {
            ac[a[i]]++;
            bc[b[i]]++;
        }
        for (int i = 0; i <= n; i++) {
            if (bc[i] != 0) {
                State st = new State(i, ac[i], bc[i]);
                if (st.ac == 0) {
                    trash.add(st);
                } else {
                    pq.add(st);
                }
            }
        }

        int cur = 0;
        int[] res = new int[n];
        Set<Integer> used = new HashSet<>();
        while (!pq.isEmpty()) {
            used.add(a[cur]);
            State s1 = pq.poll();
            if (used.contains(s1.v)) {
                trash.add(s1);
                continue;
            }
            res[cur++] = s1.v;
            if (s1.bc > 1) {
                pq.add(new State(s1.v, s1.ac, s1.bc - 1));
            }
        }
        Set<Integer> s2 = new HashSet<>();
        while (!trash.isEmpty()) {
            State s = trash.poll();
            if (a[cur] == s.v && !s2.contains(s.v)) {
                s2.add(s.v);
                trash.add(s);
                continue;
            }
            for (int i = 0; i < s.bc; i++) {
                if (a[cur] == s.v) {
                    System.out.println("No");
                    return;
                }
                res[cur++] = s.v;
            }
        }
        System.out.println("Yes");
        for (int i = 0; i < n; i++) {
            System.out.print(res[i] + " ");
        }
        System.out.println("");
    }

    public void run() {
        if (__FILE_DEBUG_FLAG__ == __t__) {
            try {
                is = new FileInputStream(__DEBUG_FILE_NAME__);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            System.out.println("FILE_INPUT!");
        } else {
            is = System.in;
        }
        in = new FastScanner(is);
        out = new PrintWriter(System.out);

        solve();
    }

    public static void main(final String[] args) {
        new Main().run();
    }
}


class FastScanner {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public FastScanner(InputStream stream) {
        this.stream = stream;
        // stream = new FileInputStream(new File("dec.in"));
    }

    int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public boolean isEndline(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public int[] nextIntArray(int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++)
            array[i] = nextInt();

        return array;
    }

    public int[][] nextIntMap(int n, int m) {
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            map[i] = nextIntArray(m);
        }
        return map;
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public long[] nextLongArray(int n) {
        long[] array = new long[n];
        for (int i = 0; i < n; i++)
            array[i] = nextLong();

        return array;
    }

    public long[][] nextLongMap(int n, int m) {
        long[][] map = new long[n][m];
        for (int i = 0; i < n; i++) {
            map[i] = nextLongArray(m);
        }
        return map;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public double[] nextDoubleArray(int n) {
        double[] array = new double[n];
        for (int i = 0; i < n; i++)
            array[i] = nextDouble();

        return array;
    }

    public double[][] nextDoubleMap(int n, int m) {
        double[][] map = new double[n][m];
        for (int i = 0; i < n; i++) {
            map[i] = nextDoubleArray(m);
        }
        return map;
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public String[] nextStringArray(int n) {
        String[] array = new String[n];
        for (int i = 0; i < n; i++)
            array[i] = next();

        return array;
    }

    public String nextLine() {
        int c = read();
        while (isEndline(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isEndline(c));
        return res.toString();
    }

    public int[][] nextPackedIntArrays(int packN, int size) {
        int[][] res = new int[packN][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < packN; j++) {
                res[j][i] = nextInt();
            }
        }
        return res;
    }
}
