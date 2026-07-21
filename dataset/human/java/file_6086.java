import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        comb();
        for(int i=2; i<=k*2; i++) {
            System.out.println(solve(k, n ,i));
        }
    }

    public static final long MOD = 998244353;

    public static long solve(int k, int n, int i) {
        long res = 0;
        i = Math.min(i, k * 2 + 2 - i);
        int s = 0;
        if(i%2 == 0 ) {
            s = 1;
        }
        int p = (i-1) / 2;
        int r = k - s - p * 2;
        if(s == 1) {
            res += s2(n, p, r);
            res += s2( n-1, p, r);
        } else {
            res += s2(n, p, r);
        }
        return res % MOD;
    }

    public static long s2(int n, int p, int r) {
        long res = 0;
        long mult = 1;
        for(int i=0; i<=p; i++) {
            if(i > n) break;
            int a = r + i;
            int b = n - i;
            long add = (comb[p][i] * comb[a + b - 1][b]) % MOD;
            res += (add * mult) % MOD;
            res %= MOD;
            mult *= 2;
            mult %= MOD;
        }
        return res % MOD;
    }

    static long[][] comb = new long[4001][4001];

    public static void comb() {
        comb[0][0] = 1;
        for(int i=1; i<=4000; i++) {
            for(int j=0; j<=i; j++) {
                if(j > 0) {
                    comb[i][j] += comb[i-1][j-1];
                }
                comb[i][j] += comb[i-1][j];
                comb[i][j] %= MOD;
            }
        }
    }
}
