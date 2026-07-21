#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector < int > a(n), c;
    int cnt_neg = 0;
    for (int &x: a) {
        cin >> x;
        cnt_neg ^= (x < 0);
        c.push_back(abs(x));
    }
    sort(c.begin(), c.end());
    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
        ans += c[i];
    for (int i = 0; i < cnt_neg; ++i)
        ans -= 2 * c[i];
    cout << ans << '\n';
}
