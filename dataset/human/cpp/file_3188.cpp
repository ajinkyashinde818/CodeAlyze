#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;

ll n, a[100005], rj;
ll dp[100005][2];

ll f(int p, int pr)
{
    if (p == n - 1)
        return a[n - 1] * (pr ? -1 : 1);
    if (dp[p][pr] != -1)
        return dp[p][pr];
    return dp[p][pr] = max(f(p + 1, 0) + a[p] * (pr ? -1 : 1),
                           f(p + 1, 1) - a[p] * (pr ? -1 : 1));
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << f(0, 0) << endl;
}
