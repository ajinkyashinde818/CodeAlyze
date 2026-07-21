#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 3e5 + 10;
int n;
LL C, x[N];
int v[N];
LL sb[N], db[N];

int main() {
    cin >> n >> C;
    n++;
    for (int i = 1; i < n; ++i) {
        scanf("%lld%d", &x[i], &v[i]);
        x[n + i] = x[i];
        v[n + i] = v[i];
    }
    for (int i = 1; i <= n; ++i) {
        sb[n + i] = v[n + i]; sb[n - i] = v[n - i];
        db[n + i] = v[n + i]; db[n - i] = v[n - i];
        sb[n + i] += sb[n + i - 1] - (x[i] - x[i - 1] + C) % C;
        sb[n - i] += sb[n - i + 1] - (x[n - i + 1] - x[n - i] + C) % C;
        db[n + i] += db[n + i - 1] - 2 * ((x[i] - x[i - 1] + C) % C);
        db[n - i] += db[n - i + 1] - 2 * ((x[n - i + 1] - x[n - i] + C) % C);
    }
    for (int i = 1; i <= n; ++i) {
        sb[n + i] = max(sb[n + i], sb[n + i - 1]);
        sb[n - i] = max(sb[n - i], sb[n - i + 1]);
        db[n + i] = max(db[n + i], db[n + i - 1]);
        db[n - i] = max(db[n - i], db[n - i + 1]);
    }
    // for (int i = 0; i <= 2 * n; ++i)
    //     printf("%lld ", sb[i]);
    // puts("");

    // for (int i = 0; i <= 2 * n; ++i)
    //     printf("%lld ", db[i]);
    // puts("");

    LL ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, db[n + i] + sb[i + 1]);
    for (int i = 0; i < n; ++i)
        ans = max(ans, db[i + 1] + sb[n + i]);
    cout << ans << endl;
}
