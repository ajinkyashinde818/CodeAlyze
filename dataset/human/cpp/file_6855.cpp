#include <bits/stdc++.h>
const int N = 2e5 + 7;
using namespace std;
int a[N], b[N];
auto main() -> int {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(b + 1, b + 1 + n, greater<int>());
    int l = 1 << 30, r = -1, c = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == b[i]) {
            l = min(l, i);
            r = max(r, i);
            c = a[i];
        }
    }
    if (c == -1) {
        cout << "Yes\n";
        for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i==n];
        return 0;
    }
    vector<int> opts;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != c && b[i] != c) {
            opts.emplace_back(i);
        }
    }
    for (int i = l; i <= r; ++i) {
        if (opts.empty()) {
            cout << "No\n";
            return 0;
        }
        auto nxt = opts.back(); opts.pop_back();
        swap(b[i], b[nxt]);
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i==n];


    return 0;
}
