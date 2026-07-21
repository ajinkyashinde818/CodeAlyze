#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll n, m;
ll a[30];

using ll = long long;
ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    string s;
    cin >> n >> s;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        a[s[i] - 'a']++;
        ans += ans * mod_pow(a[s[i] - 'a'], mod - 2, mod);
        ans %= mod;
    }
    ans--;
    cout << ans % mod << endl;
}
