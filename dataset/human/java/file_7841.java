import java.util.*;

public class Main{
    
    public static final int MOD = (int)1e9+7;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        long k = Long.parseLong(sc.next());
        
        int[][] dp = new int[100][n];
        for(int i=0; i<n; i++){
            dp[0][i] = Integer.parseInt(sc.next())-1;
        }
        
        for(int i=0; i<64; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j] = dp[i][dp[i][j]];
            }
        }
        
        int ans = 0;
        for(int i=0; i<64; i++){
            if((k & (1L<<i)) > 0){
                ans = dp[i][ans];
            }
        }
        
        System.out.println(ans+1);
        
    }
}
