#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; long long c; cin >> n >> c;
    long long x[n], v[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> v[i];
    long long f1[n], f2[n], b1[n], b2[n];
    f1[0] = max(0LL, v[0] - x[0]);
    f2[0] = max(0LL, v[0] - 2*x[0]);
    long long cur = v[0];
    for (int i = 1; i < n; i++) {
        cur += v[i];
        f1[i] = max(f1[i-1], cur - x[i]);
        f2[i] = max(f2[i-1], cur - 2 * x[i]);
    }
    b1[n-1] = max(0LL, v[n-1] - c + x[n-1]);
    b2[n-1] = max(0LL, v[n-1] - 2 * (c - x[n-1]));
    cur = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        cur += v[i];
        b1[i] = max(b1[i+1], cur - (c - x[i]));
        b2[i] = max(b2[i+1], cur - 2 * (c - x[i]));
    }
    long long ans = max(f1[n-1], b1[0]);
    for (int i = 1; i < n; i++) ans = max({ans, f1[i-1] + b2[i], f2[i-1] + b1[i]});
    cout << ans << endl;
}
