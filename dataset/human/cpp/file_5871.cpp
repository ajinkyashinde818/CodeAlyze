#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long c;
    cin >> c;
    long long x[n], v[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> v[i];
    long long cw[n], cwd[n], acw[n], acwd[n];
    cw[0] = v[0] - x[0];
    cwd[0] = v[0] - 2 * x[0];
    acw[n - 1] = v[n - 1] - (c - x[n - 1]);
    acwd[n - 1] = v[n - 1] - 2 * (c - x[n - 1]);
    for (int i = 1; i < n; i++) {
        cw[i] = cw[i - 1] + v[i] - (x[i] - x[i - 1]);
        cwd[i] = cwd[i - 1] + v[i] - 2 * (x[i] - x[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        acw[i] = acw[i + 1] + v[i] - (x[i + 1] - x[i]);
        acwd[i] = acwd[i + 1] + v[i] - 2 * (x[i + 1] - x[i]);
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, cw[i]);
        res = max(res, acw[i]);
    }
    for (int i = 1; i < n; i++) {
        cw[i] = max(cw[i], cw[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        acw[i] = max(acw[i], acw[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) {
        res = max(res, cwd[i] + acw[i + 1]);
    }
    for (int i = n - 1; i > 0; i--) {
        res = max(res, acwd[i] + cw[i - 1]);
    }
    cout << res << "\n";
    return 0;
}
