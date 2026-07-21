#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll N, C;
    cin >> N >> C;
    vector<ll> x(N), v(N), rev_x(N), rev_v(N);
    for(int i = 0; i < N; ++i) {
        cin >> x[i] >> v[i];
        rev_x[N - i - 1] = C - x[i];
        rev_v[N - i - 1] = v[i];
    }

    vector<ll> dp1(N + 1), rev_dp1(N + 1);
    vector<ll> dp2(N + 1), rev_dp2(N + 1);
    dp1[0] = rev_dp1[0] = 0;
    dp2[0] = rev_dp2[0] = 0;
    for(int i = 0; i < N; ++i) {
        dp1[i + 1] = (i != 0 ? dp1[i] + x[i - 1] : 0) + v[i] - x[i];
        dp2[i + 1] = (i != 0 ? dp2[i] + 2 * x[i - 1] : 0) + v[i] - 2 * x[i];
        rev_dp1[i + 1] = (i != 0 ? rev_dp1[i] + rev_x[i - 1] : 0) + rev_v[i] - rev_x[i];
        rev_dp2[i + 1] = (i != 0 ? rev_dp2[i] + 2 * rev_x[i - 1] : 0) + rev_v[i] - 2 * rev_x[i];
    }
    ll ans = 0;
    for(int i = 0; i < N; ++i) {
        dp1[i + 1] = max(dp1[i + 1], dp1[i]);
        dp2[i + 1] = max(dp2[i + 1], dp2[i]);
        ans = max({ans, rev_dp1[i + 1], rev_dp2[i + 1]});
    }
    ans = max(ans, dp1[N]);

    for(int i = 0; i < N; ++i) {
        ll t1 = rev_dp1[i], t2 = rev_dp2[i];
        const int rev_pos = N - i;
        t1 += max(dp2[rev_pos], 0LL);
        t2 += max(dp1[rev_pos], 0LL);
        ans = max({ans, t1, t2});
    }
    cout << ans << endl;
}
