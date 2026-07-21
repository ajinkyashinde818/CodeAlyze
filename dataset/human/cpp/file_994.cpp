#include <bits/stdc++.h>

using namespace std;

int r,g,b,n;
int dp[3001];

void solve(){
    int i,j;
    string str;
    cin >> r >> g >> b >> n;
    for(i = 0;i <= n;i+=r) dp[i] = 1;
    for(i = n-1;i >= 0;i--){
        for(j = i+g;j <= n;j+=g){
            dp[j] += dp[i];
        }
    }
    for(i = n-1;i >= 0;i--){
        for(j = i+b;j <= n;j+=b){
            dp[j] += dp[i];
        }
    }
    long long ans = dp[n];
    cout << ans << endl;
}

int main(){
    solve();
}
