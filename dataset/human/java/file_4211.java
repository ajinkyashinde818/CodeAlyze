import java.util.Scanner;

public class Main {
    static final Scanner sc = new Scanner(System.in);
    static final int MOD = (int) 1E9 + 7;
    
    public static void main(String[] args) {
        int N = nint();
        int[] A = nints(N, 1, 0);
        int[] B = nints(N, 1, 0);
        int[] C = nints(N-1, 1, 0);
        int ans = 0;
        
        for (int i = 1; i <= N; i++) {
            ans += B[A[i]];
            if (i > 1 && A[i] == A[i-1] + 1) {
                ans += C[A[i-1]];
            }
        }
        System.out.println(ans);
    }

    private static long nlong() {
        return sc.nextLong();
    }

    private static int nint() {
        return sc.nextInt();
    }

    private static String nstr() {
        return sc.next();
    }

    private static char[] nchars() {
        return sc.next().toCharArray();
    }

    private static int[] nints(int n) {
        return nints(n, 0, 0);
    }

    private static int[] nints(int n, int padL, int padR) {
        int[] a = new int[padL + n + padR];
        for (int i = 0; i < n; i++)
            a[padL + i] = nint();
        return a;
    }

    private static char[][] nchars2(int h, int w) {
        return nchars2(h, w, 0);
    }

    private static char[][] nchars2(int h, int w, int pad) {
        char[][] a2 = new char[h + pad * 2][w + pad * 2];
        for (int i = 0; i < h; i++)
            System.arraycopy(nchars(), 0, a2[pad + i], pad, w);
        return a2;
    }
}
