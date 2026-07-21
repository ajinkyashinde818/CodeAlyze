#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 200010, M = 2 * N;
const double eps = 1e-6;

int n, a[N];
LL l[N], r[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) l[i] = l[i - 1] + a[i];
    for(int i = n; i >= 1; i--) r[i] = r[i + 1] + a[i];

    LL res = 1e18;
    for(int i = 1; i <= n; i++)
    {
        if(i > 1) res = min(res, abs(l[i] - a[i] - r[i]));
        if(i < n) res = min(res, abs(l[i] - r[i] + a[i]));
    }

    cout << res << endl;
    return 0;
}
