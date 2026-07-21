#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &a_i : a) cin >> a_i;

    ll num_neg = 0, abs_sum = 0, idx_neg = -1, idx_pos = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            ++num_neg;
            if (idx_neg == -1 || a[i] < a[idx_neg])
                idx_neg = i;
        }
        else {
            if (idx_pos == -1 || a[i] < a[idx_pos])
                idx_pos = i;
        }
        abs_sum += abs(a[i]);
    }

    if (num_neg % 2 == 0) cout << abs_sum << endl;
    else if (num_neg == n) {
        for (int i = 0; i < n; ++i)
            if (a[idx_neg] < a[i]) idx_neg = i;
        cout << abs_sum + 2 * a[idx_neg] << endl;
    }
    else {
        int idx = idx_neg;
        for (int i = 0; i < n; ++i)
            if (a[i] < 0 && a[idx_neg] < a[i]) idx_neg = i;
        cout << max({abs_sum + 2 * a[idx_neg],
                    abs_sum - 2 * a[idx_pos],
                    abs_sum + 2 * a[idx]}) << endl;
    }

    return 0;
}
