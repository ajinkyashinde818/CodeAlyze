#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    vector<ll> cum_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cum_sum[i + 1] = cum_sum[i] + a[i];
    }
    ll ans = INF;
    for (int i = 1; i < N; ++i) {
        ll abs_sum = abs((cum_sum[N] - cum_sum[i]) - cum_sum[i]);
        if (abs_sum < ans) ans = abs_sum;
    }
    cout << ans << endl;
}
