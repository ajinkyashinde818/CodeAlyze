#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll c;
vector<pair<ll, ll>> nums;
int main() {
    cin >> n >> c;
    nums.resize(n+1);
    vector<ll> g(n+1);
    nums[0] = {0, 0};
    g[0] = 0;
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i].first >> nums[i].second;
        cur += nums[i].second;
        g[i] = max(g[i-1], cur - nums[i].first);
    }
    vector<ll> rg(n+1);
    rg[0] = 0;
    cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += nums[n+1-i].second;
        rg[i] = max(rg[i-1], cur - c + nums[n+1-i].first);
    }
    ll ans = max(rg[n], g[n]);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, rg[n-i] + g[i]-nums[i].first);
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, g[n-i] + rg[i]- c + nums[n+1-i].first);
    }
    cout << ans << "\n";
    return 0;
}
