#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 r, g, b, n;
    cin >> r >> g >> b >> n;

    i64 ans = 0;
    for (i64 i = 0; r * i <= n; i++) {
        for (i64 j = 0; r * i + g * j <= n; j++) {
            if ((n - r * i - g * j) % b == 0) ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
