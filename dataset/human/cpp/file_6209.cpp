#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> a(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> v[i];
    }
    vector<ll> val(n);
    ll sum = 0;
    multiset<ll, greater<ll>> kek;
    for (int i = n - 1; i >= 0; --i) {
        sum += v[i];
        val[i] = sum - (c - a[i]);
        kek.insert(val[i]);
    }
    ll ans = 0;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        kek.erase(kek.find(val[i]));
        sum += v[i];
        ll tmp = sum - a[i];
        if (i != n - 1 && *kek.begin() - a[i] > 0) {
            tmp += *kek.begin() - a[i];
        }
        ans = max(ans, tmp);
    }
    reverse(a.begin(), a.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        a[i] = c - a[i];
    }
    sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += v[i];
        val[i] = sum - (c - a[i]);
        kek.insert(val[i]);
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
        kek.erase(kek.find(val[i]));
        sum += v[i];
        ll tmp = sum - a[i];
        if (i != n - 1 && *kek.begin() - a[i] > 0) {
            tmp += *kek.begin() - a[i];
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
