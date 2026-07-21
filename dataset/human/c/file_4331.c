#include <stdio.h>
#define mod 1000000007

int main(){
    long long int dp[100100] = {0},b[100100]={0};
    long long int n,m,i;
    long long int x;

    scanf("%lld %lld",&n,&m);
    for(i = 0 ; i < m ; i++){
        scanf("%lld",&x);
        b[x] = -1;
    }
    
    dp[0] = 1;
    for(i = 1; i <= n ; i++){
       // printf("%d",i);
        
        if(b[i] == -1){
            dp[i] = 0;
        }else{
            if(i == 1){
                dp[i] = 1;
            }else{
             dp[i] = (dp[i-1] + dp[i-2])%mod;
            }
        }
          
        
    }
    printf("%lld\n",dp[n]);

    return 0;
}
