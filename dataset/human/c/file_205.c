#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define inf 100100100
ll max(ll a,ll b){return a>b?a:b;}
int main(){
    int n;
    scanf("%d",&n);
    ll a[n];
    for (int i = 0; i < n; i++)
        scanf("%lld",&a[i]);
    ll dp[n + 1][3];
    dp[0][0] = 0;
    dp[0][1] = -inf;
    for(int i = 0; i < n; i++){
        dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
        dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
    }
    printf("%lld\n",dp[n][0]);
    return 0;
}
