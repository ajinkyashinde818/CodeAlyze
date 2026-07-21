#include<stdio.h>
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    scanf(" %d%d",&n,&m);
    int broken[100002];
    rep(i,m){
        int a;
        scanf("%d",&a);
        broken[a]=1;
    }
    long long int dp[100002];
    const long long int mod = 1000000007;
    dp[n] = 1;
    for(int i= n-1;i>=0;i--){
        if(broken[i]){
            dp[i]=0;
            continue;
        }
        dp[i] = (dp[i+1] + dp[i+2]) % mod;
    }
    printf("%d\n",dp[0]);
    return 0;
}
