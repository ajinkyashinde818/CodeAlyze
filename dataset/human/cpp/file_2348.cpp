#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld N;
vector<lld> v;
lld dp[555555][2];

lld solve(lld id, lld taken)
{
    if(id > N) {
        return 0;
    }
    if(id == N - 1) {
        return (taken == 0) ? v[id] : (-v[id]);
    }
    if(dp[id][taken] != -1) {
        return dp[id][taken];
    }

    lld ans = 0;
    if(taken == 0) {
        lld temp = v[id] + solve(id + 1, 0);
        ans += max(temp, -v[id] + solve(id + 1, 1));
    } else {
        lld temp = -v[id] + solve(id + 1, 0);
        ans += max(temp, v[id] + solve(id + 1, 1));
    }
    return dp[id][taken] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    v.resize(N);
    for(lld i = 0; i < N; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
}
