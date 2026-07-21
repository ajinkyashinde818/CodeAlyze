import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;
 
    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);
 
    private void solve(Scanner sc) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();
        String[] A = new String[N];
        String[] B = new String[M];
        for (int i = 0; i < N; ++i) {
            A[i] = sc.nextLine();
        }
        for (int i = 0; i < M; ++i) {
            B[i] = sc.nextLine();
        }
 
        for (int i = 0; i < N - M + 1; ++i) {
            for (int j = 0; j < N - M + 1; ++j) {
                boolean ok = true;
                for (int k = 0; k < M; ++k) {
                    if (A[i + k].indexOf(B[k], j) != j) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    _out.println("Yes");
                    return;
                }
            }
        }
        _out.println("No");
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();
 
        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();
 
        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}
