#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll INF = 1LL << 62;

ll N, C;
vector<p> sushi;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> C;

    for (ll i = 0; i < N; i++) {
        ll x, v;
        cin >> x >> v;
        sushi.push_back(p(x, v));
    }
    
    sushi.push_back(p(0, 0));
    sort(sushi.begin(), sushi.end());
    sushi.push_back(p(0, 0));

    vector<ll> cwsum(N + 2, 0), ccwsum(N + 2, 0);
    cwsum[0] = sushi.front().second;
    for (ll i = 1; i <= N; i++) {
        cwsum[i] = cwsum[i - 1] + sushi[i].second;
    }
    ccwsum[N + 1] = sushi.back().second;
    for (ll i = N; i >= 1; i--) {
        ccwsum[i] = ccwsum[i + 1] + sushi[i].second;
    }

    vector<ll> f(N + 1, 0);
    vector<ll> f2(N + 1, 0);
    for (ll i = 0; i <= N; i++) {
        f[i] = cwsum[i] - sushi[i].first;
        f2[i] = cwsum[i] - 2 * sushi[i].first;
    }
    vector<ll> g(N + 1, 0);
    vector<ll> g2(N + 1, 0);
    for (ll i = 1; i <= N; i++) {
        g[i] = max(g[i - 1], f[i]);
        g2[i] = max(g2[i - 1], f2[i]);
    }

    ll ans = 0;
    for (ll i = 1; i <= N + 1; i++) {
        ll d = C - sushi[i].first;
        if (d == C) {
            d = 0;
        }

        ans = max(ans, max(g[i - 1] + ccwsum[i] - 2 * d, g2[i - 1] + ccwsum[i] - d));
    }

    cout << ans << endl;
    return 0;
}
