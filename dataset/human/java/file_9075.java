import java.util.Scanner;

/**
 * @author yoshizaki
 * abc 129
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);
        int step = scanner.nextInt();
        int ng = scanner.nextInt();
        long [] dp = new long[step];
        for(int i = 0; i < step; i++) dp[i] = 0;
        if (ng > 0) {
            int [] breaks = new int[step];
            for(int i = 0; i < ng ; i++) breaks[i] = scanner.nextInt();
            for(int i = 0; i < ng; i++) dp[breaks[i]-1] = -100000000000000000l;
        }
        
        if(step > 1) {
            if (dp[0] == 0 && dp[1] == 0) {
                dp[0] = 1;
                dp[1] = 2;
            } else if (dp[0] == 0) {
                dp[0] = 1;
            } else if (dp[1] == 0) {
                dp[1] = 1;
            }
            for(int i = 2; i < step; i++) {
                if (dp[i] < 0) continue;
                if (dp[i-1] > 0) dp[i] += dp[i-1];
                if (dp[i-2] > 0) dp[i] += dp[i-2];
                dp[i] %= 1000000007;
            }
        } else {
            dp[step - 1] = 1;
        }
        System.out.println(dp[step-1]);
    }
}
