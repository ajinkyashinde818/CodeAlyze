#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

ll solve(int n, ll c, vector <ll> x, vector <ll> v)
{
    vector <ll> suf(n + 1);
    ll cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cur += v[i];
        suf[i] = max(suf[i + 1], cur - (c - x[i]));
    }
    ll ans = suf[0];
    cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += v[i];
        ans = max(ans, cur - x[i]);
        ans = max(ans, cur - 2 * x[i] + suf[i + 1]);
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll c;
    cin >> c;
    vector <ll> x(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> v[i];
    }
    ll ans = solve(n, c, x, v);
    for (int i = 0; i < n; i++)
    {
        x[i] = c - x[i];
    }
    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
    ans = max(ans, solve(n, c, x, v));
    cout << ans << '\n';
}
