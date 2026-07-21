import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner     sc = new Scanner(System.in);
    static final PrintStream so = System.out;
    static int MOD = (int)1E9 + 7;
    public static void main(String[] args) {
        int n = ni();
        long[] s = new long[n+1];
        s[0] = 1;
        s[1] = 1;
        for (int i = 2; i <= n; i++) {
            s[i] = s[i-1] + s[i-2];
            s[i] %= MOD;
        }
        
        int m = ni();
        if (m == 0) {
            so.println(s[n]);
            return;
        }
        
        int[] a = new int[m + 2];
        for (int i = 1; i <= m; i++) {
            a[i] = ni();
        }
        a[m+1] = n+1;
        long ans = s[a[1]-1];
        
        for (int i = 2; i <= m+1; i++) {
            int diff = a[i] - a[i-1] - 2;
            if (diff < 0) {
                so.println(0);
                return;
            }
            
            ans *= s[diff];
            ans %= MOD;
        }
        so.println(ans);
    }
    
    
    static int gcd(int m, int n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }
    
    static long lcm(int m, int n) {
        return (long) m * n / gcd(m, n);
    }

    private static long nl() {
        return sc.nextLong();
    }

    private static int ni() {
        return sc.nextInt();
    }

    private static String ns() {
        return sc.next();
    }

    private static char[] nsToChars() {
        return sc.next().toCharArray();
    }

    private static long[] nlongs(int n) {
        return nlongs(n, 0);
    }
    private static int[] nints(int n) {
        return nints(n, 0);
    }

    private static long[] nlongs(int n, int offset) {
        long[] a = new long[offset + n];
        for (int i = 0; i < n; i++)
            a[offset + i] = nl();
        return a;
    }

    private static int[] nints(int n, int offset) {
        int[] a = new int[offset + n];
        for (int i = 0; i < n; i++)
            a[offset + i] = ni();
        return a;
    }
}
