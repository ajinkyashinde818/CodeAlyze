#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll min_v = 1e9 * 2 * n;
    for (ll i = 0, x = 0; i < n - 1; ++i) {
        x += a[i];
        if (abs(sum - 2 * x) < min_v) min_v = abs(sum - 2 * x);
    }

    cout << min_v << endl;

    return 0;
}
