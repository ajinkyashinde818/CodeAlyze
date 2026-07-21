#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <functional>
#include <cmath>

using LL = long long;

const int maxN = (int)1e5 + 10;

int N;
LL C;
LL V[maxN]; LL VPref[maxN];
LL VC[maxN];LL VCPref[maxN];
LL X[maxN]; LL XC[maxN];

LL maxPref[maxN];
LL maxPrefC[maxN];

void input()
{
    scanf("%d%lld", &N, &C);
    for (int i = 1; i <= N; i++)
        scanf("%lld%lld", X + i, V + i);

    for (int i = 1; i <= N; i++)
    {
        XC[i] = C - X[N + 1 - i];
        VC[i] = V[N + 1 - i];
    }
    std::partial_sum(V, V + N + 1, VPref);
    std::partial_sum(VC, VC + N + 1, VCPref);
}

LL solve()
{
    LL ans = 0;
    for (int i = 1; i <= N; i++)
        maxPref[i] = std::max(maxPref[i - 1], VPref[i] - X[i]);

    for (int i = 1; i <= N; i++)
        maxPrefC[i] = std::max(maxPrefC[i - 1], VCPref[i] - XC[i]);

    ans = std::max(maxPref[N], maxPrefC[N]);

    for (int i = 1; i < N; i++)
    {
        ans = std::max(ans, VPref[i] - 2 * X[i] + maxPrefC[N - i]);
        ans = std::max(ans, VCPref[i] - 2 * XC[i] + maxPref[N - i]);
    }

    return ans;
}

int main()
{
    input();
    printf("%lld", solve());
    return 0;
}
