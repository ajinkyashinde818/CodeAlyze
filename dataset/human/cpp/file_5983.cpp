#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> x(n+2);
    vector<ll> v(n+2);
    x[0] = v[0] = v[n+1] = 0;
    x[n+1] = c;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> v[i];
    }
    vector<ll> lback(n+1);
    vector<ll> rback(n+1);
    vector<ll> lst(n+1);
    vector<ll> rst(n+1);
    vector<ll> lvsum(n+1);
    vector<ll> rvsum(n+1);

    lback[0] = rback[0] = lst[0] = rst[0] = lvsum[0] = rvsum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        lvsum[i] = lvsum[i-1] + v[i];
        lback[i] = max(lback[i-1], lvsum[i] - 2 * x[i]);
        lst[i] = max(lst[i-1], lvsum[i] - x[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        rvsum[i] = rvsum[i-1] + v[n+1-i];
        rback[i] = max(rback[i-1], rvsum[i] - 2 * (c-x[n+1-i]));
        rst[i] = max(rst[i-1], rvsum[i] - (c-x[n+1-i]));
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++)
    {
        ans = max(ans, lback[i] + rst[n-i]);
        ans = max(ans, rback[i] + lst[n-i]);
    }
    cout << ans << endl;
}
