import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] ar = new long[N];
        long[] dp = new long[N];
        for (int i = 0; i < N; i++) {
            ar[i] = sc.nextLong();
            if (i == 0) {
                dp[i] = ar[i];
            } else {
                dp[i] = dp[i-1]+ar[i];
            }
        }
        long sum = Arrays.stream(ar).sum();
        long min = Long.MAX_VALUE;
        for (int i = 0; i < N-1; i++) {
            long x = dp[i];
            long y = sum-x;
            min = Math.min(min, Math.abs(x-y));
        }
        System.out.println(min);
    }
    
}
