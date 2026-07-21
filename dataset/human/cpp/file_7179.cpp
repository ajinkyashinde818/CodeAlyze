#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ara[200000+23];
ll ara2[200000+23];
int main()
{
    ll k, l, m, n, ans = 1000000000000000;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &ara[i]);
    }
    for(ll i = 1; i <= n; i++){
        ara2[i] = ara[i] + ara2[i-1];
    }
    for(ll i = 1; i < n; i++){
        k = ara2[i];
        l = ara2[n] - ara2[i];
        m = abs(k - l);
        ans = min(m, ans);
    }
    printf("%lld", ans);

    return 0;
}
