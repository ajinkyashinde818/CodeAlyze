import java.util.*;

public class Main{

    int max = 1121;
    boolean[] notp;

    void solve(){
        Scanner sc = new Scanner(System.in);

        notp = new boolean[max];
        for(int i=2; i<Math.sqrt(max)+1; i++){
            for(int j=i*2; j<max; j+=i) notp[j] = true;
        }

        int[][] dp = new int[max][15];
        dp[0][0] = 1;
        for(int i=2; i<max; i++){
            if(notp[i]) continue;
            for(int j=max; j>=0; j--){
                if(i+j>=max) continue;
                for(int k=1; k<15; k++){
                    dp[j+i][k] += dp[j][k-1];
                }
            }
        }

        while(true){
            int n = sc.nextInt();
            int k = sc.nextInt();
            if(n==0 && k==0) break;
            System.out.println(dp[n][k]);
        }
    }

    public static void main(String[] args){
        new Main().solve();
    }
}
