#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100010];
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zero = true;
    }
    if (zero) {
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += abs(a[i]);
        cout << ans;
        return 0;
    }
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] < 0) {
            a[i] *= -1;
            a[i + 1] *= -1;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    long long cur = ans;
    for (int i = n - 1; i >= 1; i--) {
        a[i] *= -1;
        a[i - 1] *= -1;
        cur += 2ll * (a[i] + a[i - 1]);
        ans = max(ans, cur);
    }
    cout << ans;
}
