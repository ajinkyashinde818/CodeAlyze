#include <stdio.h>
typedef long long ll;

const ll mod = (ll)(1e9) + 7;

ll n, m;
ll a;
ll dp[100005];

ll solve(ll i);

int main()
{
    for (int i = 0; i < 100005; i++) {
        dp[i] = -1;
    }

    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a);
        dp[a] = 0;
    }

    printf("%lld\n", solve(0));

    return 0;
}

ll solve(ll i)
{
    if (dp[i] != -1) {
        return dp[i];
    }
    if (i == n) {
        return 1;
    }
    if (i > n) {
        return 0;
    }

    return dp[i] = (solve(i + 1) + solve(i + 2)) % mod;
}
