#include<stdio.h>
#include<stdlib.h>
#pragma GCC optimize("Ofast")
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[m];
    for(int i = 0;i < m;i++){
        scanf("%d",&a[i]);
    }
    int dp[n + 1];
    for(int i = 0;i < (n + 1);i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    int j = 0;
    for(int i = 1;i < (n + 1);i++){
        
        if(i == 1){
            dp[i] = 1;
            }else{
            dp[i] += dp[i - 1];
            dp[i] += dp[i - 2];
            }
        if(dp[i] > 1000000007){
            dp[i] %= 1000000007;
        }    


        for(int rj = j;rj < m;rj++){
            if(i == a[rj]){
                dp[i] = 0;
                ++j;
                break;
            }
        }
    }
    printf("%d",dp[n]);
    return 0;
}
