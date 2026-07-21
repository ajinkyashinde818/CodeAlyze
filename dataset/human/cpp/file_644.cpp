#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int v[3] = {R,G,B};
    vector<vector<int>> dp(3,vector<int>(N+1));
    dp[0][0] = 1;
    for (int k=0;k<3;k++) {
        for (int i=0;i<=N;i++) {
            if (k>0) dp[k][i] = dp[k-1][i];
            if (i-v[k]>=0) dp[k][i] += dp[k][i-v[k]];
        }
    }
    cout << dp[2][N] << '\n';
    return 0;
}
