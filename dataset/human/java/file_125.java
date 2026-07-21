import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static long[][] selfCon, selfUncon;
    static long mod = 1000000000+7;
    static int n;
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n+1];
        for(int i=1;i<=n;i++) a[i]=sc.nextLong();
        long[] mid = new long[n+1], dp = new long[n+1];
        dp[1] = a[1];dp[2] = Math.max(a[1]+a[2],-a[1]-a[2]);
        mid[2] = Math.max(-a[2]+a[1],-a[1]+a[2]);
        for(int i=3;i<=n;i++){
            dp[i] = Math.max(a[i]+dp[i-1],-a[i]+mid[i-1]);
            mid[i] = Math.max(-a[i]+dp[i-1],a[i]+mid[i-1]);
        }
        long ans = dp[n];
        System.out.println(ans);
    }
}
