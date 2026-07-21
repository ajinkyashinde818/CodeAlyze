import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        String s = "0" + sc.next();
        char[] n = s.toCharArray();
        int len = n.length;
        
        int[][] dp = new int[len+1][2];
        for(int[] tmp : dp){
            Arrays.fill(tmp, (int)1e9);
        }
        dp[0][0] = 0;
        
        for(int i=0; i<len; i++){
            int t = Integer.parseInt(""+n[len-1-i]);
            dp[i+1][0] = Math.min(dp[i+1][0], dp[i][0]+t);
            dp[i+1][1] = Math.min(dp[i+1][1], dp[i][0]+(10-t));
            if(t+1<10){
                dp[i+1][0] = Math.min(dp[i+1][0], dp[i][1]+(t+1)%10);
            }
            dp[i+1][1] = Math.min(dp[i+1][1], dp[i][1]+(10-t-1));
        }
        
        System.out.println(Math.min(dp[len][0], dp[len][1]));
    }
}
