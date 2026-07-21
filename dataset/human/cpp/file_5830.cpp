#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int maxn = 1e5 + 10;

int n;
lli c;
lli sumval;
lli x[maxn], val[maxn];
lli costl[maxn], costlret[maxn];
lli ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    x[n + 1] = c;

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> val[i];
        sumval += val[i];
    }

    lli maxl = 0, maxlret = 0;

    for(int i = n; i >= 0; i--) {
        ans = max(ans, sumval - x[i] + maxlret);
        ans = max(ans, sumval - 2 * x[i] + maxl);
        costl[i] = costl[i + 1] - (x[i + 1] - x[i]) + val[i];
        costlret[i] = costlret[i + 1] - 2 * (x[i + 1] - x[i]) + val[i];
        maxl = max(maxl, costl[i]);
        maxlret = max(maxlret, costlret[i]);
        sumval -= val[i];
    }

    cout << ans << endl;

    return 0;
}
