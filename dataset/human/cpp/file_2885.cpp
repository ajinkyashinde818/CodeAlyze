#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll dp[MN][2], n, i, arr[MN];

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    dp[n-1][0]=max(arr[n-1]+arr[n],-arr[n-1]-arr[n]);
    dp[n-1][1]=max(-arr[n-1]+arr[n],arr[n-1]-arr[n]);
    for(i=n-2;i>=1;i--){
        dp[i][0]=max(arr[i]+dp[i+1][0],-arr[i]+dp[i+1][1]);
        dp[i][1]=max(-arr[i]+dp[i+1][0],arr[i]+dp[i+1][1]);
    }
    printf("%lld\n",dp[1][0]);
    return 0;
}
