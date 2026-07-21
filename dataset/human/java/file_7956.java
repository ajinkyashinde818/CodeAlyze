import java.util.*;
import java.awt.geom.*;
import java.io.*;
public class Main{
    int [][] dp;
    int MAX = 1120;
    int K= 14;
    boolean [] isprime;
     
    private void doit(){
        Scanner sc = new Scanner(System.in);
         
        isprime = new boolean[MAX + 1];
        eratos();
         
        dp = new int[K + 1][MAX + 1];
        dp();
        while(true){
            int n = sc.nextInt();
            int k = sc.nextInt();
            if((n|k) == 0) break;
            System.out.println(dp[k][n]);
        }
    }
 
    private void dp() {
        for(int i = 1; i <= MAX; i++){
            dp[1][i] = isprime[i] ? 1 : 0;
        }
         
        for(int i = MAX; i >= 2; i--){
            if(! isprime[i]) continue;
            for(int j = MAX; j >= i; j--){
                for(int k = K - 1; k  >= 1; k--){
                    if(k == 1 && j == i) continue;
                    if(j + i > MAX) continue;
                    dp[k+1][j + i] += dp[k][j];
                }
            }
        }
    }
 
    private void eratos() {
        Arrays.fill(isprime, true);
        isprime[0] = false;
        isprime[1] = false;
        for(int i = 2; i * i <= MAX; i++){
            if(isprime[i]){
                for(int j = i * 2; j <= MAX; j+= i){
                    isprime[j] = false;
                }
            }
        }
         
    }
 
    public static void main(String [] args){
        new Main().doit();
    }
}
