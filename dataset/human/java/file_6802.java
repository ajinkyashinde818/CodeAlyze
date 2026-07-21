import  java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int k = cin.nextInt();
        int n = cin.nextInt();
        int[] a = new int[n+1];
        int[] d = new int[n+1];
        a[1] = cin.nextInt();
        for(int i = 2; i <= n; i++){
        	a[i] = cin.nextInt();
        	d[i-1] = a[i]-a[i-1];
        }
        d[n] = k-a[n]+a[1];
        int ans = 0, maxn = 0;
        for(int i = 1; i <= n; i++){
        	if(maxn < d[i]) maxn = d[i];
        	ans += d[i];
        }
        ans = ans - maxn;
        System.out.println(ans);
    }
}
