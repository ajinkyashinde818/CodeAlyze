import java.io.*;
import java.util.*;

class Main  {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] arr = br.readLine().toCharArray();
        int n = arr.length;
        long[] dp = new long[2];
        dp[1] =1;
        for(int i = n-1; i >= 0; --i){
            long[] newdp = new long[2];
            int dig = arr[i]-'0';
            newdp[0] = dp[0]+dig;
            newdp[1] = Math.min(dp[0]+(10-dig), dp[1]+(10-dig-1));
            if(dig < 9){
                newdp[0] = Math.min(newdp[0], dp[1]+dig+1);
            }
            dp = newdp;
        }
        System.out.println(Math.min(dp[0], dp[1]+1));
    }
}
