import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        new Main().run(k, n);
    }

    final long MOD = 998244353;

    long[] fac = new long[4001];
    long[] ifac = new long[4001];
    long[] inv = new long[4001];
    long[] pow2 = new long[4001];
    {
        fac[0] = fac[1] = ifac[0] = ifac[1] = inv[0] = inv[1] = pow2[0] = 1;
        for(int i = 2;i < fac.length; ++i){
            fac[i] = fac[i-1] * i % MOD;
        }
        for(int i = 2;i < inv.length;++i){
            inv[i] = MOD - inv[(int)MOD % i] * (MOD / i)%MOD;
        }
        for(int i = 2;i < ifac.length;++i){
            ifac[i] = ifac[i-1] * inv[i] % MOD;
        }
        for(int i = 1;i < pow2.length; ++i){
            pow2[i] = 2 * pow2[i - 1] % MOD;
        }
    }

    long solve(int K, int N, int t, boolean f){
        if(t % 2 == 0 && !f) return (solve(K, N - 1, t, true) + solve(K, N, t, true)) % MOD;
        long ret = 0;
        int p = 0;
        for(int i = 1;i < t && i < t - i; ++i) if(t - i <= K) ++p;
        for(int q = 0;q <= p; ++q){
            ret += comb(p ,q) * pow2[q] % MOD * comb(N - q + K - 2 * p - (f? 1 : 0 ) + q - 1, N - q) % MOD;
            ret %= MOD;
        }
        return ret;
    }


    void run(int K, int N){
        for(int t = 2;t <= 2 * K; ++t){
            System.out.println(solve(K, N, t, false));
        }
    }


    long comb(int n,int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
    }

    void tr(Object...objects){
        System.out.println(Arrays.deepToString(objects));
    }
}
