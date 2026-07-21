import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Scanner sc = new Scanner(System.in);
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    long mod = 1000000000+7;
    int cnt2 = 0;
    long[] frac, inv;
    public static void main(String[] args) throws IOException {
        Main main = new Main();
//        main.solve();
        out.println(main.solve());
        out.flush();
    }
    long solve() throws IOException {
        int n = sc.nextInt();
        long[] x = new long[n];
        for(int i=0;i<n;i++) x[i] = sc.nextLong();
        long[] d = new long[n];
        for(int i=1;i<n;i++){
            d[i] = x[i]-x[i-1];
        }
        frac = new long[n+1];
        frac[0] = 1;
        for(int i = 1; i<=n;i++) frac[i] = frac[i-1]*i%mod;
        inv = new long[n+1];
        inv[0] = 1; inv[1] = 1;
        for(int i=2;i<=n;i++){
            inv[i] = power(i,mod-2);
        }
        long sum = 0, base = frac[n-1], ans = 0;
        for(int i=1;i<n;i++){
            sum += base*inv[i]%mod;
            sum %= mod;
            ans = (ans+sum*d[i])%mod;
        }
        return ans;
    }
    long power(long base, long p){
        long ans = 1;
        while(p>0){
            if(p%2==1) ans = ans*base%mod;
            base = base*base%mod;
            p /= 2;
        }
        return ans;
    }
}
