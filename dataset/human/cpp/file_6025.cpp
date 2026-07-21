#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll n, C;
ll a[N], b[N], x[N], v[N], sum[N];

int main() {
    scanf("%lld%lld", &n, &C);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &x[i], &v[i]);
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + v[i] - (x[i] - x[i - 1]);
    x[n + 1] = C;
    for (int i = n; i >= 1; i--)
        b[i] = b[i + 1] + v[i] - (x[i + 1] - x[i]);
    for (int i = 2; i <= n; i++)
        a[i] = max(a[i - 1], a[i]);
    for (int i = n - 1; i >= 1; i--)
        b[i] = max(b[i + 1], b[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] + b[i + 1] - x[i]);
        ans = max(ans, b[i] + a[i - 1] - (C - x[i]));
        ans = max(ans, a[i]);
        ans = max(ans, b[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
