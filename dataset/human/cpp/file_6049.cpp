#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> x(n + 1, 0);
    vector<ll> v(n + 1, 0);
    ll vallsum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> v[i];
        vallsum += v[i];
    }

    ll vrsum = 0, vlsum = 0, dpr = 0, ans = 0;
    vector<ll> dpl(n + 1, 0);
    for (int i = n - 1; i >= 1; i--) {
        vlsum += v[i + 1];
        dpl[i] = max(dpl[i + 1], vlsum - (c - x[i + 1]) * 2);
    }

    for (int i = 1; i <= n; i++) {
        vlsum = vallsum - vrsum;
        vrsum += v[i];

        ans = max({ans, vrsum - x[i] + dpl[i], vlsum - (c - x[i]) + dpr});
        dpr = max(dpr, vrsum - x[i] * 2);
    }
    cout << ans << endl;
    return 0;
}
