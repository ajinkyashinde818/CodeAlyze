import java.util.*;
import java.io.*;
 
public class Main{
    public static void main(String[] args){
        new Main().solve();
    }
 
    void solve(){
 
        Scanner cin = new Scanner(System.in);
        int MAXA = 1200;
        int MAXB = 20;
        int[][] dp = new int[MAXA][MAXB];
        dp[0][0] = 1;
        for(int i=2;i<=MAXA;i++){
            if(isPrime(i)){
                for(int j=MAXA- i - 1;j>= 0;j--){
                	for(int k=MAXB-2;k>=0;k--){
                		dp[j+i][k+1] += dp[j][k];
                	}
                }
            }
        }
        while(true)
        {
            int n = cin.nextInt();
            int k = cin.nextInt();
            if(n==0) return;
            System.out.println(dp[n][k]);
        }
    }
 
    boolean isPrime(int a){
        if(a<2) return false;
        for(int i=2;i*i<=a;i++){
            if(a%i==0) return false;
        }
        return true;
    }
}
