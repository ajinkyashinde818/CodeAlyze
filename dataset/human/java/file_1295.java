import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int i=0;i<N;i++) a[i] = sc.nextInt();
        long[] sum = new long[N+1];
        for(int i=1;i<=N;i++) sum[i]=sum[i-1]+a[i-1];
        long ans = Long.MAX_VALUE;
        for(int i=1;i<N;i++){
            long cur = sum[i]-(sum[N]-sum[i]);
            ans = Math.min(ans,Math.abs(cur));
        }
        System.out.println(ans);
    }
}
