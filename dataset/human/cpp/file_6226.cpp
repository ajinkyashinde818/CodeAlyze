#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2e5 + 5;
typedef long long ll;

int i, n;
ll D, ans = 0, go[Nmax], val[Nmax], X[Nmax], sum[Nmax], sum2[Nmax];

int main()
{
//    freopen("input", "r", stdin);
  //  freopen("output", "w", stdout);
    cin.sync_with_stdio(false);

    cin >> n >> D;
    for(i=1; i<=n; ++i) cin >> X[i] >> val[i];

    for(i=1; i<=n; ++i) sum[i] = sum[i-1] + val[i];
    for(i=n; i; --i) sum2[i] = sum2[i+1] + val[i];

    for(i=n; i; --i) go[i] = max(go[i+1], sum2[i] - (D - X[i]));

    for(i=1; i<=n; ++i)
        ans = max(ans, sum[i] - X[i] + max(0LL, go[i+1] - X[i]));

    ///
    for(i=1; i<=n; ++i) X[i] = D - X[i];
    reverse(X+1, X+n+1);
    reverse(val+1, val+n+1);


    for(i=1; i<=n; ++i) sum[i] = sum[i-1] + val[i];
    for(i=n; i; --i) sum2[i] = sum2[i+1] + val[i];

    for(i=n; i; --i) go[i] = max(go[i+1], sum2[i] - (D - X[i]));

    for(i=1; i<=n; ++i)
        ans = max(ans, sum[i] - X[i] + max(0LL, go[i+1] - X[i]));
    ///

    cout << ans << '\n';
    return 0;
}
