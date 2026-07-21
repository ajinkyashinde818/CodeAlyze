import java.util.*;

class Main{

    void solve(){
        Scanner sc = new Scanner(System.in);

        int max = 1150;
        boolean[] boo = new boolean[max];
        for(int i=2; i<max; i++) boo[i] = true;
        for(int i=2; i<Math.sqrt(max); i++){
            for(int j=i*i; j<max; j+=i) boo[j] = false;
        }

        int[][] dp = new int[max][16];
        dp[0][0] = 1;
        for(int i=1; i<max; i++){
            if(!boo[i]) continue;
            for(int j=max-1-i; j>=0; j--){
                for(int k=15; k>=1; k--){
                    dp[j+i][k] += dp[j][k-1];
                }
            }
        }

        while(true){
            int n = sc.nextInt(), k = sc.nextInt();
            if(n==0 && k==0) break;

            System.out.println(dp[n][k]);
        }
    }

    public static void main(String[] args){
        new Main().solve();
    }
}
