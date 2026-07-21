#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n, p;
    cin >> n;
    vector<ll> a(n);
    ll minus_cnt = 0;
    ll abs_total= 0;
    ll min_abs = 1e9 + 1;
    for (ll i = 0; i < n; ++i) {
        cin >> p;
        if (p < 0) minus_cnt++;
        abs_total += abs(p);
        min_abs = min(min_abs, abs(p));
        a.at(i) = p;
    }
    ll ans = abs_total;
    if (minus_cnt % 2 == 1) ans -= min_abs * 2;
    cout << ans << endl;
}
