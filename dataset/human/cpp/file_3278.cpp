#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[100000][4],a[100000];

ll solve(){
    dp[0][0] = -a[0];
    dp[0][1] = -1e15;
    dp[0][2] = -1e15;
    dp[0][3] = a[0];

    for(int i = 0;i < n-1;i ++){
        dp[i+1][0] = max(dp[i][2],dp[i][3])-a[i+1];
        dp[i+1][1] = max(dp[i][0],dp[i][1])+a[i+1];
        dp[i+1][2] = max(dp[i][0],dp[i][1])-a[i+1];
        dp[i+1][3] = max(dp[i][2],dp[i][3])+a[i+1];
    }
    return max(dp[n-1][2],dp[n-1][3]);
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    cout << solve() << endl;
    return 0;
}
