#include<stdio.h>
#define mod 1000000007;
typedef long long int ll;

int main(void){
    int n,m;
    scanf("%d%d", &n,&m);
    ll check[n+1];
    for(int i=0; i<n; i++){check[i] = 0;}
    for(int i=0; i<m; i++){
        int a;
        scanf("%d", &a);
        check[a] += 1;
    }

    ll dp[n+1];
    for(int i=0; i<n+1; i++){dp[i] = 0;}

    dp[0] = 1;
    if(check[1] == 1){
        dp[1] = 0;
    }else{
        dp[1] = 1;
    }

    for(int i=2; i<n+1; i++){
        if(check[i] == 1){
            dp[i] = 0;
        }else{
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
    }

    printf("%lld\n", dp[n]);

    return 0;
}
