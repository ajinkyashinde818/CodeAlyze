#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    ll n; cin >> n;
    vector<ll> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    vector<ll> abs_A(n);
    int negative_cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] <= 0) negative_cnt++;
        abs_A[i] = abs(A[i]);
    }
    ll m = INF;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        m = min(m, abs_A[i]);
        ans += abs_A[i];
    }
    if(negative_cnt % 2 == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << ans - 2LL * m << endl;
    }
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
