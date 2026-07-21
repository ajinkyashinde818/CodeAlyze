import java.io.PrintWriter;
import java.util.*;

import static java.lang.System.in;

public class Main {
    static int K,N;
    static final long mod = 998244353;
    static long[] pw2 = new long[4005], fac = new long[4005], inv = new long[4005];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        N = sc.nextInt();
        init();
        PrintWriter out = new PrintWriter(System.out);
        // the main for loop
        for(int i=2;i<=2*K;i++){
            long ans;
            if(i%2==1){
                ans = get(N,K,i);
            }else{
                ans = (get(N,K-1,i-1)+get(N-1,K-1,i-1))%mod;
            }
            out.println(ans);
        }
        out.flush();
    }
    // n blanks to fill number in. totally k values can be chosen.
    // why define in this way? because when i is even it's a little tricky
    // i is the sum that we want to avoid. In the main func we will make sure that i is odd
    static long get(int n, int k, int i){
        int lim = Math.max(0,i/2-Math.max(0,i-1-k));
        long ans = 0;
        for(int q=0;q<=lim;q++){
            ans = (ans+pw2[q]*comb(lim,q)%mod*hcom(k+q-2*lim,n-q))%mod;
        }
        return ans;
    }
    static long hcom(int P, int Q){
        return comb(P+Q-1,P-1);
    }
    static long comb(int n, int m){
        if(m>n||m<0||n<0) return 0;
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
    static void init(){
        pw2[0] = 1;
        for(int i=1;i<4005;i++) pw2[i] = 2*pw2[i-1]%mod;
        fac[0] = 1;
        for(int i=1;i<4005;i++) fac[i] = i*fac[i-1]%mod;
        inv[0] = 1;
        inv[4004] = pow(fac[4004],mod-2);
        for(int i=4003;i>=1;i--) inv[i] = (i+1)*inv[i+1]%mod;
    }
    static long pow(long base, long p){
        long ans = 1;
        while(p>0){
            if(p%2==1) ans = ans*base%mod;
            base = base*base%mod;
            p /= 2;
        }
        return ans;
    }
}
