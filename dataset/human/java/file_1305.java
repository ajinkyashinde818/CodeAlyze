import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] sum = new long[n];
        sum[0] = sc.nextLong();
        for(int i = 1; i < n; i++)
            sum[i] = sum[i-1] + sc.nextInt();
        long ans = Math.abs(2 * sum[0] - sum[n-1]);
        for(int i = 1; i < n-1; i++)
            ans = Math.min(ans, Math.abs(2 * sum[i] - sum[n-1]));
        System.out.println(ans);
    }
}
