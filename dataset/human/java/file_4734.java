import java.util.*;
import java.util.Map.Entry;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int N = S.length();
        int[] digit = new int[N];
        long sum = 0L;
        for (int i=0;i<N;i++) {
            digit[i] = (int)S.charAt(i)-48;
            sum += digit[i];
        }

        long up = 1+(10-digit[N-1]);
        long down = digit[N-1];

        long[][] dp = new long[N][2]; // dp[i][0]->up, dp[i][1]->down
        dp[N-1][0] = up;
        dp[N-1][1] = down;

        for (int i=N-1;i>0;i--) {
            dp[i-1][0] = Math.min(dp[i][1]+(10-digit[i-1])+1, dp[i][0]+(9-digit[i-1]));
            dp[i-1][1] = Math.min(dp[i][1]+digit[i-1], dp[i][0]+digit[i-1]);
        }
        System.out.println(Math.min(dp[0][0], dp[0][1]));
        // System.out.println(Arrays.toString(digit));

        // long ans = sum;
        // long give = sum;
        // long take = 0;
        // boolean flag = false;
        // for (int i=N-1;i>=0;i--) {
        //     give -= digit[i];
        //     if (flag==false && digit[i]!=0) {
        //         flag=true;
        //         give++;
        //         take++;
        //     }
        //     if (flag) {
        //         take += 9-digit[i];
        //     }
        //     ans = Math.min(ans, give+take);
        //     System.out.println("give, take: "+give+" "+take);
        // }
        // System.out.println(ans);
    }
}
