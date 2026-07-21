#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18;

int main(){
    int n; cin >> n;
    ll ans = 0;
    vector<ll> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    vector<vector<ll> > dp(n+1, vector<ll>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = INF * -1;
    for(int i = 0; i < n; i++){
        dp[i+1][0] = max(dp[i][0] + lis[i], dp[i][1] - lis[i]);
        dp[i+1][1] = max(dp[i][0] - lis[i], dp[i][1] + lis[i]);
    }
    cout << dp[n][0] << endl;
}
