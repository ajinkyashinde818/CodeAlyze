import java.util.Scanner;

public class Main {
    static final Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        String in = nstr();
        
        char[] a = in.toCharArray();
        int ans = 0;
        int l = 0;
        int r = in.length()-1;
        while (r >= l) {
            if (a[r] == a[l]) {
                r--;
                l++;
            } else {
                if (a[r] == 'x') {
                    ans++;
                    r--;
                } else if (a[l] == 'x') {
                    ans++;
                    l++;
                } else {
                    System.out.println(-1);
                    return;
                }
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

    private static String[] nstrs(int n) {
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = nstr();
        }
        return a;
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
