#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<long long> > dp(n, vector<long long>(2, -1e18));
    vector<long long> a(n,0);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    dp[1][0] = a[0] + a[1];
    dp[1][1] = - a[0] - a[1];
    for(int i = 2; i < n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = max(dp[i - 1][0] - 2 * a[i - 1] - a[i], dp[i - 1][1] + 2 * a[i - 1] - a[i]   );
    }
    cout<<max(dp[n-1][0], dp[n-1][1]);
    return 0;
}
