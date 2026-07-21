import java.util.*;

class Main{
    public static void main(String[] args){
        long mod=1_000_000_007l;
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[] x=new long[n+1];
        for(int i=1;i<=n;x[i++]=sc.nextLong());
        sc.close();
        long ans=0;
        for(int i=1;i<n;i++){
            ans+=((x[n]-x[i])*modinv(i, mod))%mod;
        }
        ans%=mod;
        for(int i=2;i<n;ans=(ans*i++)%mod);
        System.out.println(ans);
    }
    static long modinv(long a, long mod) {
        long b = mod;
        long u = 1, v = 0;
        while (b >= 1) {
            long t = a / b;
            a -= t * b;
            long tmp1 = a;
            a = b;
            b = tmp1;
            u -= t * v;
            long tmp2 = u;
            u = v;
            v = tmp2;
        }
        u %= mod;
        return u >= 0 ? u : u + mod;
    }
}
