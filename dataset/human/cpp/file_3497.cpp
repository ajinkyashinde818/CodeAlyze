#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1e5+15;
LL dp[maxn][2],a[maxn];
int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n; ++i) cin >> a[i];
    dp[2][1] = -a[1]-a[2];
    dp[2][0] = a[1]+a[2];
    for(int i = 3;i <= n; ++i){
        dp[i][1] = max(dp[i-1][1]+a[i-1]-(-a[i-1]+a[i]),dp[i-1][0]-a[i-1]-(a[i-1]+a[i]));
        dp[i][0] = max(dp[i-1][1]+a[i-1]+(-a[i-1]+a[i]),dp[i-1][0]-a[i-1]+(a[i-1]+a[i]));
        //cout << dp[i][1] << " " <<dp[i][0] << endl;
    }
    cout << max(dp[n][1],dp[n][0]) << '\n';
    return 0;
}
