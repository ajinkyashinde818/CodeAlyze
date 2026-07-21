#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) ++cnt;
        if (a[i] == 0) ++zero;
    }
    if (cnt % 2 == 1 && zero == 0) {
        long long ans = 0;
        int tmp = 1e9;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 0) ans = ans + a[i];
            else ans = ans - a[i];
            tmp = min(tmp, abs(a[i]));
        }
        cout << ans - tmp - tmp;
    } else {
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if(a[i] >= 0) ans = ans + a[i];
            else ans = ans - a[i];
        }
        cout << ans;
    }
    return 0;
}
