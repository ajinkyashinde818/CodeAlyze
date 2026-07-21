#include "bits/stdc++.h"
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector< ll> v(n), a(n), b(n);
    for (auto& e : v) cin >> e;
    a[0] = v[0];
    b[n - 1] = v[n - 1];

    for (int i = 1; i < n; ++i) a[i] = a[i - 1] + v[i];
    for (int i = n - 2; i >= 0; i--) b[i] = b[i + 1] + v[i];
    ll res = 1e18;
    for (int i = 0; i + 1 < n; ++i) {
        res = min(res, llabs(a[i] - b[i + 1]));
    }
    cout << res << endl;
}
