#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    ll sum = 0;
    vector<ll> a(n), b(n-1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    b[0] = a[0];
    for (int i = 1; i < n-1; ++i) {
        b[i] = a[i] + b[i-1];
    }

    ll res = 1e15;
    for (int i = 0; i < n-1; ++i) {
        if (res > abs(sum - 2*b[i])) {
            res = abs(sum - 2*b[i]);
        }
    }

    cout << res << endl;
    return 0;
}
