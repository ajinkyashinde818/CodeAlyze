import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final Scanner sc    = new Scanner(System.in);
    static final int     MOD   = (int) 1E9 + 7;
    static final long    INF_L = (long) 4E18;
    static final int     INF   = Integer.MAX_VALUE;
    
    public static void main(String[] args) {
        final int S_MAX = (int) 1e9;
        int N = nint();
        int K = nint();
        int S = nint();
        
        int[] ans = new int[N];
        if (S == S_MAX) {
            Arrays.fill(ans, 1);
            for (int i = 0; i < K; i++) {
                ans[i] = S;
            }
        } else {
            Arrays.fill(ans, S_MAX);
            for (int i = 0; i < K; i++) {
                ans[i] = S;
            }
        }
        PrintWriter out = new PrintWriter(System.out);
        for (int i: ans) {
            out.print(i);
            out.print(" ");
        }
        out.flush();
    }
    static class Point {
        long left;
        long right;
        public Point(long left, long right) {
            super();
            this.left = left;
            this.right = right;
        }
        @Override
        public String toString() {
            return "(" + left + ", " + right + ")";
        }
        long getLeft() {return left;}
    }
    
    @Deprecated
    static int nint() {
        return sc.nextInt();
    }

    @Deprecated
    static int[] nints(int N) {
        return nints(N, 0, 0);
    }

    @Deprecated
    private static int[] nints(int N, int padL, int padR) {
        int[] a = new int[padL + N + padR];
        for (int i = 0; i < N; i++)
            a[padL + i] = nint();
        return a;
    }

    static long nlong() {
        return sc.nextLong();
    }

    static long[] nlongs(int N) {
        return nlongs(N, 0, 0);
    }

    static long[] nlongs(int N, int padL, int padR) {
        long[] a = new long[padL + N + padR];
        for (int i = 0; i < N; i++)
            a[padL + i] = nlong();
        return a;
    }

    static double ndouble() {
        return sc.nextDouble();
    }

    static double[] ndoubles(int N) {
        return ndoubles(N, 0, 0);
    }

    static double[] ndoubles(int N, int padL, int padR) {
        double[] d = new double[N + padL + padR];
        for (int i = 0; i < N; i++) {
            d[padL + i] = ndouble();
        }
        return d;
    }

    static String nstr() {
        return sc.next();
    }

    static char[] nchars() {
        return sc.next().toCharArray();
    }

    static char[] nchars(int padL, int padR) {
        char[] temp = sc.next().toCharArray();
        char[] ret = new char[temp.length + padL + padR];
        System.arraycopy(temp, 0, ret, padL, temp.length);
        return ret;
    }

    static char[][] nchars2(int H, int W) {
        return nchars2(H, W, 0, 0);
    }

    static char[][] nchars2(int H, int W, int padLU, int padRD) {
        char[][] a2 = new char[H + padLU + padRD][W + padLU + padRD];
        for (int i = 0; i < H; i++)
            System.arraycopy(nchars(), 0, a2[padLU + i], padLU, W);
        return a2;
    }

    static long min(long... ls) {
        return Arrays.stream(ls).min().getAsLong();
    }

    static long max(long... ls) {
        return Arrays.stream(ls).max().getAsLong();
    }

    static long abs(long a) {
        return Math.abs(a);
    }
}
