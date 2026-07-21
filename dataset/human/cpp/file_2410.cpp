#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

// bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
//     return arg1.first > arg2.first;
// }

int main(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a.at(i);
    }

    ll dp[n+1][2];
    dp[0][0] = 0;
    dp[0][1] = -1e18;

    for(int i=0;i<n;i++) {
        dp[i+1][0] = max(dp[i][0]+a.at(i), dp[i][1]-a.at(i));
        dp[i+1][1] = max(dp[i][0]-a.at(i), dp[i][1]+a.at(i));
    }

    cout << dp[n][0] << endl;

    return 0;
}
