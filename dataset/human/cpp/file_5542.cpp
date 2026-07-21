#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 20, MAXM = 124, SZ = 26, L = 32;
const long long inf = 1e9 + 100, mod = 1e9 + 7;
mt19937 rnd;

void solve() {
    int n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r << '\n';
    else
        cout << r + 100 * (10 - n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
